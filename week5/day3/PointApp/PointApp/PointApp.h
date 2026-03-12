#pragma once

#include <QtWidgets/QMainWindow>
#include "ToolBox.h"
#include "ColorBar.h"
#include "Canvas.h"

class PointApp : public QMainWindow
{
    Q_OBJECT

public:
    PointApp(QWidget *parent = nullptr);
    ~PointApp();

private slots:

    void newFile();
    void openFile();
    void saveFile();
    void exitApp();

private:
    void createMenu();
    void createLayout();
    ToolBox *toolBox;
    ColorBar *colorBar;
    Canvas *canvas;

    QString currentFile;

};

