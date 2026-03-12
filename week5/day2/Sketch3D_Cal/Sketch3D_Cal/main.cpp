#include "Sketch3D_Cal.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    Sketch3D_Cal window;
    window.show();
    return app.exec();
}
