#pragma once
#include <ParentShape.h>
#include <QPainter>

class Circle:public ParentShape
{
public:
	Circle(QPoint s, QPoint e);
	void draw(QPainter& painter) override;
};

