#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Shape3D.h"
#include "Canvas.h"

class Shape3D : public QMainWindow
{
    Q_OBJECT

public:
    Shape3D(QWidget* parent = nullptr);
    ~Shape3D();

private:
    Ui::Shape3DClass ui;
    Canvas* canvas;

    void setupMenu();
};