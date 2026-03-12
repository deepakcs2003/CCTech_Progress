#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_qtDemo.h"

class qtDemo : public QMainWindow
{
    Q_OBJECT

public:
    qtDemo(QWidget *parent = nullptr);
    ~qtDemo();

private:
    Ui::qtDemoClass ui;
};

