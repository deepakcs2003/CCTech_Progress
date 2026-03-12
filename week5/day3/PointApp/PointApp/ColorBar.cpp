#include "ColorBar.h"
#include <QHBoxLayout>
#include <QPushButton>
//#include <QPainter>

ColorBar::ColorBar(QWidget* parent):QWidget(parent)
{
	createColors();
}

ColorBar::~ColorBar()
{
   
}

void ColorBar::createColors()
{
    QHBoxLayout* layout = new QHBoxLayout;
    //QPainter painter(this);
    QStringList colors = {
        "black","white","red","green","blue",
        "yellow","cyan","magenta","gray",
        "orange","purple","brown"
    };
    for (QString c : colors)
    {
        QPushButton* btn = new QPushButton;
        btn->setFixedSize(40, 40);
        btn->setStyleSheet("background:" + c);

        connect(btn, &QPushButton::clicked, [=]() {
            emit colorSelected(c);
            });
        layout->addWidget(btn);
    }

    layout->addStretch();

    setLayout(layout);
}
