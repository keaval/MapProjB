#pragma once
#include "Region.h"
#include "Place.h"
#include "Crust.h"
#include "color.h"

class World
{
public:
	vector <Region> regions;
	vector <Place> lp;
	vector <int> height_groups;
	TPoint FictionalPos;


	vector <Crust> crust;

	float cuHeight;
	int lastNu;
	int lastIn;
	int sswitch;
	float sinV;
	float sinVL;
	float sinLXV;
	TPoint h;
	vector <int> free_crust;
	vector <int> crust_neighbors;
	vector <set <pair <float, int> > > lake_dfs;
	vector < pair <pair <int, float>, int> > sorted_height;
	set < pair <float, int> > fi;
	pair <float, int> fis;
	vector <int> valid;
	vector <pair <int, int> > bfs_region_vertices;
	vector <int> town_shuffle;
	float sum_town_score;
	float cu_town_score;
	int cu_town;



	World();
	float getAngle(TPoint x);
	float getLayerZ(TPoint x);


	color color_rgb(float r, float g, float b);


	void outTpoint(TPoint a);


	float randomrandom();
	TPoint rand_in_sphere();


	float length(TPoint a);
	float distance(TPoint a, TPoint b);
	TPoint normalize(TPoint a);
	TPoint normalize_t(TPoint a);
	TPoint vector_mult(TPoint a, TPoint b);
	float dot_mult(TPoint a, TPoint b);
	TPoint project(TPoint a, TPoint b);
	TPoint vector_add(TPoint a, TPoint b);
	TPoint vector_substr(TPoint a, TPoint b);
	TPoint vector_scale(TPoint v, float c);



	void add_connection(int a, int b);
	void unite_crust(int a, int b);
	void initPlaces();


	void get_climate();


	void randomize_crust_height();
	void unite_random_crust(int number, int wateration);
	float get_mountain_force_between(Connection i);
	float get_mountain_force(int a);
	void init_height();
	void stabilize_height();
	void bfsSubHeightRiver(bool toAct);
	void subHeightRiver();


	float climate_town_chance(string c);
	float get_town_chances(int i);
	void bfs_regions(int cu_in);
	void get_regions();


	bool is_water(int i);
	void get_goods();


	void dfs_lake(int cu, int lake_in, float h, int lakes);
	void bfs_flow(int cu, int lakes);
	void get_lake_flow();
	void get_river_flow();
	float get_basic_flow(float prec);
	void get_rain_amount();
	void get_flow();


	float get_temp_diff(float za, float zb);
	void iterate_water_temp();
	void iterate_air_temp();


	void get_coastal();
	void get_coastal_normale();
	void get_water_speed();
	void stabilize_water_speed();


	TPoint get_wind(TPoint p, float tra, float trb);
	TPoint get_upd_wind(TPoint p);
	float get_pressure(float z);

	map<string, color> climateColor;
	void initClimateColor();
	color colorForZone(string z);

	color colorForHeight(float h);

	void paintPixel(int w, int h, color col, color(*c)[screenW][screenH]);
	void paintEllipse(int w, int h, double wr, double hr, color col, color(*c)[screenW][screenH]);
	pair <int, int> mercator(TPoint a);

	color PhysMap[screenW][screenH];
	color ClimMap[screenW][screenH];

	int getRadii(float z);
	void paintBMP(string fileName, color (* c)[screenW][screenH]);
	void paintMaps();

	int init_main();
};

