import React, { useRef, useEffect } from "react";
import { Shape, type Point2D } from "../shapes/Shape";

interface Props {
  shape: Shape | null;  
  mode: "none" | "draw" | "edit";
  shapeType: "rect" | "square" | "circle" | "none";
  onShapeCreated: (shape: Shape) => void;
  onShapeUpdated: () => void;
  createShape: (type: string, start: Point2D, end: Point2D) => Shape | null;
}

const TOL = 12;

export const Canvas2D: React.FC<Props> = ({
  shape, mode, shapeType, onShapeCreated, onShapeUpdated, createShape
}) => {
  const canvasRef = useRef<HTMLCanvasElement>(null);
  const drawing = useRef(false);
  const selected = useRef(-1);
  const active = useRef<Shape | null>(null);


  // DRAW FUNCTION (called on mouse events and resize)
  const draw = () => {

    const canvas = canvasRef.current;

    if (!canvas) return;

   //drawing tool (pen) 
    const ctx = canvas.getContext("2d")!;

    //FORCE CLEAR  (remove previous drawings)
    ctx.clearRect(0, 0, canvas.width, canvas.height);

    // if no shape, just return (avoid drawing handles etc.)
    if (!active.current) return;


    //[x1, y1, x2, y2, x3, y3...] 
    const v = active.current.getVertices();

    ctx.beginPath();
    for (let i = 0; i < v.length; i += 4) {
      ctx.moveTo(v[i], v[i + 1]);
      ctx.lineTo(v[i + 2], v[i + 3]);
    }
    ctx.strokeStyle = "#fff";
    ctx.lineWidth = 2;
    ctx.stroke();

    if (mode === "edit") {
      active.current.getControlPoints().forEach((p, i) => {
        ctx.strokeStyle = i === selected.current ? "#0f8" : "#0c6";

        ctx.beginPath();
        ctx.moveTo(p.x - 6, p.y);
        ctx.lineTo(p.x + 6, p.y);
        ctx.moveTo(p.x, p.y - 6);
        ctx.lineTo(p.x, p.y + 6);
        // ctx.strokeStyle = "#e31426";
        ctx.stroke();
      });
    }
  };

  //  whenever shape changes update internals reference  of shape
  useEffect(() => {
    active.current = shape;
  }, [shape]);

  // resize canvas properly
  useEffect(() => {
    const canvas = canvasRef.current!;
    const resize = () => {
      canvas.width = canvas.offsetWidth;
      canvas.height = canvas.offsetHeight;
      draw(); // redraw after resize
    };
    resize();
    const ro = new ResizeObserver(resize);
    ro.observe(canvas);
    return () => ro.disconnect();
  }, []);

  //convert mouse to canvas coordinates
  const getPos = (e: React.MouseEvent): Point2D => {
    const r = canvasRef.current!.getBoundingClientRect();
    return { x: e.clientX - r.left, y: e.clientY - r.top };
  };

  

  //  redraw on state change (SEPARATE effect)
  useEffect(() => {
    draw();
  }, [shape, mode]);

  const onDown = (e: React.MouseEvent) => {
    const pos = getPos(e);

    if (mode === "draw" && shapeType !== "none") {
      const s = createShape(shapeType, pos, pos);
      if (s) {
        active.current = s;
        onShapeCreated(s);
        drawing.current = true;
      }
    } else if (mode === "edit" && active.current) {
      selected.current = active.current.nearestControlPoint(pos, TOL);
      draw();
    }
  };

  const onMove = (e: React.MouseEvent) => {
    const pos = getPos(e);

    if (mode === "draw" && drawing.current && active.current) {
      active.current.setEnd(pos);
      onShapeUpdated();
      draw();
    }

    if (mode === "edit" && selected.current !== -1 && active.current) {
      active.current.moveControlPoint(selected.current, pos);
      onShapeUpdated();
      draw();
    }
  };

  const onUp = () => {
    drawing.current = false;
    selected.current = -1;
    draw();
  };

  return (
    <canvas
      ref={canvasRef}
      className="w-full h-full cursor-crosshair"
      onMouseDown={onDown}
      onMouseMove={onMove}
      onMouseUp={onUp}
    />
  );
};