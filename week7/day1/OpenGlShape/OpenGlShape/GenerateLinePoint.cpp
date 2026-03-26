#include "GenerateLinePoint.h"

GenerateLinePoint::GenerateLinePoint(float m, float c) :slope(m), contant(c)
{
}

std::vector<float> GenerateLinePoint::generatePoint()
{
	std::vector<float> points;
	float x = 0;
	float length = 10;
	while (x < length) {
		float y = x * slope + contant;
		points.push_back(x);
		points.push_back(y);
		points.push_back(getCol());
		points.push_back(getCol());
		points.push_back(getCol());

		x += 0.1;
	}
	return points;

}

float GenerateLinePoint::getCol()
{
	float col = (rand() % 101) / 100.0f;
	return col;
}
