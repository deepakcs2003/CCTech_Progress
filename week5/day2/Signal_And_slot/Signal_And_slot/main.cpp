#include "Signal_And_slot.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    Signal_And_slot window;
    window.show();
    return app.exec();
}
