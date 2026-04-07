#include "GLCanvas.h"
#include "Rectangle.h"
#include "Square.h"
#include "Circle.h"
#include <vector>

// shaders
static const char* VERT =
"#version 330 core\n"
"layout(location=0) in vec3 p;\n"
"void main(){\n"
"    gl_Position = vec4(p, 1.0);\n"
"}\n";

static const char* FRAG =
"#version 330 core\nuniform vec4 uC;\nout vec4 F;\n"
"void main(){ F = uC; }\n";

// constructor
GLCanvas::GLCanvas(QWidget* p) : QOpenGLWidget(p) {
    setMouseTracking(true);
}

// destructor
GLCanvas::~GLCanvas() {
    makeCurrent(); 
    glDeleteVertexArrays(1, &vao);
    glDeleteBuffers(1, &vbo);
    glDeleteProgram(prog);
    delete shape;
    doneCurrent(); 
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

    loadedMesh.clear();   
    loadingStl = false;

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
    glEnable(GL_DEPTH_TEST);
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
//void GLCanvas::draw(const std::vector<float>& px, GLenum type,
//    float r, float g, float b)
//{
//    if (px.empty()) return;
//
//    std::vector<float> nd;
//
//    // screen → NDC convert
//    for (int i = 0; i < (int)px.size(); i += 2) {
//        float x = (px[i] / width()) * 2.0f - 1.0f;
//        float y = -(px[i + 1] / height()) * 2.0f + 1.0f;
//
//        nd.push_back(x);
//        nd.push_back(y);
//    }
//
//    glBindVertexArray(vao);
//    glBindBuffer(GL_ARRAY_BUFFER, vbo);
//
//    glBufferData(GL_ARRAY_BUFFER, nd.size() * sizeof(float), nd.data(), GL_DYNAMIC_DRAW);
//
//    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, nullptr);
//    glEnableVertexAttribArray(0);
//
//    glUseProgram(prog);
//    glUniform4f(colorLoc, r, g, b, 1.0f);
//
//    glDrawArrays(type, 0, nd.size() / 2);
//}


void GLCanvas::draw2D(const std::vector<float>& px, GLenum type,
    float r, float g, float b)
{
    if (px.empty()) return;

    glDisable(GL_DEPTH_TEST);
    std::vector<float> nd;

    for (int i = 0; i < (int)px.size(); i += 2) {
        float x = (px[i] / width()) * 2.0f - 1.0f;
        float y = -(px[i + 1] / height()) * 2.0f + 1.0f;

        nd.push_back(x);
        nd.push_back(y);
        nd.push_back(0.0f);
    }

    glBindVertexArray(vao);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);

    glBufferData(GL_ARRAY_BUFFER, nd.size() * sizeof(float), nd.data(), GL_DYNAMIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, nullptr);
    glEnableVertexAttribArray(0);

    glUseProgram(prog);
    glUniform4f(colorLoc, r, g, b, 1.0f);

    glDrawArrays(type, 0, nd.size() / 2);
}


void GLCanvas::draw3D(const std::vector<float>& v, GLenum type,
    float r, float g, float b)
{
    if (v.empty()) return;

    glEnable(GL_DEPTH_TEST);

    std::vector<float> ndc;

    float camZ = 800.0f; 

    for (int i = 0; i < v.size(); i += 3)
    {
        float x = v[i];
        float y = v[i + 1];
        float z = v[i + 2];

        float px = x * (camZ / (camZ - z));
        float py = y * (camZ / (camZ - z));

        float nx = (px / width()) * 2.0f - 1.0f;
        float ny = -(py / height()) * 2.0f + 1.0f;

        ndc.push_back(nx);
        ndc.push_back(ny);
        ndc.push_back(z / camZ);
    }

    glBindVertexArray(vao);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);

    glBufferData(GL_ARRAY_BUFFER, ndc.size() * sizeof(float), ndc.data(), GL_DYNAMIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, nullptr);
    glEnableVertexAttribArray(0);

    glUseProgram(prog);
    glUniform4f(colorLoc, r, g, b, 1.0f);

    glDrawArrays(type, 0, ndc.size() / 3);
}


// render
void GLCanvas::paintGL()
{
    if (show3D)
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    else
        glClear(GL_COLOR_BUFFER_BIT);

    // check if stl is loaded
    if (loadingStl)
    {
        draw3D(loadedMesh, GL_TRIANGLES, 1.0f, 0.0f, 1.0f);
        return;
    }

  
    if (!shape) return;

    // 3D
    if (show3D)
    {
        loadedMesh = shape->getMesh3D();
        draw3D(loadedMesh, GL_TRIANGLES, 1.0f, 0.0f, 1.0f);
        return;
    }

    // 2D
    std::vector<float> v = shape->getVertices();
    draw2D(v, GL_LINES, 1.0f, 1.0f, 1.0f);

    // Editing
    if (mode == Mode::EDIT)
    {
        auto pts = shape->getControlPoints();

        for (int i = 0; i < pts.size(); i++)
        {
            float x = pts[i].x();
            float y = pts[i].y();
            float d = 6.0f;

            float r = (i == selected) ? 1.0f : 0.0f;
            float g = 1.0f;
            float b = (i == selected) ? 0.0f : 0.0f;

            draw2D({ x - d, y, x + d, y, x, y - d, x, y + d }, GL_LINES, r, g, b);
            draw2D({ x, y }, GL_POINTS, r, g, b);
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
        show3D = true;

        if (shape) {
            loadedMesh = shape->getMesh3D(); 
            trigulationDS.StoreData(loadedMesh);
            //trigulationDS.printData();
        }

        update();
    }

    selected = -1;
}

std::vector<float> GLCanvas::getMeshData() const
{
    if (loadingStl)
        return loadedMesh;

    if (!shape)
        return {};

    //return trigulationDS.getData();
    return shape->getMesh3D();
}

void GLCanvas::loadMeshData(const std::vector<float>& data)
{
    delete shape; 
    shape = nullptr;

    loadedMesh = data;
    loadingStl = true;
    show3D = true;

    trigulationDS.StoreData(loadedMesh);

    update();
}