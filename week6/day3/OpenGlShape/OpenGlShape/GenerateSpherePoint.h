#pragma once
#include <vector>
#include <QMatrix4x4>
#include <cmath>

class GenerateSpherePoint
{
private:
    float radius;
    float x, y, z;

    std::vector<float> points; 

    float genCol();

    void applyMatrix(QMatrix4x4& mat);

public: 
    GenerateSpherePoint(float radius, float x, float y, float z);

    std::vector<float> generatePoint();

    std::vector<float> rotateOrigin(float angle, float ax, float ay, float az);
    std::vector<float> rotateSelf(float angle, float ax, float ay, float az);

    std::vector<float> scaleOrigin(float sx, float sy, float sz);
    std::vector<float> scaleSelf(float sx, float sy, float sz);

    std::vector<float> translationOrigin(float dx, float dy, float dz);
    std::vector<float> translationSelf(float dx, float dy, float dz);
};