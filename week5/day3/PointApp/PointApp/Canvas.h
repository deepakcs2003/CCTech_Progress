#pragma once
#include <QTextEdit>

class Canvas : public QTextEdit
{
    Q_OBJECT

public:
    Canvas(QWidget* parent = nullptr);
    ~Canvas();

public slots:
    void showTool(QString tool);
    void showColor(QString color);
};

