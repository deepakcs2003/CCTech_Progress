
import { useState, useCallback, useRef } from "react";
import { Toolbar }   from "./components/Toolbar";
import { Canvas2D }  from "./components/Canvas2D";
import { Canvas3D }  from "./components/Canvas3D";
// import { StatusBar } from "./components/StatusBar";
import { Shape }     from "./shapes/Shape";
import { Rectangle } from "./shapes/Rectangle";
import { Square }    from "./shapes/Square";
import { Circle }    from "./shapes/Circle";
import { STL }       from "./utils/STL";
import { DataClass } from "./utils/DataClass";

type ShapeType = "rect" | "square" | "circle" | "none";
type Mode      = "none" | "draw" | "edit";

// factory function to create shapes based on type and start/end points
function createShape(type: string, s: { x: number; y: number }, e: { x: number; y: number }): Shape | null {
  if (type === "rect")   
    return new Rectangle(s, e);
  if (type === "square") 
    return new Square(s, e);
  if (type === "circle")
     return new Circle(s, e);
  return null;
}

export default function App() {
  const [shape,setShape]       = useState<Shape | null>(null);
  const [shapeType,setShapeType]   = useState<ShapeType>("none");
  const [mode,setMode]        = useState<Mode>("none");
  const [show3D,setShow3D]      = useState(false);
  const [meshData,setMeshData]    = useState<number[]>([]);
  const [tick,setTick]        = useState(0);   // force 2D re-render
  const dataClass = useRef(new DataClass());

  console.log(tick);
  // shape created by Canvas2D during drawing
  const handleShapeCreated = useCallback((s: Shape) => {
    setShape(s);
    setMode("draw");
  }, []);

  // shape updated (setEnd / moveControlPoint called inside Canvas2D)
  const handleShapeUpdated = useCallback(() => {
    setTick(t => t + 1);
  }, []);

  // toolbar handlers
  const handleShapeSelect = (t: ShapeType) => {
    setShapeType(t);
    setMode("draw");
    setShow3D(false);
    setShape(null);
    setMeshData([]);
  };

  const handleModeChange = (m: Mode) => {
    setMode(m);
    setShow3D(false);
  };

  const handleToggle3D = () => {
    if (!shape && meshData.length === 0) return;
    const next = !show3D;
    setShow3D(next);
    if (next && shape) {
      const mesh = shape.getMesh3D();
      dataClass.current.storeData(mesh);
      setMeshData(mesh);
    }
  };

  const handleClear = () => {
    setShape(null);
    setShapeType("none");
    setMode("none");
    setShow3D(false);
    setMeshData([]);
  };

  const handleSaveSTL = () => {
    const data = meshData.length > 0 ? meshData : shape?.getMesh3D() ?? [];
    if (data.length) STL.saveSTL(data);
  };

  const handleLoadSTL = async () => {
    const data = await STL.loadSTL();
    if (data.length === 0) return;
    setShape(null);
    dataClass.current.storeData(data);
    setMeshData(data);
    setShow3D(true);
    setMode("none");
  };

  const hasShape = !!shape || meshData.length > 0;

  return (
    <div className="flex flex-col h-screen w-screen bg-zinc-950 overflow-hidden">
      <Toolbar
        activeShape={shapeType}
        mode={mode}
        show3D={show3D}
        hasShape={hasShape}
        onShapeSelect={handleShapeSelect}
        onModeChange={handleModeChange}
        onToggle3D={handleToggle3D}
        onClear={handleClear}
        onSaveSTL={handleSaveSTL}
        onLoadSTL={handleLoadSTL}
      />

      {/* Canvas area */}
      <main className="flex-1 relative overflow-hidden">
        {/* 2D canvas — always mounted, hidden when 3D */}
        <div className={`absolute inset-0 transition-opacity duration-200 ${show3D ? "opacity-0 pointer-events-none" : "opacity-100"}`}>
          <Canvas2D
            shape={shape}
            mode={mode}
            shapeType={shapeType}
            onShapeCreated={handleShapeCreated}
            onShapeUpdated={handleShapeUpdated}
            createShape={createShape}
          />
          {/* Empty state hint */}
          {!shape && !show3D && (
            <div className="absolute inset-0 flex items-center justify-center pointer-events-none">
              <p className="text-zinc-600 font-mono text-sm select-none">
                Select a shape from the toolbar and draw on the canvas
              </p>
            </div>
          )}
        </div>

        {/* 3D canvas — only mounted when needed */}
        {show3D && (
          <div className="absolute inset-0">
            <Canvas3D meshData={meshData} />
          </div>
        )}
      </main>

      {/* <StatusBar
        shapeName={shape?.name() ?? (meshData.length > 0 ? "STL Model" : null)}
        mode={mode}
        show3D={show3D}
        vertCount={meshData.length}
      /> */}
    </div>
  );
}
