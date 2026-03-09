#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <cmath>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Shape types
    ui->comboShapeType->addItem("2D");
    ui->comboShapeType->addItem("3D");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_comboShapeType_currentTextChanged(const QString &arg1)
{
    ui->comboShape->clear();

    if(arg1 == "2D"){
        ui->comboShape->addItem("Circle");
        ui->comboShape->addItem("Rectangle");
        ui->comboShape->addItem("Triangle");
    }
    else if(arg1 == "3D"){
        ui->comboShape->addItem("Sphere");
        ui->comboShape->addItem("Cube");
    }
}

void MainWindow::on_comboShape_currentTextChanged(const QString &shape)
{
    if(shape == "Circle"){
        ui->input1_label->setText("Radius");
        ui->input1->show();

        ui->input2_label->hide();
        ui->input2->hide();
    }

    else if(shape == "Rectangle"){
        ui->input1_label->setText("Length");
        ui->input2_label->setText("Width");

        ui->input1->show();
        ui->input2->show();
        ui->input2_label->show();
    }

    else if(shape == "Triangle"){
        ui->input1_label->setText("Base");
        ui->input2_label->setText("Height");

        ui->input1->show();
        ui->input2->show();
        ui->input2_label->show();
    }

    else if(shape == "Sphere"){
        ui->input1_label->setText("Radius");

        ui->input1->show();
        ui->input2_label->hide();
        ui->input2->hide();
    }

    else if(shape == "Cube"){
        ui->input1_label->setText("Side");

        ui->input1->show();
        ui->input2_label->hide();
        ui->input2->hide();
    }
}

void MainWindow::on_pushButton_clicked()
{
    QString shape = ui->comboShape->currentText();

    double a = ui->input1->text().toDouble();
    double b = ui->input2->text().toDouble();

    double result = 0;

    if(shape == "Circle"){
        result = M_PI * a * a;
        ui->labelResult->setText("Area = " + QString::number(result,'f',2));
    }

    else if(shape == "Rectangle"){
        result = a * b;
        ui->labelResult->setText("Area = " + QString::number(result,'f',2));
    }

    else if(shape == "Triangle"){
        result = 0.5 * a * b;
        ui->labelResult->setText("Area = " + QString::number(result,'f',2));
    }

    else if(shape == "Sphere"){
        result = (4.0/3.0) * M_PI * pow(a,3);
        ui->labelResult->setText("Volume = " + QString::number(result,'f',2));
    }

    else if(shape == "Cube"){
        result = pow(a,3);
        ui->labelResult->setText("Volume = " + QString::number(result,'f',2));
    }
}
