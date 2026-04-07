#include "TriangleClass.h"

TriangleClass::TriangleClass(int v1, int v2, int v3) :v1(v1), v2(v2), v3(v3)
{
}

TriangleClass::~TriangleClass()
{
}

int TriangleClass::getV1() const
{
	return v1;
}

int TriangleClass::getV2() const
{
	return v2;
}

int TriangleClass::getV3() const
{
	return v3;
}


