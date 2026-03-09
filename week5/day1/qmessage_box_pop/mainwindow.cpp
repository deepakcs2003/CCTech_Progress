#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_warn_btn_clicked()
{
    QMessageBox::warning(this,"warning","send by deepak");
}


void MainWindow::on_error_btn_clicked()
{
    QMessageBox::critical(this,"Error","send by deepak");

}


void MainWindow::on_info_btn_clicked()
{
    QMessageBox::information(this,"infomation","send by deepak");


}


void MainWindow::on_question_btn_clicked()
{
    QMessageBox::StandardButton reply;
    reply=QMessageBox::question(this,"question","send by deepak",QMessageBox::Yes|QMessageBox::No|QMessageBox::Discard);
    if(reply==QMessageBox::Yes){
        ui->label->setText("thanks");
    }

}

