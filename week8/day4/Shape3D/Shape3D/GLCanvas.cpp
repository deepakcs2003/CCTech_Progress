#include "GLCanvas.h"
#include "Rectangle.h"
#include "Square.h"
#include "Circle.h"
#include <vector>

// shaders
static const char* VERT =
"#version 330 core\nlayout(location=0) in vec2 p;\n"
"void main(){ gl_Position = vec4(p,0,1); }\n";

static const char* FRAG =
"#version 330 core\nuniform vec4 uC;\nout vec4 F;\n"
"void main(){ F = uC; }\n";

// constructor
GLCanvas::GLCanvas(QWidget* p) : QOpenGLWidget(p) {
    setMouseTracking(true); // track mouse
}

// destructor
GLCanvas::~GLCanvas() {
    makeCurrent(); // activate context
    glDeleteVertexArrays(1, &vao);
    glDeleteBuffers(1, &vbo);
    glDeleteProgram(prog);
    delete shape;
    doneCurrent(); // release context
}

// set shape
void GLCanvas::setShapeType(ShapeType t) {
    shapeType = t;
    mode = Mode::DRAW;
    show3D = false;
    delete shape;
    shape = nullptr;
    drawing = false;
    update();
}

// set mode
void GLCanvas::setMode(Mode m) {
    mode = m;
    show3D = false;
    selected = -1;
    update();
}

// clear canvas
void GLCanvas::clearCanvas() {
    delete shape;
    shape = nullptr;
    mode = Mode::NONE;
    show3D = false;
    selected = -1;
    update();
}

// toggle 3D
void GLCanvas::toggle3DView() {
    if (!shape) return;
    show3D = !show3D;
    update();
}

// init GL
void GLCanvas::initializeGL() {
    initializeOpenGLFunctions();
    glClearColor(0.15f, 0.15f, 0.15f, 1);
    glGenVertexArrays(1, &vao);
    glGenBuffers(1, &vbo);
    buildShader();
}

// resize view
void GLCanvas::resizeGL(int w, int h) {
    glViewport(0, 0, w, h);
}

// build shader
void GLCanvas::buildShader() {
    auto make = [this](GLenum t, const char* s) {
        GLuint sh = glCreateShader(t);
        glShaderSource(sh, 1, &s, nullptr);
        glCompileShader(sh);
        return sh;
        };

    GLuint vs = make(GL_VERTEX_SHADER, VERT);
    GLuint fs = make(GL_FRAGMENT_SHADER, FRAG);

    prog = glCreateProgram();
    glAttachShader(prog, vs);
    glAttachShader(prog, fs);
    glLinkProgram(prog);

    glDeleteShader(vs);
    glDeleteShader(fs);

    colorLoc = glGetUniformLocation(prog, "uC");
}

// draw function
void GLCanvas::draw(const std::vector<float>& px, GLenum type,
    float r, float g, float b)
{
    if (px.empty()) return;

    std::vector<float> nd;

    // screen → NDC convert
    for (int i = 0; i < (int)px.size(); i += 2) {
        float x = (px[i] / width()) * 2.0f - 1.0f;
        float y = -(px[i + 1] / height()) * 2.0f + 1.0f;

        nd.push_back(x);
        nd.push_back(y);
    }

    glBindVertexArray(vao);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);

    glBufferData(GL_ARRAY_BUFFER, nd.size() * sizeof(float), nd.data(), GL_DYNAMIC_DRAW);

    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, nullptr);
    glEnableVertexAttribArray(0);

    glUseProgram(prog);
    glUniform4f(colorLoc, r, g, b, 1.0f);

    glDrawArrays(type, 0, nd.size() / 2);
}

// render
void GLCanvas::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT);

    if (!shape) return;

    // 🔷 3D MODE
    if (show3D)
    {
        std::vector<float> v = shape->getVertices3D(30.0f);

        // triangles draw
        draw(v, GL_TRIANGLES, 0.2f, 0.8f, 1.0f);

        return;
    }

    // 🔷 2D MODE
    std::vector<float> v = shape->getVertices();  // ❌ flaot → ✔ float
    draw(v, GL_LINES, 1.0f, 1.0f, 1.0f);

    // 🔷 EDIT MODE
    if (mode == Mode::EDIT)
    {
        auto pts = shape->getControlPoints();

        for (int i = 0; i < (int)pts.size(); i++)
        {
            float x = pts[i].x();
            float y = pts[i].y();
            float d = 6.0f;

            std::vector<float> cross = {
                x - d, y, x + d, y,
                x, y - d, x, y + d
            };

            bool sel = (i == selected);

            // cross lines
            draw(cross, GL_LINES, sel ? 1.0f : 0.0f, 1.0f, 0.0f);

            // point
            std::vector<float> pt = { x, y };
            draw(pt, GL_POINTS, sel ? 1.0f : 0.0f, 1.0f, 0.0f);
        }
    }
}
// mouse press
void GLCanvas::mousePressEvent(QMouseEvent* e) {
    if (show3D) return; // ignore 3D

    if (mode == Mode::DRAW && shapeType != ShapeType::NONE) {
        start = e->pos();
        delete shape;

        if (shapeType == ShapeType::RECT)
            shape = new Rectangle(start, start);
        else if (shapeType == ShapeType::SQUARE)
            shape = new Square(start, start);
        else if (shapeType == ShapeType::CIRCLE)
            shape = new Circle(start, start);

        drawing = true;
    }
    else if (mode == Mode::EDIT && shape) {
        selected = shape->nearestControlPoint(e->pos(), tol);
        update();
    }
}

// mouse move
void GLCanvas::mouseMoveEvent(QMouseEvent* e) {
    if (show3D) return;

    if (mode == Mode::DRAW && drawing && shape) {
        shape->setEnd(e->pos());
        update();
    }
    else if (mode == Mode::EDIT && selected != -1 && shape) {
        shape->moveControlPoint(selected, e->pos());
        update();
    }
}

// mouse release
void GLCanvas::mouseReleaseEvent(QMouseEvent*) {
    if (show3D) return;

    if (mode == Mode::DRAW && drawing) {
        drawing = false;
        mode = Mode::NONE;
        show3D = true; // auto 3D
        update();
    }

    selected = -1;
}