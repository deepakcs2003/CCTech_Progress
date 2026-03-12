#include "Canvas.h"

Canvas::Canvas(QWidget* parent) :QTextEdit(parent)
{
	setText("Canvas Arear");
}

Canvas::~Canvas()
{
}

void Canvas::showTool(QString tool)
{
	append("Tool Selected : " + tool);
}


void Canvas::showColor(QString color)
{
	append("color Selected: " + color);
}
