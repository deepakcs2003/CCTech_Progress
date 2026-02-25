#pragma once
#include "shape.h"
class Triangle :public shape
{
private:
	double x1, y1, x2, y2, x3, y3;
public:
	Triangle(string name, double x1, double y1, double x2, double y2, double x3, double y3);
	double area() override;
	void display() override;
};

