/********************************************************************************
** Form generated from reading UI file 'Shape3D.ui'
**
** Created by: Qt User Interface Compiler version 6.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SHAPE3D_H
#define UI_SHAPE3D_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Shape3DClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Shape3DClass)
    {
        if (Shape3DClass->objectName().isEmpty())
            Shape3DClass->setObjectName("Shape3DClass");
        Shape3DClass->resize(600, 400);
        menuBar = new QMenuBar(Shape3DClass);
        menuBar->setObjectName("menuBar");
        Shape3DClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Shape3DClass);
        mainToolBar->setObjectName("mainToolBar");
        Shape3DClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(Shape3DClass);
        centralWidget->setObjectName("centralWidget");
        Shape3DClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(Shape3DClass);
        statusBar->setObjectName("statusBar");
        Shape3DClass->setStatusBar(statusBar);

        retranslateUi(Shape3DClass);

        QMetaObject::connectSlotsByName(Shape3DClass);
    } // setupUi

    void retranslateUi(QMainWindow *Shape3DClass)
    {
        Shape3DClass->setWindowTitle(QCoreApplication::translate("Shape3DClass", "Shape3D", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Shape3DClass: public Ui_Shape3DClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHAPE3D_H
