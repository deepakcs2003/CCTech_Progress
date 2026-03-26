#include "GenerateLinePoint.h"

GenerateLinePoint::GenerateLinePoint(float m, float c) :slope(m), contant(c)
{
}

std::vector<float> GenerateLinePoint::generatePoint()
{
	std::vector<float> points;
	float x = 0;
	float length=10;
	while (x < length) {
		float y = x * slope + contant;
		points.push_back(x);
		points.push_back(y);
		x += 0.1;
	}
	return points;
	
}
