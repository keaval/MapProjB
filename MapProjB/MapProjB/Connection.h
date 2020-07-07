#pragma once
#include "TPoint.h"


class Connection
{
public:
	int p = 0;
	TPoint v_to = TPoint();
	TPoint mountain_project = TPoint();
	TPoint wind_summer_project = TPoint();
	TPoint wind_winter_project = TPoint();
	TPoint water_project = TPoint();
	bool water_go = false;
	bool wind_summer_go = false;
	bool wind_winter_go = false;
	float temp_diff = 0;
	float water_len = 0;
	float wind_summer_len = 0;
	float wind_winter_len = 0;
	Connection();
	~Connection();
};

