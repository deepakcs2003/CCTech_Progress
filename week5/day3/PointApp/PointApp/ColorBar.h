#pragma once
#include <QWidget>

class ColorBar : public QWidget
{
    Q_OBJECT

public:
    ColorBar(QWidget* parent = nullptr);
    ~ColorBar();
signals:
    void colorSelected(QString color);
private:
    void createColors();
};
