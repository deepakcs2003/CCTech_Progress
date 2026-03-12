#pragma once

#include <QtWidgets/QMainWindow>

#include <QComboBox>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
class Sketch3D_Cal : public QMainWindow
{
    Q_OBJECT

public:
    Sketch3D_Cal(QWidget *parent = nullptr);
    ~Sketch3D_Cal();
    void Calculate();

private:
    QComboBox* shapeBox;
    QLineEdit* input1;
    QLineEdit* input2;
    QPushButton* calculate;
    QLabel* result;

};

