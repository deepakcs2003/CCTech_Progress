import React, { useRef, useEffect } from "react";
import * as THREE from "three";
import { OrbitControls } from "three/examples/jsm/controls/OrbitControls.js";

interface Props {
  meshData: number[];
}

export const Canvas3D: React.FC<Props> = ({ meshData }) => {
  const mountRef = useRef<HTMLDivElement>(null);
  const meshRef = useRef<THREE.Mesh | null>(null);

  useEffect(() => {
    const mount = mountRef.current!;
    const w = mount.clientWidth;
    const h = mount.clientHeight;

    // basic setup
    const scene = new THREE.Scene();
    const camera = new THREE.PerspectiveCamera(45, w / h, 0.1, 10000);
    camera.position.set(0, 0, 800);
    // camera.position.z=-10;

    const renderer = new THREE.WebGLRenderer({ antialias: true });
    renderer.setSize(w, h);
    renderer.setClearColor(0x1a1a2e);
    mount.appendChild(renderer.domElement);

    const controls = new OrbitControls(camera, renderer.domElement);
    controls.enableDamping = true;

    scene.add(new THREE.AmbientLight(0xffffff, 0.5));
    const light = new THREE.DirectionalLight(0xffffff, 2);
    light.position.set(300, 300, 300);
    scene.add(light);

    //  mesh creation (clean)
    if (meshData.length) {
      const positions: number[] = [];

      for (let i = 0; i < meshData.length; i += 3) {
        positions.push(meshData[i], -meshData[i + 1], meshData[i + 2]);
      }

      const geometry = new THREE.BufferGeometry();
      geometry.setAttribute(
        "position",
        new THREE.Float32BufferAttribute(positions, 3)
      );
      geometry.computeVertexNormals();

      const mesh = new THREE.Mesh(
        geometry,
        new THREE.MeshPhongMaterial({ color: 0x9933ff, side: THREE.DoubleSide })
      );

      scene.add(mesh);
      meshRef.current = mesh;

      //  camera + rotation fix
      geometry.computeBoundingBox();
      const center = new THREE.Vector3();
      geometry.boundingBox!.getCenter(center);

      camera.position.set(center.x, center.y, 800);
      controls.target.copy(center);
    }

    // animate
    const animate = () => {
      requestAnimationFrame(animate);
      controls.update();
      renderer.render(scene, camera);
    };
    animate();

    // resize
    const onResize = () => {
      const nw = mount.clientWidth;
      const nh = mount.clientHeight;
      camera.aspect = nw / nh;
      camera.updateProjectionMatrix();
      renderer.setSize(nw, nh);
    };

    window.addEventListener("resize", onResize);

    return () => {
      window.removeEventListener("resize", onResize);
      renderer.dispose();
      mount.removeChild(renderer.domElement);
    };
  }, [meshData]);

  return <div ref={mountRef} className="w-full h-full" />;
};