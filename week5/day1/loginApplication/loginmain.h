#ifndef LOGINMAIN_H
#define LOGINMAIN_H

#include <QMainWindow>

namespace Ui {
class loginMain;
}

class loginMain : public QMainWindow
{
    Q_OBJECT

public:
    explicit loginMain(QWidget *parent = nullptr);
    ~loginMain();

private:
    Ui::loginMain *ui;
};

#endif // LOGINMAIN_H
