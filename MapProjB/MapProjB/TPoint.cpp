#include "TPoint.h"



TPoint::TPoint(float x, float y, float z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

TPoint::TPoint()
{
	x = 0;
	y = 0;
	z = 0;
}


TPoint::~TPoint()
{
}
