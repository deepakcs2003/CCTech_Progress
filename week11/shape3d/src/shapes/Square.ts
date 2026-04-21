import { Shape, type Point2D } from "./Shape";

export class Square extends Shape {
  private start: Point2D;

  constructor(s: Point2D, e: Point2D) {
    super();
    this.start = s;

    this.pts = [
      { x: 0, y: 0 },
      { x: 0, y: 0 },
      { x: 0, y: 0 },
      { x: 0, y: 0 }
    ];

    this.rebuild(s, e);
  }

  name() {
    return "Square";
  }

  setEnd(p: Point2D) {
    this.rebuild(this.start, p);
  }

  moveControlPoint(i: number, p: Point2D) {
    const opposite = (i + 2) % 4;
    this.rebuild(this.pts[opposite], p);
  }

  getControlPoints() {
    return this.pts;
  }

  private rebuild(a: Point2D, b: Point2D) {
    const dx = b.x - a.x;
    const dy = b.y - a.y;

    let side = Math.min(Math.abs(dx), Math.abs(dy));

    if (dx < 0) side = -side;
    if (dy < 0) side = -side;

    const x0 = a.x;
    const y0 = a.y;

    this.pts[0] = { x: x0, y: y0 + side };
    this.pts[1] = { x: x0 + side, y: y0 + side };
    this.pts[2] = { x: x0 + side, y: y0 };
    this.pts[3] = { x: x0, y: y0 };
  }

  getVertices(): number[] {
    const v: number[] = [];

    for (let i = 0; i < 4; i++) {
      const next = (i + 1) % 4;

      v.push(this.pts[i].x, this.pts[i].y);
      v.push(this.pts[next].x, this.pts[next].y);
    }

    return v;
  }

  getMesh3D(): number[] {
    const cx = (this.pts[0].x + this.pts[2].x) / 2;
    const cy = (this.pts[0].y + this.pts[2].y) / 2;
    const s = Math.abs(this.pts[1].x - this.pts[0].x) / 2;

    const verts = [
      [-s,-s,-s], [s,-s,-s], [s,s,-s], [-s,s,-s],
      [-s,-s, s], [s,-s, s], [s,s, s], [-s,s, s]
    ];

    const idx = [
      0,1,2, 0,2,3,
      4,5,6, 4,6,7,
      0,3,7, 0,7,4,
      1,2,6, 1,6,5,
      3,2,6, 3,6,7,
      0,1,5, 0,5,4
    ];

    const mesh: number[] = [];

    for (let i = 0; i < idx.length; i++) {
      const id = idx[i];
      mesh.push(
        cx + verts[id][0],
        cy + verts[id][1],
        verts[id][2]
      );
    }

    return mesh;
  }
}