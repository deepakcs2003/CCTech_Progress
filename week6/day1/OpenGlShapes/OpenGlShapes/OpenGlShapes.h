#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_OpenGlShapes.h"

class OpenGlShapes : public QMainWindow
{
    Q_OBJECT

public:
    OpenGlShapes(QWidget *parent = nullptr);
    ~OpenGlShapes();

private:
    Ui::OpenGlShapesClass ui;
};

