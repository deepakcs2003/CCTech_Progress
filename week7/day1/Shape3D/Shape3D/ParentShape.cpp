#include "ParentShape.h"

ParentShape::ParentShape(QPoint s, QPoint e):start(s),end(e)
{
}

ParentShape::~ParentShape()
{
}

void ParentShape::setEnd(QPoint e)
{
	end = e;
}
