#include "Shape.h"



Shape::Shape(int id) :id(id)
{
}

int Shape::getId() const
{
	return id;
}

Shape::~Shape()
{
}

void Shape::move(double dx, double dy)
{
}

void Shape::scale(double factor)
{
}

void Shape::display() const
{
}
