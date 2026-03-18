#include "Cuboid.h"

#include <Qt3DRender/QGeometryRenderer>

#include <QtGui/QQuaternion>

#include <QtCore/QDebug>

Cuboid::Cuboid(Qt3DCore::QEntity* rootEntity) :m_rootEntity(rootEntity)
{
    Qt3DExtras::QCuboidMesh* cuboid = new Qt3DExtras::QCuboidMesh();

    Qt3DCore::QTransform* cuboidTransform = new Qt3DCore::QTransform();
    cuboidTransform->setScale(4.0f);
    cuboidTransform->setTranslation(QVector3D(5.0f, -4.0f, 0.0f));

    Qt3DExtras::QPhongMaterial* cuboidMaterial = new Qt3DExtras::QPhongMaterial();
    cuboidMaterial->setDiffuse(QColor(QRgb(0x665423)));

   
    m_cuboidEntity = new Qt3DCore::QEntity(m_rootEntity);
    m_cuboidEntity->addComponent(cuboid);
    m_cuboidEntity->addComponent(cuboidMaterial);
    m_cuboidEntity->addComponent(cuboidTransform);
    
}

Cuboid::~Cuboid()
{
}
void Cuboid::enableCuboid(bool enabled)
{
    m_cuboidEntity->setEnabled(enabled);
}