// Canvas3D.tsx
// Renders 3D mesh via Three.js — mirrors GLCanvas draw3D / paintGL 3D logic.
// Uses simple perspective projection + OrbitControls-style drag rotation.

import React, { useRef, useEffect } from "react";
import * as THREE from "three";
import { OrbitControls } from "three/examples/jsm/controls/OrbitControls.js";

interface Props {
  meshData: number[];   // flat [x,y,z, ...] triangle soup (screen-space coords)
}

export const Canvas3D: React.FC<Props> = ({ meshData }) => {
  const mountRef = useRef<HTMLDivElement>(null);
  const rendererRef = useRef<THREE.WebGLRenderer | null>(null);
  const sceneRef    = useRef<THREE.Scene | null>(null);
  const cameraRef   = useRef<THREE.PerspectiveCamera | null>(null);
  const meshRef     = useRef<THREE.Mesh | null>(null);
  const controlsRef = useRef<OrbitControls | null>(null);
  const frameRef    = useRef<number>(0);

  // ── init Three.js scene once ──────────────────────────────────────────────
  useEffect(() => {
    const mount = mountRef.current!;
    const w = mount.clientWidth, h = mount.clientHeight;

    const renderer = new THREE.WebGLRenderer({ antialias: true, alpha: true });
    renderer.setSize(w, h);
    renderer.setPixelRatio(window.devicePixelRatio);
    renderer.setClearColor(0x1a1a2e, 1);
    mount.appendChild(renderer.domElement);
    rendererRef.current = renderer;

    const scene = new THREE.Scene();
    sceneRef.current = scene;

    // Lights
    scene.add(new THREE.AmbientLight(0xffffff, 0.4));
    const dir = new THREE.DirectionalLight(0xffffff, 1.2);
    dir.position.set(300, 500, 400);
    scene.add(dir);
    const fill = new THREE.DirectionalLight(0x8899ff, 0.5);
    fill.position.set(-300, -200, -400);
    scene.add(fill);

    const camera = new THREE.PerspectiveCamera(45, w / h, 0.1, 10000);
    camera.position.set(0, 0, 800);
    cameraRef.current = camera;

    const controls = new OrbitControls(camera, renderer.domElement);
    controls.enableDamping = true;
    controls.dampingFactor = 0.08;
    controlsRef.current = controls;

    const animate = () => {
      frameRef.current = requestAnimationFrame(animate);
      controls.update();
      renderer.render(scene, camera);
    };
    animate();

    const handleResize = () => {
      const nw = mount.clientWidth, nh = mount.clientHeight;
      camera.aspect = nw / nh;
      camera.updateProjectionMatrix();
      renderer.setSize(nw, nh);
    };
    window.addEventListener("resize", handleResize);

    return () => {
      cancelAnimationFrame(frameRef.current);
      window.removeEventListener("resize", handleResize);
      controls.dispose();
      renderer.dispose();
      mount.removeChild(renderer.domElement);
    };
  }, []);

  // ── rebuild mesh whenever meshData changes ────────────────────────────────
  useEffect(() => {
    const scene = sceneRef.current;
    if (!scene) return;

    // remove old mesh
    if (meshRef.current) {
      scene.remove(meshRef.current);
      meshRef.current.geometry.dispose();
      (meshRef.current.material as THREE.Material).dispose();
      meshRef.current = null;
    }

    if (meshData.length === 0) return;

    // Convert screen-space coords → centred Three.js world space
    // Compute bounding box to centre the mesh
    let minX = Infinity, maxX = -Infinity;
    let minY = Infinity, maxY = -Infinity;
    let minZ = Infinity, maxZ = -Infinity;

    for (let i = 0; i < meshData.length; i += 3) {
      minX = Math.min(minX, meshData[i]);   maxX = Math.max(maxX, meshData[i]);
      minY = Math.min(minY, meshData[i+1]); maxY = Math.max(maxY, meshData[i+1]);
      minZ = Math.min(minZ, meshData[i+2]); maxZ = Math.max(maxZ, meshData[i+2]);
    }

    const cx = (minX + maxX) / 2;
    const cy = (minY + maxY) / 2;
    const cz = (minZ + maxZ) / 2;

    // Build geometry — flip Y (canvas Y-down → Three.js Y-up)
    const positions: number[] = [];
    for (let i = 0; i < meshData.length; i += 3) {
      positions.push(
        meshData[i]   - cx,
        -(meshData[i+1] - cy),
        meshData[i+2] - cz
      );
    }

    const geometry = new THREE.BufferGeometry();
    geometry.setAttribute("position", new THREE.Float32BufferAttribute(positions, 3));
    geometry.computeVertexNormals();

    const material = new THREE.MeshPhongMaterial({
      color: 0x9933ff,
      emissive: 0x220044,
      specular: 0xffffff,
      shininess: 60,
      side: THREE.DoubleSide,
      wireframe: false,
    });

    const mesh = new THREE.Mesh(geometry, material);
    scene.add(mesh);
    meshRef.current = mesh;

    // Auto-fit camera
    const size = Math.max(maxX - minX, maxY - minY, maxZ - minZ);
    const camera = cameraRef.current!;
    camera.position.set(0, 0, size * 1.8);
    camera.near = size * 0.01;
    camera.far  = size * 20;
    camera.updateProjectionMatrix();
    if (controlsRef.current) controlsRef.current.target.set(0, 0, 0);
  }, [meshData]);

  return (
    <div
      ref={mountRef}
      className="w-full h-full"
      style={{ background: "#1a1a2e" }}
    />
  );
};
