#pragma once
#include <string>
#include "Shape.h"
using namespace std;
class Circle :public shape
{
private:
	double radius;
	static  double  pi;
	double x, y;
public:
	Circle(string name, double radius, double x, double y);
	void display() override;
	double area() override;

};

