#include "PointApp.h"
#include "ToolBox.h"
#include "Canvas.h"
#include "ColorBar.h"

#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QTextEdit>
#include <QMenuBar>
#include <QStatusBar>
#include <QMessageBox>

#include <QFileDialog>
#include <QFile>
#include <QTextStream>

#include <QApplication>


PointApp::PointApp(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle("DPoint");
    resize(900, 600);

    createMenu();
    createLayout();
}

PointApp::~PointApp()
{}


// for file i use this :https://zetcode.com/gui/qt5/files/
void PointApp::newFile()
{
    QMessageBox::StandardButtons reply;
    //if (!currentFile.isEmpty()) {
    //    canvas->clear();
    //}
    //else {
    //    reply = QMessageBox::question(
    //        this,
    //        "New file",
    //        "Save before closing?",
    //        QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel
    //    );
    //    if (reply == QMessageBox::Yes) {
    //        saveFile();
    //        canvas->clear();
    //    }
    //    else if (reply == QMessageBox::No) {
    //        canvas->clear();
    //    }
    //}

    reply = QMessageBox::question(
        this,
        "New file",
        "Save before closing?",
        QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel
    );
    if (reply == QMessageBox::Yes) {
        saveFile();
        canvas->clear();
    }
    else if (reply == QMessageBox::No) {
        canvas->clear();
    }
    
}

void PointApp::openFile()
{
    QString filename = QFileDialog::getOpenFileName(
        this,
        "open file",
        "",
        "Text Files (*.txt)"
    );
    if (filename.isEmpty()) {
        return;
    }
    QFile file(filename);
    if (file.open(QIODevice::ReadOnly| QIODevice::Text)) {
        QTextStream in(&file);
        canvas->setText(in.readAll());
        file.close();

        currentFile = filename;
    }
}

void PointApp::saveFile()
{
    QString filename;
    if (currentFile.isEmpty()) {
        filename = QFileDialog::getSaveFileName(
            this,
            "Save file",
            "",
            "Text Files(*.txt)"
        );
    }
    else {
        filename = currentFile;
    }
    if (filename.isEmpty()) {
        return;
    }
    QFile file(filename);

    if (file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QTextStream out(&file);
        out << canvas->toPlainText();
        file.close();

        currentFile = filename;
    }

}

void PointApp::exitApp()
{
    QApplication::quit();

}

void PointApp::createMenu()
{
    //resource i use:https://doc.qt.io/qt-6/qtwidgets-mainwindows-menus-example.html
    //https://zetcode.com/gui/qt5/menusandtoolbars/

    QMenu* file = menuBar()->addMenu("&file");

    QAction* newAct = file->addAction("New");
    QAction* openAct = file->addAction("Open");
    QAction* saveAct = file->addAction("Save");
    file->addAction("Print");
    QAction* exitAct = file->addAction("Exit");

    connect(newAct, &QAction::triggered, this, &PointApp::newFile);
    connect(openAct, &QAction::triggered, this, &PointApp::openFile);
    connect(saveAct, &QAction::triggered, this, &PointApp::saveFile);
    connect(exitAct, &QAction::triggered, this, &PointApp::exitApp);

    QMenu* edit = menuBar()->addMenu("edit");
    edit->addAction("Undo");
    edit->addAction("Cut");
    edit->addAction("Copy");
    edit->addAction("Paste");

    menuBar()->addMenu("View");
    menuBar()->addMenu("Image");
    menuBar()->addMenu("Colors");
    menuBar()->addMenu("Help");

}

void PointApp::createLayout()
{

    QWidget* central = new QWidget;
    setCentralWidget(central);

    QVBoxLayout *mainLayout = new QVBoxLayout();
    QHBoxLayout *workspaceLayout = new QHBoxLayout();
    

    toolBox = new ToolBox;
    canvas = new Canvas;

    workspaceLayout->addWidget(toolBox);
    workspaceLayout->addWidget(canvas);

    colorBar = new ColorBar;

    mainLayout->addLayout(workspaceLayout);
    mainLayout->addWidget(colorBar);

    central->setLayout(mainLayout);

    connect(colorBar, &ColorBar::colorSelected, canvas, &Canvas::showColor);
    connect(toolBox, &ToolBox::toolSelected,canvas, &Canvas::showTool);
    statusBar()->showMessage("Ready");

}




