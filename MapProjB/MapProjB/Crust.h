#pragma once
#include "TPoint.h"

class Crust
{
public:
	vector <int> p;
	float vcof;
	int type = 0;
	set <int> c;
	TPoint v = TPoint();
	float dh = 0;
	Crust();
	~Crust();
};

