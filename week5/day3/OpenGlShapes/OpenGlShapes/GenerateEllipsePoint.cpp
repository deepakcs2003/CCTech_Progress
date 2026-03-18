#include "GenerateEllipsePoint.h"


const double PI = 3.141592653589793238463;    //value of pi

GenerateEllipsePoint::GenerateEllipsePoint(float a, float b,float x ,float y) :semi_major(a),semi_minor(b),x(x),y(y)
{
}

std::vector<float> GenerateEllipsePoint::generatePoints()
{
	std::vector<float> points;
	int segment = 100;

	for (int i = 0;i < segment;i++) {
		float angle = i * PI * 2.0f / segment;
		float px =x+semi_major * cos(angle);
		float py =y+semi_minor * sin(angle);
		points.push_back(px);
		points.push_back(py);
	}
	return points;

}
