#include "qtTest.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    qtTest window;
    window.show();
    return app.exec();
}
