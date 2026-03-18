#pragma once
#include <QObject>

#include <Qt3DCore/QTransform>
#include <Qt3DCore/QEntity>

#include <Qt3DExtras/QSphereMesh>
#include <Qt3DExtras/QPhongMaterial>
class Sphere : public QObject
{
	Q_OBJECT
public:
    Sphere(Qt3DCore::QEntity* rootEntity);
    ~Sphere();
public slots:
    void enableSphere(bool enabled);

private:
    Qt3DCore::QEntity* m_rootEntity;
    Qt3DCore::QEntity* m_sphereEntity;
};

