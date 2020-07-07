#pragma once
#include "TPoint.h"
#include "color.h"

class Chunk
{
public:
	TPoint x;
	TPoint r;
	pair<float, float> texCoor;
	float h;
	string climate;
	color cl;
	int ran;
	Chunk();
	~Chunk();
};

