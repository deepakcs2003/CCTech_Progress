#pragma once

#include <QObject>
#include <Qt3DCore/QEntity>
#include <Qt3DCore/QTransform>

#include <Qt3DExtras/QCuboidMesh>
#include <Qt3DExtras/QPhongMaterial>

class Cuboid : public QObject
{
    Q_OBJECT

public:
    Cuboid(Qt3DCore::QEntity* rootEntity);
    ~Cuboid();

public slots:
    void enableCuboid(bool enabled);

private:
    Qt3DCore::QEntity* m_rootEntity;
    Qt3DCore::QEntity* m_cuboidEntity;
};