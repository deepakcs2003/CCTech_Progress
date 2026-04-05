#include "Rectangle.h"

Rectangle::Rectangle(QPoint s, QPoint e) :ParentShape(s, e)
{
}

void Rectangle::draw(QPainter& painter)
{
	int x = std::min(start.x(), end.x());
	int y = std::min(start.y(), end.y());
	int w = abs(start.x() - end.x());
	int h = abs(start.y() - end.y());
	painter.drawRect(x, y, w, h);
}
