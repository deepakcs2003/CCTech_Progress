#include "Shape3D.h"
#include <QtWidgets/QApplication>
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    Shape3D window;
    window.show();

    //Canvas canvas;
    //canvas.resize(800, 600);
    //canvas.show();
    return app.exec();
}
