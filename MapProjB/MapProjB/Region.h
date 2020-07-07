#pragma once
#include "cons.h"

class Region
{
public:
	int t = 0;
	vector <int> p;
	set <int> marine_borders;
	set <int> land_borders;
	float good[10];
	Region();
	~Region();
};

