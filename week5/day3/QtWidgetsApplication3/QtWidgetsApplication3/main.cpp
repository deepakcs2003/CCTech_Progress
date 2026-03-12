#include <QApplication>
#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QMouseEvent>
#include <QWheelEvent>

#ifdef _WIN32
#include <Windows.h>
#endif
#include <GL/gl.h>
#include <GL/glu.h>

class GLWidget : public QOpenGLWidget, protected QOpenGLFunctions
{
public:
    float rotX = 30;
    float rotY = 0;
    float zoom = -6;

    QPoint lastPos;

protected:

    void initializeGL() override
    {
        initializeOpenGLFunctions();
        glEnable(GL_DEPTH_TEST);
    }

    void resizeGL(int w, int h) override
    {
        glViewport(0, 0, w, h);

        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();

        gluPerspective(45.0, (float)w / h, 0.1, 100.0);

        glMatrixMode(GL_MODELVIEW);
    }

    void paintGL() override
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glLoadIdentity();

        glTranslatef(0, -1, zoom);

        glRotatef(rotX, 1, 0, 0);
        glRotatef(rotY, 0, 1, 0);

        drawPlane();
        drawGrid();
    }

    void drawPlane()
    {
        glBegin(GL_QUADS);

        glColor3f(0.7f, 0.7f, 0.7f);

        glVertex3f(-5, 0, -5);
        glVertex3f(5, 0, -5);
        glVertex3f(5, 0, 5);
        glVertex3f(-5, 0, 5);

        glEnd();
    }

    void drawGrid()
    {
        glColor3f(0.3f, 0.3f, 0.3f);

        glBegin(GL_LINES);

        for (int i = -5;i <= 5;i++)
        {
            glVertex3f(i, 0, -5);
            glVertex3f(i, 0, 5);

            glVertex3f(-5, 0, i);
            glVertex3f(5, 0, i);
        }

        glEnd();
    }

 

    void mousePressEvent(QMouseEvent* event) override
    {
        lastPos = event->position().toPoint();
    }

    void mouseMoveEvent(QMouseEvent* event) override
    {
        int dx = event->position().x() - lastPos.x();
        int dy = event->position().y() - lastPos.y();

        if (event->buttons() & Qt::LeftButton)
        {
            rotX += dy;
            rotY += dx;
        }

        lastPos = event->position().toPoint();
        update();
    }
};

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    GLWidget w;
    w.resize(900, 600);
    w.show();

    return app.exec();
}