/********************************************************************************
** Form generated from reading UI file 'Qt_OpenGL.ui'
**
** Created by: Qt User Interface Compiler version 6.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QT_OPENGL_H
#define UI_QT_OPENGL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Qt_OpenGLClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Qt_OpenGLClass)
    {
        if (Qt_OpenGLClass->objectName().isEmpty())
            Qt_OpenGLClass->setObjectName("Qt_OpenGLClass");
        Qt_OpenGLClass->resize(600, 400);
        menuBar = new QMenuBar(Qt_OpenGLClass);
        menuBar->setObjectName("menuBar");
        Qt_OpenGLClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Qt_OpenGLClass);
        mainToolBar->setObjectName("mainToolBar");
        Qt_OpenGLClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(Qt_OpenGLClass);
        centralWidget->setObjectName("centralWidget");
        Qt_OpenGLClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(Qt_OpenGLClass);
        statusBar->setObjectName("statusBar");
        Qt_OpenGLClass->setStatusBar(statusBar);

        retranslateUi(Qt_OpenGLClass);

        QMetaObject::connectSlotsByName(Qt_OpenGLClass);
    } // setupUi

    void retranslateUi(QMainWindow *Qt_OpenGLClass)
    {
        Qt_OpenGLClass->setWindowTitle(QCoreApplication::translate("Qt_OpenGLClass", "Qt_OpenGL", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Qt_OpenGLClass: public Ui_Qt_OpenGLClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QT_OPENGL_H
