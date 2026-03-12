#pragma once
#include <QWidget>

class ToolBox : public QWidget
{
    Q_OBJECT

public:

    ToolBox(QWidget* parent = nullptr);
    ~ToolBox();

signals:
    void toolSelected(QString tool);

private:
    void createTools();
};

