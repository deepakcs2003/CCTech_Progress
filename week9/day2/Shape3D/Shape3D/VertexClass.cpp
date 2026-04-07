#include "VertexClass.h"

VertexClass::VertexClass(double x, double y, double z) :x(y), y(y), z(z)
{
}

VertexClass::~VertexClass()
{
}

double VertexClass::getX() const
{
	return x;
}

double VertexClass::getY() const
{
	return y;
}

double VertexClass::getZ() const
{
	return z;
}
