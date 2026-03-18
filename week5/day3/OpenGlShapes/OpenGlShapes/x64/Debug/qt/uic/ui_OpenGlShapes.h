/********************************************************************************
** Form generated from reading UI file 'OpenGlShapes.ui'
**
** Created by: Qt User Interface Compiler version 6.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OPENGLSHAPES_H
#define UI_OPENGLSHAPES_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_OpenGlShapesClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *OpenGlShapesClass)
    {
        if (OpenGlShapesClass->objectName().isEmpty())
            OpenGlShapesClass->setObjectName("OpenGlShapesClass");
        OpenGlShapesClass->resize(600, 400);
        menuBar = new QMenuBar(OpenGlShapesClass);
        menuBar->setObjectName("menuBar");
        OpenGlShapesClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(OpenGlShapesClass);
        mainToolBar->setObjectName("mainToolBar");
        OpenGlShapesClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(OpenGlShapesClass);
        centralWidget->setObjectName("centralWidget");
        OpenGlShapesClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(OpenGlShapesClass);
        statusBar->setObjectName("statusBar");
        OpenGlShapesClass->setStatusBar(statusBar);

        retranslateUi(OpenGlShapesClass);

        QMetaObject::connectSlotsByName(OpenGlShapesClass);
    } // setupUi

    void retranslateUi(QMainWindow *OpenGlShapesClass)
    {
        OpenGlShapesClass->setWindowTitle(QCoreApplication::translate("OpenGlShapesClass", "OpenGlShapes", nullptr));
    } // retranslateUi

};

namespace Ui {
    class OpenGlShapesClass: public Ui_OpenGlShapesClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OPENGLSHAPES_H
