#include "Line.h"
#include "Shape.h"
#include "Point.h"
#include <iostream>
using namespace std;


Line::Line(int id, double x1, double y1, double x2, double y2):
	Shape(id),p1(id, x1, y1), p2(id, x2, y2)
{
}

void Line::move(double dx, double dy)
{
	p1.move(dx, dy);
	p2.move(dx, dy);
}

void Line::scale(double factor)
{
	p1.scale(factor);
	p2.scale(factor);
}

string Line::getType() const
{
	return "Line";
}

void Line::display() const
{
	cout << "ID: " << getId() << "\n";
	cout << "Type: " << getType() << "\n";
	cout << "Start Point: ("
		<< p1.getX() << ", " << p1.getY() << ")\n";

	cout << "End Point: ("
		<< p2.getX() << ", " << p2.getY() << ")\n";

	cout << "Length: " << length() << "\n";
}

double Line::length() const
{
	return p1.distanceTo(p2);
}

//bool Line::intersects(const Line& other) const
//{
//	return ;
//}
