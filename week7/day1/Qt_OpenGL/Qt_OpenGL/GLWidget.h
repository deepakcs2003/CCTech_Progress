#pragma once

#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QMatrix4x4>

class GLWidget : public QOpenGLWidget, protected QOpenGLFunctions
{
	Q_OBJECT
public:
	explicit GLWidget(QWidget *parent = nullptr);
	~GLWidget();

protected:
	void initializeGL() override;
	void resizeGL(int w, int h) override;
	void paintGL() override;

private:
	// Vertex Array / Buffer objects used in GLWidget.cpp
	GLuint VBO;
	GLuint VAO;

	// Projection matrix used in resizeGL and elsewhere
	QMatrix4x4 m_projection;
};

