#include "Circle.h"
#include <stdexcept>
#include <iostream>
#include "Point.h"
#include <memory>
using namespace std;
double Circle:: pi=3.14;

Circle::Circle(int id, double x,double y, double r) :
	AreaShape(id), center(id,x,y), radius(r)
{
	if (radius <= 0) {
		throw invalid_argument("Radius must me positive");
	}
}

void Circle::move(double dx, double dy)
{
	center.move(dx, dy);
}

void Circle::scale(double factor)
{
	if (factor <= 0) {
		throw invalid_argument("Scale factor must be positive");
	}
	radius*= factor;
}

string Circle::getType() const
{
	return "Circle";
}

void Circle::display() const
{
	cout << "ID: " << getId() << "\n";
	cout << "Type: " << getType() << "\n";
	cout << "Center Point: ("
		<< center.getX() << ", " << center.getY() << ")\n";
	cout << "radius:" << radius << endl;
}

double Circle::area() const
{
	return pi*radius*radius;
}

double Circle::perimeter() const
{
	return 2*pi*radius;
}

bool Circle::contains(const Point& p) const
{
	
	return center.distanceTo(p)<= radius;
}