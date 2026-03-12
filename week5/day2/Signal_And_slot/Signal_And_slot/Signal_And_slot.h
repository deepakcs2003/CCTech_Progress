#pragma once

#include <QtWidgets/QMainWindow>
#include <QPushButton>
#include <QStackedWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QWidget>
#include <QLineEdit>
#include <QLabel>

class Signal_And_slot : public QMainWindow
{
    Q_OBJECT

public:
    Signal_And_slot(QWidget* parent = nullptr);
    ~Signal_And_slot();

private:

    QWidget* central;
    QVBoxLayout* mainLayout;
    QHBoxLayout* menuLayout;

    QPushButton* btnSignal;
    QPushButton* btnAdd;
    QPushButton* btnMul;

    QStackedWidget* stack;

    QWidget* signalPage;
    QWidget* addPage;
    QWidget* mulPage;

    QPushButton* btn;
    QLabel* label;

    QLineEdit* num1;
    QLineEdit* num2;
    QLabel* result;
    QPushButton* addBtn;

    QLineEdit* mul1;
    QLineEdit* mul2;
    QLabel* mulResult;
    QPushButton* mulBtn;

    void createSignalPage();
    void createAddPage();
    void createMulPage();

private slots:

    void showSignalPage();
    void showAddPage();
    void showMulPage();

    void calculateSum();
    void calculateMul();
};