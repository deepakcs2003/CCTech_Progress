#pragma once
#include <string>
#include "shape.h"

using namespace std;
class Rectangle:public shape
{
private:
	double x1, y1, x2, y2;
public:
	Rectangle(string name, double x1, double y1, double x2, double y2);
	double area() override;
	void display() override;
};

