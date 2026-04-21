// Toolbar.tsx — Top menu bar (Draw, Options) — mirrors Shape3D::buildMenus()

import React from "react";

type ShapeType = "rect" | "square" | "circle" | "none";
type Mode      = "none" | "draw" | "edit";

interface Props {
  activeShape: ShapeType;
  mode:        Mode;
  show3D:      boolean;
  hasShape:    boolean;
  onShapeSelect: (s: ShapeType) => void;
  onModeChange:  (m: Mode) => void;
  onToggle3D:    () => void;
  onClear:       () => void;
  onSaveSTL:     () => void;
  onLoadSTL:     () => void;
}

const Btn: React.FC<{
  active?: boolean;
  onClick: () => void;
  children: React.ReactNode;
  disabled?: boolean;
}> = ({ active, onClick, children, disabled }) => (
  <button
    onClick={onClick}
    disabled={disabled}
    className={`
      px-3 py-1.5 text-xs font-mono rounded transition-all duration-150 border
      ${active
        ? "bg-purple-600 border-purple-400 text-white shadow-lg shadow-purple-900/40"
        : "bg-zinc-800 border-zinc-600 text-zinc-300 hover:bg-zinc-700 hover:border-zinc-400"
      }
      ${disabled ? "opacity-40 cursor-not-allowed" : "cursor-pointer"}
    `}
  >
    {children}
  </button>
);

const Sep: React.FC = () => (
  <div className="w-px h-6 bg-zinc-600 mx-1" />
);

export const Toolbar: React.FC<Props> = ({
  activeShape, mode, show3D, hasShape,
  onShapeSelect, onModeChange, onToggle3D,
  onClear, onSaveSTL, onLoadSTL,
}) => (
  <header className="flex items-center gap-2 px-4 py-2 bg-zinc-900 border-b border-zinc-700 flex-wrap">
    {/* Logo */}
    <span className="font-mono text-sm font-bold text-purple-400 mr-2 select-none tracking-wider">
      SHAPE3D
    </span>

    <Sep />

    {/* Draw group */}
    <span className="text-xs text-zinc-500 font-mono">DRAW</span>
    <Btn active={activeShape === "rect"}   onClick={() => onShapeSelect("rect")}>   Rectangle </Btn>
    <Btn active={activeShape === "square"} onClick={() => onShapeSelect("square")}> Square    </Btn>
    <Btn active={activeShape === "circle"} onClick={() => onShapeSelect("circle")}> Circle    </Btn>

    <Sep />

    {/* Options group */}
    <span className="text-xs text-zinc-500 font-mono">OPTIONS</span>
    <Btn
      active={mode === "edit" && !show3D}
      disabled={!hasShape || show3D}
      onClick={() => onModeChange("edit")}
    >Edit</Btn>
    <Btn
      active={!show3D && mode === "none"}
      onClick={() => onModeChange("none")}
    >None</Btn>
    <Btn
      active={show3D}
      disabled={!hasShape}
      onClick={onToggle3D}
    >{show3D ? "← 2D" : "3D View"}</Btn>

    <Sep />

    <Btn onClick={onClear}>Clear</Btn>

    <Sep />

    {/* STL */}
    <span className="text-xs text-zinc-500 font-mono">STL</span>
    <Btn disabled={!hasShape} onClick={onSaveSTL}>Save STL</Btn>
    <Btn onClick={onLoadSTL}>Load STL</Btn>
  </header>
);
