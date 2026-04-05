#pragma once
#include <qwidget.h>
#include <QPoint>
class ParentShape
{
protected:
	QPoint start;
	QPoint end;
public:
	ParentShape(QPoint s,QPoint e);
	virtual ~ParentShape();
	virtual void draw(QPainter& painter) = 0;
	void setEnd(QPoint e);
};

