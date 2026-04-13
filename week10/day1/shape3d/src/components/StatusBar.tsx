// StatusBar.tsx — bottom info strip

import React from "react";

interface Props {
  shapeName: string | null;
  mode:      string;
  show3D:    boolean;
  vertCount: number;
}

export const StatusBar: React.FC<Props> = ({ shapeName, mode, show3D, vertCount }) => (
  <footer className="flex items-center gap-4 px-4 py-1.5 bg-zinc-900 border-t border-zinc-700 text-xs font-mono text-zinc-500">
    <span>Shape: <span className="text-zinc-300">{shapeName ?? "—"}</span></span>
    <span>Mode: <span className="text-zinc-300">{show3D ? "3D" : mode}</span></span>
    {show3D && (
      <span>Triangles: <span className="text-purple-400">{vertCount / 9}</span></span>
    )}
    <span className="ml-auto text-zinc-600">Click &amp; drag to draw · Edit mode → drag handles · 3D → orbit with mouse</span>
  </footer>
);
