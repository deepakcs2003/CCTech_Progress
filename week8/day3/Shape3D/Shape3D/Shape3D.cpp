#include "Shape3D.h"
#include <QVBoxLayout>
#include <QMenuBar>

Shape3D::Shape3D(QWidget* p) : QMainWindow(p) {
    ui.setupUi(this);

    QWidget* container = new QWidget(this);
    setCentralWidget(container);

    m_canvas = new GLCanvas(this);

    QVBoxLayout* layout = new QVBoxLayout(container);
    layout->setContentsMargins(0, 0, 0, 0);
    layout->addWidget(m_canvas);

    buildMenus();
    setWindowTitle("Shape3D");
    resize(900, 700);
}

void Shape3D::buildMenus() {
    QMenuBar* bar = menuBar();

    // Draw menu
    QMenu* drawMenu = bar->addMenu("Draw");

    QAction* rect = new QAction("Rectangle", this);
    connect(rect, &QAction::triggered, this, [this]() {
        m_canvas->setShapeType(GLCanvas::ShapeType::RECT);
        });
    drawMenu->addAction(rect);

    QAction* square = new QAction("Square", this);
    connect(square, &QAction::triggered, this, [this]() {
        m_canvas->setShapeType(GLCanvas::ShapeType::SQUARE);
        });
    drawMenu->addAction(square);

    QAction* circle = new QAction("Circle", this);
    connect(circle, &QAction::triggered, this, [this]() {
        m_canvas->setShapeType(GLCanvas::ShapeType::CIRCLE);
        });
    drawMenu->addAction(circle);

    // Options menu
    QMenu* optMenu = bar->addMenu("Options");

    // Edit: 2D mein aao, control points drag karo
    QAction* edit = new QAction("Edit", this);
    connect(edit, &QAction::triggered, this, [this]() {
        m_canvas->setMode(GLCanvas::Mode::EDIT);
        });
    optMenu->addAction(edit);

    QAction* none = new QAction("None", this);
    connect(none, &QAction::triggered, this, [this]() {
        m_canvas->setMode(GLCanvas::Mode::NONE);
        });
    optMenu->addAction(none);

    optMenu->addSeparator();

    // 3D View: 2D <-> 3D toggle
    QAction* view3d = new QAction("3D View", this);
    connect(view3d, &QAction::triggered, this, [this]() {
        m_canvas->toggle3DView();
        });
    optMenu->addAction(view3d);

    optMenu->addSeparator();

    QAction* clear = new QAction("Clear", this);
    connect(clear, &QAction::triggered, this, [this]() {
        m_canvas->clearCanvas();
        });
    optMenu->addAction(clear);
}