#pragma once
#include "Connection.h"


class Place
{
public:
	TPoint rG = TPoint();
	TPoint x = TPoint();
	TPoint display_x = TPoint();
	vector<Connection> c;
	int cr = 0;
	float vCof;
	TPoint v = TPoint();
	float dh = 0;
	int cr_type = 0;
	float cudh = 0;
	float h = 0;
	TPoint wind_v = TPoint();
	TPoint upd_wind_v = TPoint();
	TPoint dwater_v = TPoint();
	TPoint water_v = TPoint();
	float water_temp = 0.5;
	float water_dtemp = 0;
	bool isCoastal = false;
	TPoint coastal_normale = TPoint();
	float winter_air_prec = 0;
	float winter_dair_prec = 0;
	float summer_air_prec = 0;
	float summer_dair_prec = 0;
	float air_pressure = 0;
	string climateType = "";
	TPoint winter_wind_v = TPoint();
	TPoint summer_wind_v = TPoint();
	bool flow_went = false;
	int subHeightVis = 0;
	int lake_flow = -1;
	int lake_nu = 0;
	float lake_size = 0;
	int flow_to = 0;
	float basic_summer_flow = 0.0;
	float basic_winter_flow = 0.0;
	float summer_flow = 0.0;
	float winter_flow = 0.0;
	float lake_height = 10000.0;
	float lake_top = 0;
	float water_lake_flow = 0;
	float town_chance = 0.0;
	int town_nu = -1;
	pair<float, float> texCoor;
	int ran;
	Place();
	~Place();
};
