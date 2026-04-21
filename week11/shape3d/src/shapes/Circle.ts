import { Shape, type Point2D } from "./Shape";

export class Circle extends Shape {
  private start: Point2D;

  constructor(s: Point2D, e: Point2D) {
    super();
    this.start = s;

    this.pts = [
      { x: 0, y: 0 },
      { x: 0, y: 0 }
    ];

    this.setEnd(e);
  }

  name() {
    return "Circle";
  }

  setEnd(p: Point2D) {
    const cx = (this.start.x + p.x) / 2;
    const cy = (this.start.y + p.y) / 2;

    let r = Math.min(
      Math.abs(p.x - this.start.x),
      Math.abs(p.y - this.start.y)
    ) / 2;

    if (r < 1) r = 1;

    this.pts[0] = { x: cx, y: cy };
    this.pts[1] = { x: cx + r, y: cy };
  }

  moveControlPoint(i: number, p: Point2D) {
    if (i === 0) {
      const dx = p.x - this.pts[0].x;
      const dy = p.y - this.pts[0].y;

      this.pts[0] = p;
      this.pts[1].x += dx;
      this.pts[1].y += dy;
    } else {
      const dx = p.x - this.pts[0].x;
      const dy = p.y - this.pts[0].y;

      const r = Math.sqrt(dx * dx + dy * dy);

      this.pts[1] = {
        x: this.pts[0].x + r,
        y: this.pts[0].y
      };
    }
  }

  getControlPoints() {
    return this.pts;
  }

  getVertices(): number[] {
    const v: number[] = [];

    const cx = this.pts[0].x;
    const cy = this.pts[0].y;
    const r = this.pts[1].x - this.pts[0].x;

    const SEG = 60;

    for (let i = 0; i < SEG; i++) {
      const t1 = (2 * Math.PI * i) / SEG;
      const t2 = (2 * Math.PI * (i + 1)) / SEG;

      v.push(cx + r * Math.cos(t1), cy + r * Math.sin(t1));
      v.push(cx + r * Math.cos(t2), cy + r * Math.sin(t2));
    }

    return v;
  }

  getMesh3D(): number[] {
    const mesh: number[] = [];

    const cx = this.pts[0].x;
    const cy = this.pts[0].y;
    const r = this.pts[1].x - this.pts[0].x;

    const LAT = 20;
    const LON = 20;

    for (let i = 0; i < LAT; i++) {
      const t1 = (Math.PI * i) / LAT - Math.PI / 2;
      const t2 = (Math.PI * (i + 1)) / LAT - Math.PI / 2;

      for (let j = 0; j < LON; j++) {
        const p1 = (2 * Math.PI * j) / LON;
        const p2 = (2 * Math.PI * (j + 1)) / LON;

        const x1 = r * Math.cos(t1) * Math.cos(p1);
        const y1 = r * Math.sin(t1);
        const z1 = r * Math.cos(t1) * Math.sin(p1);

        const x2 = r * Math.cos(t1) * Math.cos(p2);
        const y2 = r * Math.sin(t1);
        const z2 = r * Math.cos(t1) * Math.sin(p2);

        const x3 = r * Math.cos(t2) * Math.cos(p1);
        const y3 = r * Math.sin(t2);
        const z3 = r * Math.cos(t2) * Math.sin(p1);

        const x4 = r * Math.cos(t2) * Math.cos(p2);
        const y4 = r * Math.sin(t2);
        const z4 = r * Math.cos(t2) * Math.sin(p2);

        mesh.push(cx+x1, cy+y1, z1);
        mesh.push(cx+x2, cy+y2, z2);
        mesh.push(cx+x3, cy+y3, z3);

        mesh.push(cx+x2, cy+y2, z2);
        mesh.push(cx+x4, cy+y4, z4);
        mesh.push(cx+x3, cy+y3, z3);
      }
    }

    return mesh;
  }
}