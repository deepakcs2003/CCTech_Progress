#include <QApplication>
#include "dPlace.h"

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);
    dPlace w;
    w.show();
    return app.exec();
}