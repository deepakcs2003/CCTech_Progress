#include "GLWidget.h"
#include <QOpenGLContext>
#include <QOpenGLFunctions>

GLWidget::GLWidget(QWidget* parent) : QOpenGLWidget(parent)
{
	VBO = 0;
	VAO = 0;
}

GLWidget::~GLWidget()
{
	
}

void GLWidget::initializeGL()
{

    initializeOpenGLFunctions();


	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);

	glEnable(GL_DEPTH_TEST);
}

void GLWidget::resizeGL(int w, int h)
{
    // Viewport update — screen coordinates set karo
    glViewport(0, 0, w, h);

    // Projection matrix — 3D se 2D projection
    m_projection.setToIdentity();
    m_projection.perspective(
        45.0f,          // Field of view angle
        w / float(h),  // Aspect ratio
        0.01f,          // Near clipping plane
        100.0f          // Far clipping plane
    );

}

void GLWidget::paintGL()
{

    // Screen saaf karo (color + depth buffer dono)
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Apna scene draw karo
    // ... drawing code yahan ...
}
