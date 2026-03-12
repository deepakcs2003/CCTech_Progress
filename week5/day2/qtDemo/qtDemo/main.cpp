#include "qtDemo.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    qtDemo window;
    window.show();
    return app.exec();
}
