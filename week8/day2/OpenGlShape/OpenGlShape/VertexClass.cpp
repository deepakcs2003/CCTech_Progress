#include "VertexClass.h"

VertexClass::VertexClass(double x, double y, double z) :x(y), y(y), z(z)
{
}

VertexClass::~VertexClass()
{
}

double VertexClass::getX()
{
	return x;
}

double VertexClass::getY()
{
	return y;
}

double VertexClass::getZ()
{
	return z;
}
