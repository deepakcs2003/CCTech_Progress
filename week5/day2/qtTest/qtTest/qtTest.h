#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_qtTest.h"

class qtTest : public QMainWindow
{
    Q_OBJECT

public:
    qtTest(QWidget *parent = nullptr);
    ~qtTest();

private:
    Ui::qtTestClass ui;
};

