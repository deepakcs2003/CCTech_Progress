#pragma once
#include "Shape.h"
#include <QOpenGLFunctions_3_3_Core>
#include <vector>

// ─────────────────────────────────────────────────────
//  Shape3DRenderer
//  Ek alag module sirf 3D drawing ke liye.
//  GLCanvas is module ko use karta hai.
//
//  Square  → Cube
//  Rect    → Cuboid
//  Circle  → Sphere
//
//  Same jagah, same size jahan 2D draw hua.
// ─────────────────────────────────────────────────────

class Shape3DRenderer : protected QOpenGLFunctions_3_3_Core {
public:
    Shape3DRenderer() = default;

    // OpenGL init (GLCanvas ke initializeGL se call karo)
    void init();

    // Shape ki info se 3D draw karo
    // shape   = current 2D shape
    // rotY    = Y-axis rotation angle (degrees)
    // winW/H  = window width/height (pixel → NDC ke liye)
    void render(const Shape* shape, float rotY, int winW, int winH);

private:
    GLuint vao = 0, vbo = 0, prog = 0;
    GLint  colorLoc = -1;

    // ---- low-level draw ----
    void drawLines(const std::vector<float>& pts,
        float r, float g, float b,
        int winW, int winH);

    // ---- 3D shape drawers ----
    void drawCube(float cx, float cy, float side, float rotY, int w, int h);
    void drawCuboid(float cx, float cy, float ww, float hh, float rotY, int w, int h);
    void drawSphere(float cx, float cy, float r, float rotY, int w, int h);

    // ---- isometric projection ----
    // 3D (x,y,z) → 2D screen (ox, oy)
    void project(float x, float y, float z, float rotY,
        float& ox, float& oy);

    // ---- build 12 edges of a box ----
    std::vector<float> boxEdges(float verts[8][3], float rotY,
        float cx, float cy);
};