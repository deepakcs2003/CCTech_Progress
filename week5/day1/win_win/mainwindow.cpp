#include "mainwindow.h"
#include "ui_mainwindow.h"

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

void MainWindow::on_login_btn_clicked() {

}

void MainWindow::on_logic_win_btn_clicked()
{
    hide();
    login_window=new loginWindow(this);
    login_window->show();

}


void MainWindow::on_login_dialog_btn_clicked()
{
    hide();
    log_dialog=new loginDialog(this);
    log_dialog->show();

}

