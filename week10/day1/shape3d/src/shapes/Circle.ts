// Circle.ts — Mirrors Circle.cpp / Circle.h

import { Shape, type Point2D } from "./Shape";

const PI = Math.PI;
const SEG = 60;
const LAT = 30;
const LON = 30;

export class Circle extends Shape {
  private start: Point2D;

  constructor(s: Point2D, e: Point2D) {
    super();
    this.start = { ...s };
    this.pts = [{ x: 0, y: 0 }, { x: 0, y: 0 }];
    this.setEnd(e);
  }

  name() { return "Circle"; }

  setEnd(p: Point2D) {
    const center: Point2D = {
      x: (this.start.x + p.x) / 2,
      y: (this.start.y + p.y) / 2,
    };
    const r = Math.max(
      1,
      Math.min(Math.abs(p.x - this.start.x), Math.abs(p.y - this.start.y)) / 2
    );
    this.pts[0] = center;
    this.pts[1] = { x: center.x + r, y: center.y };
  }

  moveControlPoint(i: number, p: Point2D) {
    if (i === 0) {
      const diff = { x: p.x - this.pts[0].x, y: p.y - this.pts[0].y };
      this.pts[0] = p;
      this.pts[1] = { x: this.pts[1].x + diff.x, y: this.pts[1].y + diff.y };
    } else {
      const dx = p.x - this.pts[0].x;
      const dy = p.y - this.pts[0].y;
      const r = Math.max(1, Math.round(Math.sqrt(dx * dx + dy * dy)));
      this.pts[1] = { x: this.pts[0].x + r, y: this.pts[0].y };
    }
  }

  getControlPoints() { return this.pts; }

  // 2D — line segments around circumference
  getVertices(): number[] {
    const v: number[] = [];
    const cx = this.pts[0].x, cy = this.pts[0].y;
    const r = this.pts[1].x - this.pts[0].x;

    for (let i = 0; i < SEG; i++) {
      const t1 = (2 * PI * i) / SEG;
      const t2 = (2 * PI * (i + 1)) / SEG;
      v.push(cx + r * Math.cos(t1), cy + r * Math.sin(t1));
      v.push(cx + r * Math.cos(t2), cy + r * Math.sin(t2));
    }
    return v;
  }

  // 3D — sphere mesh
  getMesh3D(): number[] {
    const cx = this.pts[0].x;
    const cy = this.pts[0].y;
    const r  = this.pts[1].x - this.pts[0].x;
    const mesh: number[] = [];

    for (let i = 0; i < LAT; i++) {
      const t1 = (PI * i) / LAT - PI / 2;
      const t2 = (PI * (i + 1)) / LAT - PI / 2;

      for (let j = 0; j < LON; j++) {
        const p1 = (2 * PI * j) / LON;
        const p2 = (2 * PI * (j + 1)) / LON;

        const x1 = r * Math.cos(t1) * Math.cos(p1), y1 = r * Math.sin(t1), z1 = r * Math.cos(t1) * Math.sin(p1);
        const x2 = r * Math.cos(t1) * Math.cos(p2), y2 = r * Math.sin(t1), z2 = r * Math.cos(t1) * Math.sin(p2);
        const x3 = r * Math.cos(t2) * Math.cos(p1), y3 = r * Math.sin(t2), z3 = r * Math.cos(t2) * Math.sin(p1);
        const x4 = r * Math.cos(t2) * Math.cos(p2), y4 = r * Math.sin(t2), z4 = r * Math.cos(t2) * Math.sin(p2);

        // triangle 1
        mesh.push(cx+x1,cy+y1,z1, cx+x2,cy+y2,z2, cx+x3,cy+y3,z3);
        // triangle 2
        mesh.push(cx+x2,cy+y2,z2, cx+x4,cy+y4,z4, cx+x3,cy+y3,z3);
      }
    }
    return mesh;
  }
}
