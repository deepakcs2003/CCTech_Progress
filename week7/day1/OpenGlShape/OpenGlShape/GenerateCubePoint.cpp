#include "GenerateCubePoint.h"

GenerateCubePoint::GenerateCubePoint(float length, float x, float y, float z) :length(length), x(x), y(y), z(z)
{
}

std::vector<float> GenerateCubePoint::generatePoint()
{
    std::vector<float> v;

    float s = length;
    auto add = [&](float x, float y, float z) {
        v.push_back(x);
        v.push_back(y);
        v.push_back(z);

        // random color
        v.push_back((rand() % 101) / 100.0f);
        v.push_back((rand() % 101) / 100.0f);
        v.push_back((rand() % 101) / 100.0f);
        };

    // FRONT
    add(-s, -s, s); add(s, -s, s); add(s, s, s);
    add(-s, -s, s); add(s, s, s); add(-s, s, s);

    // BACK
    add(-s, -s, -s); add(s, s, -s); add(s, -s, -s);
    add(-s, -s, -s); add(-s, s, -s); add(s, s, -s);

    // LEFT
    add(-s, -s, -s); add(-s, -s, s); add(-s, s, s);
    add(-s, -s, -s); add(-s, s, s); add(-s, s, -s);

    // RIGHT
    add(s, -s, -s); add(s, s, s); add(s, -s, s);
    add(s, -s, -s); add(s, s, -s); add(s, s, s);

    // TOP
    add(-s, s, -s); add(-s, s, s); add(s, s, s);
    add(-s, s, -s); add(s, s, s); add(s, s, -s);

    // BOTTOM
    add(-s, -s, -s); add(s, -s, s); add(-s, -s, s);
    add(-s, -s, -s); add(s, -s, -s); add(s, -s, s);

    return v;
}

float GenerateCubePoint::genCol()
{
	float num = (rand() % 101) / 100.0f;
	return num;
}