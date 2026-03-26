#include "GenerateCirclePoint.h"
#include<cmath>

const double PI = 3.141592653589793238463;    //value of pi

GenerateCirclePoint::GenerateCirclePoint(float radius, float x,float y) :radius(radius), x(x),y(y)
{
}

std::vector<float> GenerateCirclePoint::generatePoint()
{
	std::vector<float> points;
	int segment = 100;

	for (int i = 0;i < segment;i++) {
		float angle = i * PI * 2 / segment;
		float px =x+ radius * cos(angle);
		float py =y+ radius * sin(angle);
		points.push_back(px);
		points.push_back(py);
	}
	return points;
}
