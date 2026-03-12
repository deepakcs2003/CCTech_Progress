#include "Signal_And_slot.h"

Signal_And_slot::Signal_And_slot(QWidget* parent)
    : QMainWindow(parent)
{
    central = new QWidget();

    mainLayout = new QVBoxLayout();
    menuLayout = new QHBoxLayout();

    btnSignal = new QPushButton("Signal Slot");
    btnAdd = new QPushButton("Add");
    btnMul = new QPushButton("Multiply");

    menuLayout->addWidget(btnSignal);
    menuLayout->addWidget(btnAdd);
    menuLayout->addWidget(btnMul);

    stack = new QStackedWidget();

    createSignalPage();
    createAddPage();
    createMulPage();

    mainLayout->addLayout(menuLayout);
    mainLayout->addWidget(stack);

    central->setLayout(mainLayout);

    setCentralWidget(central);

    connect(btnSignal, &QPushButton::clicked, this, &Signal_And_slot::showSignalPage);
    connect(btnAdd, &QPushButton::clicked, this, &Signal_And_slot::showAddPage);
    connect(btnMul, &QPushButton::clicked, this, &Signal_And_slot::showMulPage);
}

Signal_And_slot::~Signal_And_slot()
{

}

void Signal_And_slot::createSignalPage()
{
    signalPage = new QWidget();

    QVBoxLayout* layout = new QVBoxLayout();

    btn = new QPushButton("Press Button");
    label = new QLabel("Hello");

    layout->addWidget(btn);
    layout->addWidget(label);

    signalPage->setLayout(layout);

    stack->addWidget(signalPage);

    connect(btn, &QPushButton::clicked, label, &QLabel::clear);
}

void Signal_And_slot::createAddPage()
{
    addPage = new QWidget();

    QVBoxLayout* layout = new QVBoxLayout();

    num1 = new QLineEdit();
    num2 = new QLineEdit();

    addBtn = new QPushButton("Add");

    result = new QLabel("Result = ");

    layout->addWidget(new QLabel("Enter First Number"));
    layout->addWidget(num1);

    layout->addWidget(new QLabel("Enter Second Number"));
    layout->addWidget(num2);

    layout->addWidget(addBtn);
    layout->addWidget(result);

    addPage->setLayout(layout);

    stack->addWidget(addPage);

    connect(addBtn, &QPushButton::clicked, this, &Signal_And_slot::calculateSum);
}

void Signal_And_slot::createMulPage()
{
    mulPage = new QWidget();

    QVBoxLayout* layout = new QVBoxLayout();

    mul1 = new QLineEdit();
    mul2 = new QLineEdit();

    mulBtn = new QPushButton("Multiply");

    mulResult = new QLabel("Result = ");

    layout->addWidget(new QLabel("Enter First Number"));
    layout->addWidget(mul1);

    layout->addWidget(new QLabel("Enter Second Number"));
    layout->addWidget(mul2);

    layout->addWidget(mulBtn);
    layout->addWidget(mulResult);

    mulPage->setLayout(layout);

    stack->addWidget(mulPage);

    connect(mulBtn, &QPushButton::clicked, this, &Signal_And_slot::calculateMul);
}

void Signal_And_slot::showSignalPage()
{
    stack->setCurrentWidget(signalPage);
}

void Signal_And_slot::showAddPage()
{
    stack->setCurrentWidget(addPage);
}

void Signal_And_slot::showMulPage()
{
    stack->setCurrentWidget(mulPage);
}

void Signal_And_slot::calculateSum()
{
    double a = num1->text().toDouble();
    double b = num2->text().toDouble();

    double sum = a + b;

    result->setText("Result = " + QString::number(sum));
}

void Signal_And_slot::calculateMul()
{
    double a = mul1->text().toDouble();
    double b = mul2->text().toDouble();

    double mul = a * b;

    mulResult->setText("Result = " + QString::number(mul));
}