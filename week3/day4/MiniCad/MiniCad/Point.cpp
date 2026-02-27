#include "Point.h"
#include "Shape.h"
#include <stdexcept>
#include <iostream>
using namespace std;

Point::Point(int id, double x, double y) :
	Shape(id), x(x), y(y)
{

}

void Point::move(double dx, double dy)
{
	x += dx;
	y += dy;
}

void Point::scale(double factor)
{
	if (factor <= 0) {
		throw  invalid_argument("Invalid scale factor");
	}
	x *= factor;
	y *= factor;
}

string Point::getType() const
{
	return "Point";
}

void Point::display() const
{
	cout << "point" << "(" << x<<"," << y << ")" << endl;
}

double Point::getX() const
{
	return x;
}

double Point::getY() const
{
	return y;
}

double Point::distanceTo(const Point& other) const
{
	double a = (x - other.x);
	double b = (y - other.y);
	double c = a * a + b * b;
	double distance = sqrt(c);
	return distance;
}
