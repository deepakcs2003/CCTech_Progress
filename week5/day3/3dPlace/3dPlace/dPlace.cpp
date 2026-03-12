#include "dPlace.h"
#include <QColor>
#include <QVector3D>
#include <Qt3DExtras/Qt3DWindow>
#include <Qt3DCore/QEntity>
#include <Qt3DExtras/QPlaneMesh>
#include <Qt3DExtras/QCuboidMesh>
#include <Qt3DExtras/QPhongMaterial>
#include <Qt3DCore/QTransform>
#include <Qt3DRender/QCamera>

dPlace::dPlace(QWidget *parent)
    : QMainWindow(parent), view(nullptr), rootEntity(nullptr)
{
    ui.setupUi(this);
    setup3DScene();
}

dPlace::~dPlace()
{}

void dPlace::setup3DScene()
{
    // 3D window
    view = new Qt3DExtras::Qt3DWindow();
    view->defaultFrameGraph()->setClearColor(QColor(50, 50, 50));

    QWidget* container = QWidget::createWindowContainer(view);
    setCentralWidget(container);
    resize(800, 600);

    // Root entity
    rootEntity = new Qt3DCore::QEntity();

    // ----------- Plane -------------
    Qt3DExtras::QPlaneMesh* planeMesh = new Qt3DExtras::QPlaneMesh();
    planeMesh->setWidth(20);
    planeMesh->setHeight(20);

    Qt3DCore::QEntity* planeEntity = new Qt3DCore::QEntity(rootEntity);

    Qt3DCore::QTransform* planeTransform = new Qt3DCore::QTransform();
    planeTransform->setRotationX(-90);

    Qt3DExtras::QPhongMaterial* planeMaterial = new Qt3DExtras::QPhongMaterial();
    planeMaterial->setDiffuse(QColor(150, 150, 150));

    planeEntity->addComponent(planeMesh);
    planeEntity->addComponent(planeTransform);
    planeEntity->addComponent(planeMaterial);

    // ----------- Cube (Shape) -------------
    Qt3DExtras::QCuboidMesh* cubeMesh = new Qt3DExtras::QCuboidMesh();

    Qt3DCore::QEntity* cubeEntity = new Qt3DCore::QEntity(rootEntity);

    Qt3DCore::QTransform* cubeTransform = new Qt3DCore::QTransform();
    cubeTransform->setTranslation(QVector3D(0, 1, 0));

    Qt3DExtras::QPhongMaterial* cubeMaterial = new Qt3DExtras::QPhongMaterial();
    cubeMaterial->setDiffuse(QColor(255, 0, 0));

    cubeEntity->addComponent(cubeMesh);
    cubeEntity->addComponent(cubeTransform);
    cubeEntity->addComponent(cubeMaterial);

    // ----------- Camera -------------
    Qt3DRender::QCamera* camera = view->camera();
    camera->lens()->setPerspectiveProjection(45.0f, 16.0f / 9.0f, 0.1f, 1000.0f);
    camera->setPosition(QVector3D(0, 10, 20));
    camera->setViewCenter(QVector3D(0, 0, 0));

    view->setRootEntity(rootEntity);
}

