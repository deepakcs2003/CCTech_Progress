#include "Triangle.h"
#include "AreaShape.h"
#include "Point.h"
#include <stdexcept>
#include <iostream>
using namespace std;


Triangle::Triangle(int id, double x1, double y1, double x2, double y2, double x3, double y3) :
	AreaShape(id), p1(id, x1, y1), p2(id, x2, y2), p3(id, x3, y3)
{
}

void Triangle::move(double dx, double dy)
{
	p1.move(dx, dy);
	p2.move(dx, dy);
	p3.move(dx, dy);

}

void Triangle::scale(double factor)
{
	if (factor <= 0) {
		throw invalid_argument("Scale factor must be positive");
	}
	p1.scale(factor);
	p2.scale(factor);
	p3.scale(factor);


}

std::string Triangle::getType() const
{
	return "Triangle";
}

void Triangle::display() const
{
	cout << "ID: " << getId() << "\n";
	cout << "Type: " << getType() << "\n";
	cout << " Point1: ("
		<< p1.getX() << ", " << p1.getY() << ")\n";

	cout << "Point2: ("
		<< p2.getX() << ", " << p2.getY() << ")\n";

    cout << "Point3: ("
        << p3.getX() << ", " << p3.getY() << ")\n";

}

double Triangle::area() const
{
	double x1 = p1.getX();
	double y1 = p1.getY();

	double x2 = p2.getX();
	double y2 = p2.getY();

	double x3 = p3.getX();
	double y3 = p3.getY();

	double result = x1 * (y2 - y3) +
		x2 * (y3 - y1) +
		x3 * (y1 - y2);

	return abs(result) / 2.0;
}

double Triangle::perimeter() const
{
	double side1 = p1.distanceTo(p2);
	double side2 = p2.distanceTo(p3);
	double side3 = p3.distanceTo(p1);

	return side1 + side2 + side3;
}

bool Triangle::isValid() const
{
	return abs(area()) > 1e-9;
}
