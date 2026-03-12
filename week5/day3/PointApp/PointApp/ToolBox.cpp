#include "ToolBox.h"
#include <QVBoxLayout>
#include <QToolButton>
#include <QIcon>

ToolBox::ToolBox(QWidget* parent): QWidget(parent)
{
	createTools();
}

ToolBox::~ToolBox()
{
}

void ToolBox::createTools()
{
    QVBoxLayout* layout = new QVBoxLayout;

    struct Tool {
        QString name;
        QString icon;
    };

    QList<Tool> tools{
        {"Select", ":/icons/icons/select.svg"},
        {"Pencil", ":/icons/icons/pencil.svg"},
        {"Eraser", ":/icons/icons/eraser.svg"},
        {"Brush", ":/icons/icons/brush.svg"},
        {"Fill", ":/icons/icons/fill.svg"},
        {"Text", ":/icons/icons/text.svg"},
        {"Line", ":/icons/icons/line.svg"},
        {"Rectangle", ":/icons/icons/rectangle.svg"},
        {"Circle", ":/icons/icons/circle.svg"}
    };
    for (auto tool : tools) {
        QToolButton* btn = new QToolButton;
        btn->setIcon(QIcon(tool.icon));
        btn->setIconSize(QSize(28, 28));
        btn->setToolTip(tool.name);

        connect(btn, &QToolButton::clicked, this, [=]() {
            emit toolSelected(tool.name);
            });

        layout->addWidget(btn);
    }
    layout->addStretch();
    setLayout(layout);

};
