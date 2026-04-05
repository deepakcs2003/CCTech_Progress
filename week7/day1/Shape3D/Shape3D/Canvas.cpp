#include "Canvas.h"
#include <QPainter>
#include "Rectangle.h"
#include "Circle.h"

Canvas::Canvas(QWidget* parent)
    : QWidget(parent)
{
    setMouseTracking(true);
}

// Set Tool
void Canvas::setTool(Tool t)
{
    currentTool = t;
    isDrawing = false;
}

// Set Mode
void Canvas::setMode(Mode m)
{
    currentMode = m;

    if (currentMode == NO_MODE)
    {
        isDrawing = false;
        isSelected = false;
    }
}

// Clear Shape
void Canvas::clearShape()
{
    if (shape)
    {
        delete shape;
        shape = nullptr;
        update();
    }
}

// Mouse Press
void Canvas::mousePressEvent(QMouseEvent* event)
{
    startPoint = event->pos();

    if (currentMode == NO_MODE)
        return;

    // DRAW MODE
    if (currentMode == DRAW && currentTool != NO_TOOL)
    {
        if (shape != nullptr)
        {
            delete shape;
            shape = nullptr;
        }

        if (currentTool == RECTANGLE)
            shape = new Rectangle(startPoint, startPoint);
        else if (currentTool == CIRCLE)
            shape = new Circle(startPoint, startPoint);

        isDrawing = true;
    }

    // EDIT MODE
    else if (currentMode == EDIT && shape != nullptr)
    {
        isSelected = true;
    }
}

//  Mouse Move
void Canvas::mouseMoveEvent(QMouseEvent* event)
{
    if (shape == nullptr)
        return;

    if (isDrawing)
    {
        shape->setEnd(event->pos());
        update();
    }
    else if (isSelected)
    {
        shape->setEnd(event->pos());
        update();
    }
}

//  Mouse Release
void Canvas::mouseReleaseEvent(QMouseEvent*)
{
    
    if (currentMode == DRAW)
    {
        isDrawing = false;
    }

    
    if (currentMode == EDIT)
    {
        isSelected = false;
    }

}

//  Paint
void Canvas::paintEvent(QPaintEvent*)
{
    QPainter painter(this);

    if (shape != nullptr)
    {
        shape->draw(painter);
    }
}