#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "loginwindow.h"
#include "logindialog.h"
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_login_btn_clicked();

    void on_logic_win_btn_clicked();

    void on_login_dialog_btn_clicked();

private:
    Ui::MainWindow *ui;
    loginDialog *log_dialog;
    loginWindow *login_window;
};

#endif // MAINWINDOW_H
