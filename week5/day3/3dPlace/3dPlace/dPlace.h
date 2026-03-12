#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_dPlace.h"

namespace Qt3DCore { class QEntity; }
namespace Qt3DRender { class QCamera; }
namespace Qt3DExtras { class Qt3DWindow; }

class dPlace : public QMainWindow
{
    Q_OBJECT

public:
    dPlace(QWidget *parent = nullptr);
    ~dPlace();

private:
    void setup3DScene();
    Ui::dPlaceClass ui;
    Qt3DExtras::Qt3DWindow* view;
    Qt3DCore::QEntity* rootEntity;
};

