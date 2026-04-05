#pragma once
#include <QtWidgets/QMainWindow>
#include "ui_Shape3D.h"
#include "GLCanvas.h"

class Shape3D : public QMainWindow {
    Q_OBJECT

public:
    Shape3D(QWidget* parent = nullptr);

private:
    void buildMenus(); 

    Ui::Shape3DClass ui;
    GLCanvas* m_canvas = nullptr;
};