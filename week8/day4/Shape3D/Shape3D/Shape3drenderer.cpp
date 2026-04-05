#include "Shape3DRenderer.h"
#include <cmath>
#include <algorithm>

static const float PI = 3.14159265f;

// simple shaders (same as GLCanvas)
static const char* VERT3D =
"#version 330 core\n"
"layout(location=0) in vec2 p;\n"
"void main(){ gl_Position = vec4(p,0,1); }\n";

static const char* FRAG3D =
"#version 330 core\n"
"uniform vec4 uC;\n"
"out vec4 F;\n"
"void main(){ F = uC; }\n";

// ─────────────────────────────────────────────
// init: OpenGL objects banao
// ─────────────────────────────────────────────
void Shape3DRenderer::init() {
    initializeOpenGLFunctions();

    glGenVertexArrays(1, &vao);
    glGenBuffers(1, &vbo);

    // shader banao
    auto compile = [this](GLenum type, const char* src) -> GLuint {
        GLuint sh = glCreateShader(type);
        glShaderSource(sh, 1, &src, nullptr);
        glCompileShader(sh);
        return sh;
        };

    GLuint vs = compile(GL_VERTEX_SHADER, VERT3D);
    GLuint fs = compile(GL_FRAGMENT_SHADER, FRAG3D);

    prog = glCreateProgram();
    glAttachShader(prog, vs);
    glAttachShader(prog, fs);
    glLinkProgram(prog);

    glDeleteShader(vs);
    glDeleteShader(fs);

    colorLoc = glGetUniformLocation(prog, "uC");
}

// ─────────────────────────────────────────────
// render: shape dekho, 3D banao same jagah
// ─────────────────────────────────────────────
void Shape3DRenderer::render(const Shape* shape, float rotY, int winW, int winH) {
    if (!shape) return;

    std::string nm = shape->name();
    auto cpts = shape->getControlPoints();

    if (nm == "Square") {
        // square ki 4 corners se center aur side nikalo
        float cx = (cpts[0].x() + cpts[2].x()) / 2.0f;
        float cy = (cpts[0].y() + cpts[2].y()) / 2.0f;
        float side = std::abs((float)(cpts[1].x() - cpts[0].x())); // width = height

        drawCube(cx, cy, side, rotY, winW, winH);
    }
    else if (nm == "Rectangle") {
        // rectangle ka center aur W/H
        float cx = (cpts[0].x() + cpts[2].x()) / 2.0f;
        float cy = (cpts[0].y() + cpts[2].y()) / 2.0f;
        float w = std::abs((float)(cpts[1].x() - cpts[0].x()));
        float h = std::abs((float)(cpts[2].y() - cpts[1].y()));

        drawCuboid(cx, cy, w, h, rotY, winW, winH);
    }
    else if (nm == "Circle") {
        // circle ka center aur radius
        float cx = (float)cpts[0].x();
        float cy = (float)cpts[0].y();
        float r = std::abs((float)(cpts[1].x() - cpts[0].x()));

        drawSphere(cx, cy, r, rotY, winW, winH);
    }
}

// ─────────────────────────────────────────────
// project: 3D → 2D (isometric, Y-axis rotation)
// ─────────────────────────────────────────────
void Shape3DRenderer::project(float x, float y, float z, float rotY,
    float& ox, float& oy) {
    float rad = rotY * PI / 180.0f;
    float cosA = cosf(rad);
    float sinA = sinf(rad);

    // Y-axis ke around rotate karo
    float rx = x * cosA - z * sinA;
    float rz = x * sinA + z * cosA;

    // isometric tilt (z ko y mein thoda mix karo)
    ox = rx;
    oy = y - rz * 0.5f;
}

// ─────────────────────────────────────────────
// boxEdges: 8 corners se 12 edges ki line list
// ─────────────────────────────────────────────
std::vector<float> Shape3DRenderer::boxEdges(float verts[8][3], float rotY,
    float cx, float cy) {
    // project all 8 corners
    float px[8], py[8];
    for (int i = 0; i < 8; i++) {
        float ox, oy;
        project(verts[i][0], verts[i][1], verts[i][2], rotY, ox, oy);
        px[i] = cx + ox;
        py[i] = cy + oy;
    }

    // 12 edges (box ki definition)
    int edges[12][2] = {
        {0,1},{1,2},{2,3},{3,0},  // back face
        {4,5},{5,6},{6,7},{7,4},  // front face
        {0,4},{1,5},{2,6},{3,7}   // connecting edges
    };

    std::vector<float> lines;
    for (auto& e : edges) {
        lines.push_back(px[e[0]]); lines.push_back(py[e[0]]);
        lines.push_back(px[e[1]]); lines.push_back(py[e[1]]);
    }
    return lines;
}

// ─────────────────────────────────────────────
// drawCube: Square → Cube
// center = 2D shape ka center, side = 2D side length
// ─────────────────────────────────────────────
void Shape3DRenderer::drawCube(float cx, float cy, float side,
    float rotY, int w, int h) {
    float s = side * 0.5f;  // half-side
    float d = s * 0.6f;     // depth (thoda kam rakha dikh sake)

    // 8 corners: front face (z=+d), back face (z=-d)
    float v[8][3] = {
        {-s, -s, -d}, { s, -s, -d}, { s,  s, -d}, {-s,  s, -d},  // back
        {-s, -s,  d}, { s, -s,  d}, { s,  s,  d}, {-s,  s,  d}   // front
    };

    auto lines = boxEdges(v, rotY, cx, cy);

    // back face = dark, front+edges = cyan
    // pehle back (first 8 floats = 4 back edges)
    std::vector<float> back(lines.begin(), lines.begin() + 8 * 2);
    std::vector<float> front(lines.begin() + 8 * 2, lines.end());

    drawLines(back, 0.35f, 0.35f, 0.35f, w, h);  // dark grey
    drawLines(front, 0.2f, 0.85f, 1.0f, w, h);  // cyan
}

// ─────────────────────────────────────────────
// drawCuboid: Rectangle → Cuboid
// same W and H as 2D rectangle, depth = average
// ─────────────────────────────────────────────
void Shape3DRenderer::drawCuboid(float cx, float cy, float ww, float hh,
    float rotY, int w, int h) {
    float hw = ww * 0.5f;
    float hh2 = hh * 0.5f;
    float d = (ww + hh) * 0.25f * 0.6f;  // depth proportional

    float v[8][3] = {
        {-hw, -hh2, -d}, { hw, -hh2, -d}, { hw,  hh2, -d}, {-hw,  hh2, -d},
        {-hw, -hh2,  d}, { hw, -hh2,  d}, { hw,  hh2,  d}, {-hw,  hh2,  d}
    };

    auto lines = boxEdges(v, rotY, cx, cy);

    std::vector<float> back(lines.begin(), lines.begin() + 8 * 2);
    std::vector<float> front(lines.begin() + 8 * 2, lines.end());

    drawLines(back, 0.35f, 0.35f, 0.35f, w, h);
    drawLines(front, 1.0f, 0.6f, 0.2f, w, h);  // orange
}

// ─────────────────────────────────────────────
// drawSphere: Circle → Sphere (3 rings)
// same center, same radius as 2D circle
// ─────────────────────────────────────────────
void Shape3DRenderer::drawSphere(float cx, float cy, float r,
    float rotY, int w, int h) {
    int SEG = 48;

    // ring 1 – equator (XZ plane)
    {
        std::vector<float> pts;
        for (int i = 0; i < SEG; i++) {
            float t1 = 2 * PI * i / SEG, t2 = 2 * PI * (i + 1) / SEG;
            float ox1, oy1, ox2, oy2;
            project(r * cosf(t1), 0, r * sinf(t1), rotY, ox1, oy1);
            project(r * cosf(t2), 0, r * sinf(t2), rotY, ox2, oy2);
            pts.push_back(cx + ox1); pts.push_back(cy + oy1);
            pts.push_back(cx + ox2); pts.push_back(cy + oy2);
        }
        drawLines(pts, 0.3f, 1.0f, 0.5f, w, h);  // green
    }

    // ring 2 – vertical (XY plane)
    {
        std::vector<float> pts;
        for (int i = 0; i < SEG; i++) {
            float t1 = 2 * PI * i / SEG, t2 = 2 * PI * (i + 1) / SEG;
            float ox1, oy1, ox2, oy2;
            project(r * cosf(t1), r * sinf(t1), 0, rotY, ox1, oy1);
            project(r * cosf(t2), r * sinf(t2), 0, rotY, ox2, oy2);
            pts.push_back(cx + ox1); pts.push_back(cy + oy1);
            pts.push_back(cx + ox2); pts.push_back(cy + oy2);
        }
        drawLines(pts, 0.2f, 0.8f, 1.0f, w, h);  // blue
    }

    // ring 3 – vertical (YZ plane)
    {
        std::vector<float> pts;
        for (int i = 0; i < SEG; i++) {
            float t1 = 2 * PI * i / SEG, t2 = 2 * PI * (i + 1) / SEG;
            float ox1, oy1, ox2, oy2;
            project(0, r * sinf(t1), r * cosf(t1), rotY, ox1, oy1);
            project(0, r * sinf(t2), r * cosf(t2), rotY, ox2, oy2);
            pts.push_back(cx + ox1); pts.push_back(cy + oy1);
            pts.push_back(cx + ox2); pts.push_back(cy + oy2);
        }
        drawLines(pts, 1.0f, 1.0f, 0.3f, w, h);  // yellow
    }
}

// ─────────────────────────────────────────────
// drawLines: pixel coords → NDC → OpenGL draw
// ─────────────────────────────────────────────
void Shape3DRenderer::drawLines(const std::vector<float>& pts,
    float r, float g, float b,
    int winW, int winH) {
    if (pts.empty()) return;

    std::vector<float> nd;
    nd.reserve(pts.size());

    for (int i = 0; i < (int)pts.size(); i += 2) {
        nd.push_back((pts[i] / winW) * 2.0f - 1.0f);   // x: pixel → NDC
        nd.push_back(-((pts[i + 1] / winH) * 2.0f - 1.0f));  // y: flip
    }

    glBindVertexArray(vao);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, nd.size() * sizeof(float), nd.data(), GL_DYNAMIC_DRAW);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, nullptr);
    glEnableVertexAttribArray(0);

    glUseProgram(prog);
    glUniform4f(colorLoc, r, g, b, 1.0f);
    glDrawArrays(GL_LINES, 0, nd.size() / 2);
}