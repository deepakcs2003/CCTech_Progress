#include "Triangle.h"

Triangle::Triangle(string name, double x1, double y1, double x2, double y2, double x3, double y3):
shape(name),x1(x1),y1(y1),x2(x2),y2(y2),x3(x3),y3(y3)
{
}

double Triangle::area()
{

	int a = x1 * (y2 - y3);
	int b = x2 * (y3 - y1);
	int c = x3 * (y1 - y2);
	return 0.5 * abs(a + b + c);
}

void Triangle::display()
{
	cout << name<<"(" << "point1=(" << x1 <<","<< y1 << ")"
	<< ",point2=(" << x2<<"," << y2 << ")"
	<< ",point3=(" << x3 <<"," << y3 << ")" << ")" << endl;
}
