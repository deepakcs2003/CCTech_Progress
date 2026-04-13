// Canvas2D.tsx
// Handles 2D shape drawing and control-point editing — mirrors GLCanvas 2D logic.

import React, { useRef, useEffect, useCallback } from "react";
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
  shape,
  mode,
  shapeType,
  onShapeCreated,
  onShapeUpdated,
  createShape,
}) => {
  const canvasRef = useRef<HTMLCanvasElement>(null);
  const drawingRef  = useRef(false);
  const startRef    = useRef<Point2D>({ x: 0, y: 0 });
  const selectedRef = useRef(-1);
  const activeShape = useRef<Shape | null>(null);

  // keep activeShape in sync with prop
  useEffect(() => { activeShape.current = shape; }, [shape]);

  // ── render ──────────────────────────────────────────────────────────────────
  const render = useCallback(() => {
    const canvas = canvasRef.current;
    if (!canvas) return;
    const ctx = canvas.getContext("2d")!;
    ctx.clearRect(0, 0, canvas.width, canvas.height);

    const s = activeShape.current;
    if (!s) return;

    // draw 2D outline
    const verts = s.getVertices();
    ctx.strokeStyle = "#ffffff";
    ctx.lineWidth = 1.5;
    ctx.beginPath();
    for (let i = 0; i < verts.length; i += 4) {
      ctx.moveTo(verts[i], verts[i + 1]);
      ctx.lineTo(verts[i + 2], verts[i + 3]);
    }
    ctx.stroke();

    // draw control points in edit mode
    if (mode === "edit") {
      const pts = s.getControlPoints();
      for (let i = 0; i < pts.length; i++) {
        const { x, y } = pts[i];
        const isSelected = i === selectedRef.current;
        ctx.strokeStyle = isSelected ? "#00ff88" : "#00cc66";
        ctx.lineWidth = 1.5;
        const d = 6;
        ctx.beginPath();
        ctx.moveTo(x - d, y); ctx.lineTo(x + d, y);
        ctx.moveTo(x, y - d); ctx.lineTo(x, y + d);
        ctx.stroke();
        ctx.fillStyle = isSelected ? "#00ff88" : "#00cc66";
        ctx.beginPath();
        ctx.arc(x, y, 3, 0, Math.PI * 2);
        ctx.fill();
      }
    }
  }, [mode]);

  useEffect(() => { render(); }, [shape, mode, render]);

  // ── resize observer ─────────────────────────────────────────────────────────
  useEffect(() => {
    const canvas = canvasRef.current;
    if (!canvas) return;
    const ro = new ResizeObserver(() => {
      canvas.width  = canvas.offsetWidth;
      canvas.height = canvas.offsetHeight;
      render();
    });
    ro.observe(canvas);
    return () => ro.disconnect();
  }, [render]);

  // ── mouse handlers ───────────────────────────────────────────────────────────
  const getPos = (e: React.MouseEvent): Point2D => {
    const r = canvasRef.current!.getBoundingClientRect();
    return { x: e.clientX - r.left, y: e.clientY - r.top };
  };

  const onMouseDown = (e: React.MouseEvent) => {
    const pos = getPos(e);

    if (mode === "draw" && shapeType !== "none") {
      startRef.current = pos;
      const s = createShape(shapeType, pos, pos);
      if (s) {
        activeShape.current = s;
        onShapeCreated(s);
        drawingRef.current = true;
      }
    } else if (mode === "edit" && activeShape.current) {
      selectedRef.current = activeShape.current.nearestControlPoint(pos, TOL);
      render();
    }
  };

  const onMouseMove = (e: React.MouseEvent) => {
    const pos = getPos(e);

    if (mode === "draw" && drawingRef.current && activeShape.current) {
      activeShape.current.setEnd(pos);
      onShapeUpdated();
      render();
    } else if (mode === "edit" && selectedRef.current !== -1 && activeShape.current) {
      activeShape.current.moveControlPoint(selectedRef.current, pos);
      onShapeUpdated();
      render();
    }
  };

  const onMouseUp = () => {
    if (drawingRef.current) {
      drawingRef.current = false;
    }
    selectedRef.current = -1;
    render();
  };

  return (
    <canvas
      ref={canvasRef}
      className="w-full h-full cursor-crosshair"
      onMouseDown={onMouseDown}
      onMouseMove={onMouseMove}
      onMouseUp={onMouseUp}
    />
  );
};
