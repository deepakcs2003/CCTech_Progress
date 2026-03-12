#include "Sketch3D_Cal.h"

#include <QVBoxLayout>
#include <QLabel>
Sketch3D_Cal::Sketch3D_Cal(QWidget *parent)
    : QMainWindow(parent)
{

    setWindowTitle("shape calculator");

    QWidget* central = new QWidget();
    setCentralWidget(central);

    shapeBox = new QComboBox();
    shapeBox->addItem("Circle");
    shapeBox->addItem("Rectangle");
    shapeBox->addItem("Cube");
    shapeBox->addItem("Cuboid");

    input1 = new QLineEdit();
    input1->setPlaceholderText("enter the value1");

    input2 = new QLineEdit();
    input2->setPlaceholderText("enter the value1");

    calculate = new QPushButton("Calculate");
    result = new QLabel("Result: ");

    QVBoxLayout* layout = new QVBoxLayout;

    layout->addWidget(new QLabel("Select shape: "));
    layout->addWidget(shapeBox);

    layout->addWidget(new QLabel("value 1: "));
    layout->addWidget(input1);

    layout->addWidget(new QLabel("value 2: "));
    layout->addWidget(input2);

    layout->addWidget(calculate);
    layout->addWidget(result);


    central->setLayout(layout);


    connect(calculate, &QPushButton::clicked, this, &Sketch3D_Cal::Calculate);
}

Sketch3D_Cal::~Sketch3D_Cal()
{}

void Sketch3D_Cal::Calculate()
{
    QString shape = shapeBox->currentText();
    double i1 = input1->text().toDouble();
    double i2 = input2->text().toDouble();

    double ans = 0;
    if (shape == "Circle") {
        i2 = 1;
        ans = 3.14 * i1 * i2;
        result->setText("Area = " + QString::number(ans));
    }
    else if (shape == "Rectangle") {
        ans = i1 * i2;
        result->setText("Area = " + QString::number(ans));
    }
    else if (shape == "Cube") {
        ans = 6* i1 * i2;
        result->setText("Area = " + QString::number(ans));
    }
    else if (shape == "Cuboid") {
        double face = i1 * i2;
        ans = 2*(3*face);
        result->setText("Area = " + QString::number(ans));
    }
}


