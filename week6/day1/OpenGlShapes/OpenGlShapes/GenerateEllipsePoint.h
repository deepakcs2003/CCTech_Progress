#pragma once
#include <vector>
class GenerateEllipsePoint
{
private:
	float semi_major;
	float semi_minor;
	float x;
	float y;
public:
	GenerateEllipsePoint(float a, float b,float x,float y);
	std::vector<float> generatePoints();
};

