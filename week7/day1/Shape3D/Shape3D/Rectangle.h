#pragma once
#include <ParentShape.h>
#include <QPainter>

class Rectangle:public ParentShape
{
public:
	Rectangle(QPoint s, QPoint e);
	void draw(QPainter& painter) override;
};

