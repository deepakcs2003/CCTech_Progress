#include "GenerateEllipsePoint.h"


const double PI = 3.141592653589793238463;    //value of pi

GenerateEllipsePoint::GenerateEllipsePoint(float a, float b, float x, float y) :semi_major(a), semi_minor(b), x(x), y(y)
{
}

std::vector<float> GenerateEllipsePoint::generatePoints()
{
	std::vector<float> points;
	points.push_back(x);
	points.push_back(y);
	points.push_back(getCol());
	points.push_back(getCol());
	points.push_back(getCol());

	int segment = 100;

	for (int i = 0;i < segment;i++) {
		float angle = i * PI * 2.0f / segment;
		float px = x + semi_major * cos(angle);
		float py = y + semi_minor * sin(angle);
		points.push_back(px);
		points.push_back(py);
		points.push_back(getCol());
		points.push_back(getCol());
		points.push_back(getCol());

	}
	return points;

}

float GenerateEllipsePoint::getCol()
{
	float num = (rand() % 101) / 100.0f;
	return num;
}
