/********************************************************************************
** Form generated from reading UI file 'dPlace.ui'
**
** Created by: Qt User Interface Compiler version 6.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DPLACE_H
#define UI_DPLACE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_dPlaceClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *dPlaceClass)
    {
        if (dPlaceClass->objectName().isEmpty())
            dPlaceClass->setObjectName("dPlaceClass");
        dPlaceClass->resize(600, 400);
        menuBar = new QMenuBar(dPlaceClass);
        menuBar->setObjectName("menuBar");
        dPlaceClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(dPlaceClass);
        mainToolBar->setObjectName("mainToolBar");
        dPlaceClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(dPlaceClass);
        centralWidget->setObjectName("centralWidget");
        dPlaceClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(dPlaceClass);
        statusBar->setObjectName("statusBar");
        dPlaceClass->setStatusBar(statusBar);

        retranslateUi(dPlaceClass);

        QMetaObject::connectSlotsByName(dPlaceClass);
    } // setupUi

    void retranslateUi(QMainWindow *dPlaceClass)
    {
        dPlaceClass->setWindowTitle(QCoreApplication::translate("dPlaceClass", "dPlace", nullptr));
    } // retranslateUi

};

namespace Ui {
    class dPlaceClass: public Ui_dPlaceClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DPLACE_H
