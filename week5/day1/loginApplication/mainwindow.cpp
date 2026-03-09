#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
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

void MainWindow::on_login_btn_clicked()
{
    QString username=ui->lineEdit_user->text();
    QString password=ui->lineEdit_password->text();
    login_main=new loginMain(this);
    if(username=="deepak" && password=="deepak@1234"){
        login_main->show();
    }else{
        QMessageBox::critical(this,"login failed","username or password is incorrect");
    }
}

