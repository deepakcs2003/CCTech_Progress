#include "loginmain.h"
#include "ui_loginmain.h"

loginMain::loginMain(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::loginMain)
{
    ui->setupUi(this);
}

loginMain::~loginMain()
{
    delete ui;
}
