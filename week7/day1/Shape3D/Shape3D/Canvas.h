#pragma once

#include <QWidget>
#include <QMouseEvent>
#include "ParentShape.h"

class Canvas : public QWidget
{
    Q_OBJECT

public:
    enum Tool { NO_TOOL, RECTANGLE, CIRCLE };
    enum Mode { NO_MODE, DRAW, EDIT };

    Canvas(QWidget* parent = nullptr);

    void setTool(Tool t);
    void setMode(Mode m);
    void clearShape();

protected:
    void mousePressEvent(QMouseEvent* event) override;
    void mouseMoveEvent(QMouseEvent* event) override;
    void mouseReleaseEvent(QMouseEvent* event) override;
    void paintEvent(QPaintEvent* event) override;

private:
    ParentShape* shape = nullptr;
    QPoint startPoint;

    Tool currentTool = NO_TOOL;
    Mode currentMode = NO_MODE;

    bool isDrawing = false;
    bool isSelected = false;
};