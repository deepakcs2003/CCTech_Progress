#include "Circle.h"


 double Circle:: pi=3.14;


Circle::Circle(string name, double radius, double x, double y) :
	shape(name), radius(radius), x(x), y(y)
{
}

void Circle::display()
{
	cout << name<<"(" << "radius: " << radius
		<< ",center of cicle:(" << x << " , " << y << "))" << endl;
}

double Circle::area()
{
	return radius*radius*3.14;
}
