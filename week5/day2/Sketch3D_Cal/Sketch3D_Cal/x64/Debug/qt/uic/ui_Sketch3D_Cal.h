/********************************************************************************
** Form generated from reading UI file 'Sketch3D_Cal.ui'
**
** Created by: Qt User Interface Compiler version 6.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SKETCH3D_CAL_H
#define UI_SKETCH3D_CAL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Sketch3D_CalClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Sketch3D_CalClass)
    {
        if (Sketch3D_CalClass->objectName().isEmpty())
            Sketch3D_CalClass->setObjectName("Sketch3D_CalClass");
        Sketch3D_CalClass->resize(600, 400);
        menuBar = new QMenuBar(Sketch3D_CalClass);
        menuBar->setObjectName("menuBar");
        Sketch3D_CalClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Sketch3D_CalClass);
        mainToolBar->setObjectName("mainToolBar");
        Sketch3D_CalClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(Sketch3D_CalClass);
        centralWidget->setObjectName("centralWidget");
        Sketch3D_CalClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(Sketch3D_CalClass);
        statusBar->setObjectName("statusBar");
        Sketch3D_CalClass->setStatusBar(statusBar);

        retranslateUi(Sketch3D_CalClass);

        QMetaObject::connectSlotsByName(Sketch3D_CalClass);
    } // setupUi

    void retranslateUi(QMainWindow *Sketch3D_CalClass)
    {
        Sketch3D_CalClass->setWindowTitle(QCoreApplication::translate("Sketch3D_CalClass", "Sketch3D_Cal", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Sketch3D_CalClass: public Ui_Sketch3D_CalClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SKETCH3D_CAL_H
