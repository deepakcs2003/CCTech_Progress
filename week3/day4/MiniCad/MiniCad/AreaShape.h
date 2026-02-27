#pragma once
#include <string>
#include "Shape.h"
class AreaShape : public Shape
{
public:
	AreaShape(int id);
	virtual double area() const = 0;
	virtual double perimeter() const = 0;

};

