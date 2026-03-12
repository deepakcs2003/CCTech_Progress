/********************************************************************************
** Form generated from reading UI file 'qtTest.ui'
**
** Created by: Qt User Interface Compiler version 6.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTTEST_H
#define UI_QTTEST_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_qtTestClass
{
public:
    QWidget *centralWidget;
    QLabel *label;
    QPushButton *pushButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *qtTestClass)
    {
        if (qtTestClass->objectName().isEmpty())
            qtTestClass->setObjectName("qtTestClass");
        qtTestClass->resize(600, 400);
        centralWidget = new QWidget(qtTestClass);
        centralWidget->setObjectName("centralWidget");
        label = new QLabel(centralWidget);
        label->setObjectName("label");
        label->setGeometry(QRect(180, 80, 241, 131));
        QFont font;
        font.setPointSize(26);
        label->setFont(font);
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(210, 50, 131, 41));
        qtTestClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(qtTestClass);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 600, 21));
        qtTestClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(qtTestClass);
        mainToolBar->setObjectName("mainToolBar");
        qtTestClass->addToolBar(Qt::ToolBarArea::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(qtTestClass);
        statusBar->setObjectName("statusBar");
        qtTestClass->setStatusBar(statusBar);

        retranslateUi(qtTestClass);
        QObject::connect(pushButton, &QPushButton::clicked, label, qOverload<>(&QLabel::clear));

        QMetaObject::connectSlotsByName(qtTestClass);
    } // setupUi

    void retranslateUi(QMainWindow *qtTestClass)
    {
        qtTestClass->setWindowTitle(QCoreApplication::translate("qtTestClass", "qtTest", nullptr));
        label->setText(QCoreApplication::translate("qtTestClass", "hello world", nullptr));
        pushButton->setText(QCoreApplication::translate("qtTestClass", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class qtTestClass: public Ui_qtTestClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTTEST_H
