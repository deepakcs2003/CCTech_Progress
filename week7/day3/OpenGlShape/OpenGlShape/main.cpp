// Copyright (C) 2016 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR BSD-3-Clause


#include <STL_ASCII.h>
#include <QGuiApplication>
#include <QMatrix4x4>
#include <QOpenGLShaderProgram>
#include <QOpenGLBuffer>
#include <QScreen>
#include <QtMath>
#include "OpenGlShape.h"
#include "fibonacci.h"
#include "GenerateCirclePoint.h"
#include "GenerateEllipsePoint.h"
#include "GenerateLinePoint.h"
#include "GenerateSpherePoint.h"
#include "GenerateCubePoint.h"

//! [1]
class TriangleWindow : public OpenGLWindow
{
public:
    using OpenGLWindow::OpenGLWindow;

    void initialize() override;
    void render() override;

private:
    GLint m_matrixUniform = 0;
    QOpenGLBuffer m_vbo;
    QOpenGLShaderProgram* m_program = nullptr;
    int m_frame = 0;
    int dataSize;
};
//! [1]

//! [2]
int main(int argc, char** argv)
{
    srand(time(0));
    QGuiApplication app(argc, argv);

    QSurfaceFormat format;
    format.setSamples(16);

    TriangleWindow window;
    window.setFormat(format);
    window.resize(640, 480);
    window.show();

    window.setAnimating(true);

    return app.exec();
}
//! [2]

//! [3]
static const char* vertexShaderSource = "attribute highp vec4 posAttr;\n"
"attribute lowp vec4 colAttr;\n"
"varying lowp vec4 col;\n"
"uniform highp mat4 matrix;\n"
"void main() {\n"
"   col = colAttr;\n"
"   gl_Position = matrix * posAttr;\n"
"}\n";

static const char* fragmentShaderSource = "varying lowp vec4 col;\n"
"void main() {\n"
"   gl_FragColor = col;\n"
"}\n";
//! [3]

//! [4]
void TriangleWindow::initialize()
{
    STL_ASCII f1;
    std::vector<float> data = f1.loadSTL();
    for (int i = 0;i < data.size();i++) {
        qDebug() << data[i];
    }
    
    //GenerateSpherePoint sphere(0.5f, 0.0f, 0.0f, 0.0f);

    //std::vector<float> data = sphere.generatePoint();


    // Translation
    //data = sphere.translationOrigin(0.5f, 0.0f, 0.0f);
    //data = sphere.translationSelf(0.5f, 0.2f, 0.7f);

    //// Scaling
    //data = sphere.scaleOrigin(1.5f, 1.5f, 1.5f);
    //data = sphere.scaleSelf(0.5f, 0.5f, 0.5f);

    //// Rotation
    //data = sphere.rotateOrigin(45.0f, 0.0f, 1.0f, 0.0f);
    //data = sphere.rotateSelf(45.0f, 1.0f, 0.0f, 0.0f);

    dataSize = data.size();

  
    //static const GLfloat vertices_colors[] = {
    //    // First Triangle (Normal)
    //     0.0f,  0.707f, 1.0f, 0.0f, 0.0f,
    //    -0.5f, -0.500f, 0.0f, 1.0f, 0.0f,
    //     0.5f, -0.500f, 0.0f, 0.0f, 1.0f,

    //     // Second Triangle (Inverted)
    //      0.0f, -0.707f, 1.0f, 1.0f, 0.0f,
    //     -0.5f,  0.500f, 0.0f, 1.0f, 1.0f,
    //      0.5f,  0.500f, 1.0f, 0.0f, 1.0f
    //};

    m_vbo.create();
    m_vbo.bind();
    m_vbo.allocate(data.data(), static_cast<int>(data.size() * sizeof(float)));

    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), nullptr);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat),
        reinterpret_cast<void*>(3 * sizeof(GLfloat)));

    m_program = new QOpenGLShaderProgram(this);
    m_program->addShaderFromSourceCode(QOpenGLShader::Vertex, vertexShaderSource);
    m_program->addShaderFromSourceCode(QOpenGLShader::Fragment, fragmentShaderSource);
    m_program->bindAttributeLocation("posAttr", 0);
    m_program->bindAttributeLocation("colAttr", 1);
    m_program->link();
    m_program->bind();

    m_matrixUniform = m_program->uniformLocation("matrix");
    Q_ASSERT(m_matrixUniform != -1);
}
//! [4]

//! [5]
void TriangleWindow::render()
{
    const qreal retinaScale = devicePixelRatio();
    glViewport(0, 0, width() * retinaScale, height() * retinaScale);

    glClear(GL_COLOR_BUFFER_BIT);

    m_program->bind();

    QMatrix4x4 matrix;
    matrix.perspective(60.0f, 4.0f / 3.0f, 0.1f, 100.0f);
    matrix.translate(0, 0, -4);
    matrix.rotate(100.0f * m_frame / screen()->refreshRate(), 0, 1, 0);
    //matrix.ortho(-3, 3, -3, 3, -1, 1);

    m_program->setUniformValue(m_matrixUniform, matrix);

    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);

    //glLineWidth(10.0f);
    //glPointSize(10.0f);

    //glDrawArrays(GL_TRIANGLE_FAN, 0, 102);
    //glDrawArrays(GL_LINE_STRIP, 0, 10);
    //glDrawArrays(GL_POINTS, 0, 10);
    //glDrawArrays(GL_TRIANGLE_FAN, 0, 402);

    //glPointSize(3.0f);
    glDrawArrays(GL_TRIANGLES, 0, dataSize / 6);

    //glDrawArrays(GL_LINE_STRIP, 0, dataSize / 6);

    //glDrawArrays(GL_TRIANGLES, 0, dataSize / 6);

    glDisableVertexAttribArray(0);
    glDisableVertexAttribArray(1);

    m_program->release();

    ++m_frame;
}
//! [5]