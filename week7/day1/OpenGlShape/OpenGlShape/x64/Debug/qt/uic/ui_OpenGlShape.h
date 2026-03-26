/********************************************************************************
** Form generated from reading UI file 'OpenGlShape.ui'
**
** Created by: Qt User Interface Compiler version 6.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OPENGLSHAPE_H
#define UI_OPENGLSHAPE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_OpenGlShapeClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *OpenGlShapeClass)
    {
        if (OpenGlShapeClass->objectName().isEmpty())
            OpenGlShapeClass->setObjectName("OpenGlShapeClass");
        OpenGlShapeClass->resize(600, 400);
        menuBar = new QMenuBar(OpenGlShapeClass);
        menuBar->setObjectName("menuBar");
        OpenGlShapeClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(OpenGlShapeClass);
        mainToolBar->setObjectName("mainToolBar");
        OpenGlShapeClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(OpenGlShapeClass);
        centralWidget->setObjectName("centralWidget");
        OpenGlShapeClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(OpenGlShapeClass);
        statusBar->setObjectName("statusBar");
        OpenGlShapeClass->setStatusBar(statusBar);

        retranslateUi(OpenGlShapeClass);

        QMetaObject::connectSlotsByName(OpenGlShapeClass);
    } // setupUi

    void retranslateUi(QMainWindow *OpenGlShapeClass)
    {
        OpenGlShapeClass->setWindowTitle(QCoreApplication::translate("OpenGlShapeClass", "OpenGlShape", nullptr));
    } // retranslateUi

};

namespace Ui {
    class OpenGlShapeClass: public Ui_OpenGlShapeClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OPENGLSHAPE_H
