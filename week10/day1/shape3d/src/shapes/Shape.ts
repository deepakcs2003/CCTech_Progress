// Shape.ts — Abstract base for all 2D/3D shapes
// Mirrors C++ Shape.h

export interface Point2D {
  x: number;
  y: number;
}

export abstract class Shape {
  protected pts: Point2D[] = [];

  abstract name(): string;
  abstract setEnd(p: Point2D): void;
  abstract getVertices(): number[];       // 2D line segments (x,y pairs)
  abstract getMesh3D(): number[];          // 3D triangles (x,y,z triples)
  abstract getControlPoints(): Point2D[];
  abstract moveControlPoint(idx: number, p: Point2D): void;

  /** Returns index of nearest control point within tolerance, or -1 */
  nearestControlPoint(pos: Point2D, tol: number): number {
    for (let i = 0; i < this.pts.length; i++) {
      const dx = this.pts[i].x - pos.x;
      const dy = this.pts[i].y - pos.y;
      if (dx * dx + dy * dy < tol * tol) return i;
    }
    return -1;
  }
}
