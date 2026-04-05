#include "Shape3D.h"
#include <QVBoxLayout>
#include <QMenuBar>
#include <QAction>

Shape3D::Shape3D(QWidget* parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

    QWidget* central = new QWidget(this);
    setCentralWidget(central);

    canvas = new Canvas(this);

    QVBoxLayout* layout = new QVBoxLayout(central);
    layout->addWidget(canvas);

    setupMenu();
}

Shape3D::~Shape3D() {}

void Shape3D::setupMenu()
{
    QMenuBar* bar = menuBar();

    // DRAW MENU
    QMenu* drawMenu = bar->addMenu("Draw");

    QAction* rect = new QAction("Rectangle", this);
    QAction* circle = new QAction("Circle", this);

    drawMenu->addAction(rect);
    drawMenu->addAction(circle);

    // EDIT MENU
    QMenu* editMenu = bar->addMenu("Edit");

    QAction* editMode = new QAction("Edit Mode", this);
    QAction* clear = new QAction("Clear", this);
    QAction* none = new QAction("None", this);

    editMenu->addAction(editMode);
    editMenu->addAction(clear);
    editMenu->addAction(none);


    //CONNECT SIGNALS

    // Draw Rectangle
    connect(rect, &QAction::triggered, this, [=]() {
        canvas->setMode(Canvas::DRAW);
        canvas->setTool(Canvas::RECTANGLE);
        });

    // Draw Circle
    connect(circle, &QAction::triggered, this, [=]() {
        canvas->setMode(Canvas::DRAW);
        canvas->setTool(Canvas::CIRCLE);
        });

    // Edit Mode
    connect(editMode, &QAction::triggered, this, [=]() {
        canvas->setMode(Canvas::EDIT);
        });

    // Clear
    connect(clear, &QAction::triggered, this, [=]() {
        canvas->clearShape();
        });
    //none mode
    connect(none, &QAction::triggered, this, [=]() {
        canvas->setMode(Canvas::NO_MODE);
        });

}