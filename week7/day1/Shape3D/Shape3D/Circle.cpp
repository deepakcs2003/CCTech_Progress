#include "Circle.h"

Circle::Circle(QPoint s, QPoint e):ParentShape(s,e)
{
}

void Circle::draw(QPainter& painter)
{
    int w = abs(start.x() - end.x());
    int h = abs(start.y() - end.y());
    int d = std::min(w, h);
    int x = std::min(start.x(), end.x());
    int y = std::min(start.y(), end.y());

    painter.drawEllipse(x, y, d, d);
}
