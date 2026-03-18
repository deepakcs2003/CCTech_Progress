#include "OpenGlShapes.h"
#include <QtWidgets/QApplication>
#include <GenerateCirclePoint.h>
#include <QDebug>
#include <vector>
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    OpenGlShapes window;
    window.show();
    GenerateCirclePoint circlePoints(3.0, 2.1, 2.4);
    std::vector<float>points=circlePoints.generatePoint();
    for (int i = 0; i < points.size(); i += 2) {
        qDebug() << points[i] << points[i + 1];
    }
    return app.exec();
}
