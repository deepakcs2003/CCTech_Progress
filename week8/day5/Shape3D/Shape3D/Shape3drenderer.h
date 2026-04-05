#pragma once
#include "Shape.h"
#include <QOpenGLFunctions_3_3_Core>
#include <vector>


class Shape3DRenderer : protected QOpenGLFunctions_3_3_Core {
public:
    Shape3DRenderer() = default;

    void init();

    void render(const Shape* shape, float rotY, int winW, int winH);

private:
    GLuint vao = 0, vbo = 0, prog = 0;
    GLint  colorLoc = -1;

    void drawLines(const std::vector<float>& pts,
        float r, float g, float b,
        int winW, int winH);

    void drawCube(float cx, float cy, float side, float rotY, int w, int h);
    void drawCuboid(float cx, float cy, float ww, float hh, float rotY, int w, int h);
    void drawSphere(float cx, float cy, float r, float rotY, int w, int h);

    void project(float x, float y, float z, float rotY,
        float& ox, float& oy);

    std::vector<float> boxEdges(float verts[8][3], float rotY,
        float cx, float cy);
};