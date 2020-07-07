#include "World.h"

World::World()
{
	initClimateColor();
	FictionalPos = TPoint(1000.0, 0.0, 0.0);
	cuHeight = -pointRadii;
	lastNu = 0;
	lastIn = 0;
	sswitch = 1;
	sinV = float(sin(3.1415 / 36));
	sinVL = float(sin(3.1415 / 4));
	sinLXV = float(sin(13 * 3.1415 / 36));
	h = TPoint(0, 0, 1);
	sum_town_score = 0.0;
	cu_town_score = 0.0;
	cu_town = 0;
}

float World::getAngle(TPoint x) {
	return atan2(x.y, x.x);
}


float World::getLayerZ(TPoint x) {
	return x.z;
}

color World::color_rgb(float r, float g, float b) {
	color c = color();
	c.r = r;
	if (r < 0) {
		c.r = 0;
	}
	if (r > 255) {
		c.r = 255;
	}
	c.g = g;
	if (g < 0) {
		c.g = 0;
	}
	if (g > 255) {
		c.g = 255;
	}
	c.b = b;
	if (b < 0) {
		c.b = 0;
	}
	if (b > 255) {
		c.b = 255;
	}
	return c;
}



void World::outTpoint(TPoint a) {
	cout << a.x << " " << a.y << " " << a.z << endl;
}



float World::randomrandom() {
	return float(2 * (double(rand()) - RAND_MAX / 2) / RAND_MAX);
}


TPoint World::rand_in_sphere() {
	while (true) {
		float x = randomrandom();
		float y = randomrandom();
		float z = randomrandom();
		TPoint p = TPoint();
		p.x = x;
		p.y = y;
		p.z = z;
		if (x * x + y * y + z * z < 1) {
			return p;
		}
	}
}



float World::length(TPoint a) {
	return sqrt(a.x * a.x + a.y * a.y + a.z * a.z);
}


float World::distance(TPoint a, TPoint b) {
	float res = (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y) + (a.z - b.z) * (a.z - b.z);
	return sqrt(res);
}


TPoint World::normalize(TPoint a) {
	TPoint zer = TPoint(0, 0, 0);
	float dis = distance(a, zer);
	return TPoint(a.x / dis, a.y / dis, a.z / dis);
}


TPoint World::normalize_t(TPoint a) {
	float res = sqrt(a.x * a.x + a.y * a.y + a.z * a.z);
	if (res == 0) {
		return TPoint();
	}
	TPoint re = TPoint();
	re.x = a.x / res;
	re.y = a.y / res;
	re.z = a.z / res;
	return re;
}


TPoint World::vector_mult(TPoint a, TPoint b) {
	TPoint c = TPoint();
	c.x = a.y * b.z - a.z * b.y;
	c.y = -a.x * b.z + a.z * b.x;
	c.z = a.x * b.y - a.y * b.x;
	return c;
}


float World::dot_mult(TPoint a, TPoint b) {
	return a.x * b.x + a.y * b.y + a.z * b.z;
}


TPoint World::project(TPoint a, TPoint b) {
	float co = dot_mult(a, b) / dot_mult(b, b);
	TPoint c = TPoint();
	c.x = co * b.x;
	c.y = co * b.y;
	c.z = co * b.z;
	return c;
}


TPoint World::vector_add(TPoint a, TPoint b) {
	TPoint c = TPoint();
	c.x = b.x + a.x;
	c.y = b.y + a.y;
	c.z = b.z + a.z;
	return c;
}


TPoint World::vector_substr(TPoint a, TPoint b) {
	TPoint c = TPoint();
	c.x = a.x - b.x;
	c.y = a.y - b.y;
	c.z = a.z - b.z;
	return c;
}


TPoint World::vector_scale(TPoint v, float c) {
	TPoint a = TPoint();
	a.x = v.x * c;
	a.y = v.y * c;
	a.z = v.z * c;
	return a;
}





void World::add_connection(int a, int b) {
	Connection a_connect = Connection();
	Connection b_connect = Connection();
	a_connect.p = a;
	b_connect.p = b;
	lp[a].c.push_back(b_connect);
	lp[b].c.push_back(a_connect);
}


void World::unite_crust(int a, int b) {
	for (int j = 0; j < int(crust[b].p.size()); j++) {
		int i = crust[b].p[j];
		lp[i].cr = a;
		crust[a].p.push_back(i);
	}
	crust[b].p.clear();
	vector <int> oc = vector<int>(crust[b].c.begin(), crust[b].c.end());
	for (int j = 0; j < int(oc.size()); j++) {
		int i = oc[j];
		crust[i].c.erase(b);
		crust[i].c.insert(a);
	}
	crust[a].c.insert(crust[b].c.begin(), crust[b].c.end());
	crust[a].c.erase(a);
	crust[a].c.erase(b);
	crust[b].c.clear();
}


void World::initPlaces() {
	while (cuHeight <= pointRadii + 0.5) {
		height_groups.push_back(lp.size());
		float circleHeight = ((float)cuHeight) / float(pointRadii);
		float circleRadii = sqrt(1 - circleHeight * circleHeight);
		int pointNum = int(round(4 * pointRadii) + 0.5);
		if (pointRadii - cuHeight < 0.5 || pointRadii + cuHeight < 0.5) {
			pointNum = 1;
		}
		float angle = 0.0;
		float angleTurn = (float)2.0f * 3.1415f / pointNum;
		while (angle < 2 * 3.1415 - angleTurn / 2) {
			float x = circleRadii * cos(angle);
			float y = circleRadii * sin(angle);
			float z = circleHeight;
			TPoint p = TPoint(x, y, z);
			Place t = Place();
			t.c.clear();
			t.x = p;
			t.cr = lp.size();
			lp.push_back(t);
			Crust cr = Crust();
			cr.p.clear();
			cr.p.push_back(lp.size() - 1);
			crust.push_back(cr);
			double ap = round(angle / angleTurn) + 0.1;
			if (lastNu > 0) {
				int ki = int(ap);
				int kj = int(ap) + 1;
				int kk = int(ap) - 1 + lastNu;
				ki %= lastNu;
				kj %= lastNu;
				kk %= lastNu;

				add_connection(lp.size() - 1, lastIn - lastNu + ki);

				if (lastNu > 1) {
					add_connection(lp.size() - 1, lastIn - lastNu + kj);
					add_connection(lp.size() - 1, lastIn - lastNu + kk);
				}
			}
			if (angle > angleTurn / 2) {
				add_connection(lp.size() - 1, lp.size() - 2);
			}
			angle += angleTurn;
		}
		lastNu = lp.size() - lastIn;
		lastIn += lastNu;
		if (lastNu > 1) {
			add_connection(lastIn - 1, lastIn - lastNu);
		}
		cuHeight += 1;
	}
	height_groups.push_back(lp.size());
	for (int i = 0; i < int(lp.size()); i++) {
		free_crust.push_back(i);
		for (int j = 0; j < int(lp[i].c.size()); j++) {
			crust[i].c.insert(lp[i].c[j].p);
			crust[i].vcof = randomrandom();
		}
		crust[i].v = rand_in_sphere();
	}
	float cuCrustW = 0.0;
	random_shuffle(free_crust.begin(), free_crust.end());
	for (int i = 0; i < free_crust.size(); i++) {
		cuCrustW += 0.57566328;
		if (cuCrustW > 1) {
			cuCrustW--;
		}
		if (cuCrustW > waterCrust) {
			crust[free_crust[i]].type = 1;
		}
		else {
			crust[free_crust[i]].type = 0;
		}
	}
}


void World::get_climate() {
	float air_prec, max_prec, latitude;
	string climate;
	for (int i = 0; i < int(lp.size()); i++) {
		if (lp[i].h < 0) {
			lp[i].climateType = "oceanic";
			continue;
		}
		if (lp[i].h > 1500) {
			lp[i].climateType = "mountain";
			continue;
		}
		air_prec = (lp[i].summer_air_prec + lp[i].winter_air_prec) / 2;
		max_prec = max(lp[i].summer_air_prec, lp[i].winter_air_prec);
		latitude = (float)asin(lp[i].x.z) * 180.0f / 3.1415f;
		climate = "";
		if (latitude < 0) {
			latitude = -latitude;
		}
		if (latitude - 2 * air_prec < 17 && max_prec > 0.4) {
			if (max_prec > 0.7) {
				climate = "Af";
			}
			else {
				if (max_prec + air_prec / 2.0f > 0.9f) {
					climate = "Am";
				}
				else {
					climate = "Aw";
				}
			}
		}
		else {
			if ((air_prec * 300 + latitude < 126 && latitude < 60) || latitude - 2 * air_prec < 17) {
				climate = "B";
				if (air_prec * 40 + latitude < 44) {
					climate += "W";
				}
				else {
					climate += "S";
				}
				if (latitude + 10 * max_prec < 35) {
					climate += "h";
				}
				else {
					climate += "k";
				}
			}
			else {
				if (latitude - 2 * air_prec < 54 && (max_prec > 0.5 || air_prec > 0.45)) {
					climate = "C";
					float bonus = 0;
					if (lp[i].winter_air_prec - lp[i].summer_air_prec > 0.1f) {
						climate += "s";
						bonus = 12;
					}
					else {
						if (lp[i].winter_air_prec - lp[i].summer_air_prec < -0.1f) {
							climate += "w";
						}
						else {
							climate += "f";
						}
					}
					if ((max_prec * 80 - latitude + bonus > 16 || latitude <= 32) && latitude < 46) {
						climate += "a";
					}
					else {
						if (max_prec * 80 - latitude > -10) {
							climate += "b";
						}
						else {
							climate += "c";
						}
					}
				}
				else {
					climate = "D";
					if (lp[i].winter_air_prec - lp[i].summer_air_prec > 0.15f) {
						climate += "s";
					}
					else {
						if (lp[i].winter_air_prec - lp[i].summer_air_prec < -0.15f) {
							climate += "w";
						}
						else {
							climate += "f";
						}
					}
					if (max_prec * 50 - latitude > -27) {
						climate += "a";
					}
					else {
						if (max_prec * 50 - latitude > -45) {
							climate += "b";
						}
						else {
							climate += "c";
						}
					}
				}
			}
		}
		lp[i].climateType = climate;
	}
}


void World::randomize_crust_height() {
	for (int i = 0; i < int(crust.size()); i++) {
		crust[i].dh = randomrandom() * 2 * crustRandomHeightMax;
	}
	for (int i = 0; i < int(lp.size()); i++) {
		lp[i].dh += crust[lp[i].cr].dh;
	}
}


void World::unite_random_crust(int number, int wateration) {
	for (int i = 0; i < number; i++) {
		if (lp.size() - i == crustRandomHeightNumA || lp.size() - i == crustRandomHeightNumB || lp.size() - i == crustRandomHeightNumC || lp.size() - i == crustRandomHeightNumD) {
			randomize_crust_height();
		}
		if (lp.size() - i == mountCoefPlacingNum) {
			for (int j = 0; j < int(lp.size()); j++) {
				lp[j].vCof = randomrandom() / mountCoefPlacingPlaceVariation + crust[lp[j].cr].vcof;
			}
		}
		if (i == wateration) {
			for (int j = 0; j < int(lp.size()); j++) {
				lp[j].cr_type = crust[lp[j].cr].type;
			}
		}
		int c = free_crust[lp.size() - i - 1];
		crust_neighbors = vector<int>(crust[c].c.begin(), crust[c].c.end());
		unite_crust(crust_neighbors[rand() % crust_neighbors.size()], c);
	}
}



float World::get_mountain_force_between(Connection i) {
	TPoint d = i.mountain_project;
	return (float)(pow(d.x * d.x + d.y * d.y + d.z * d.z, mountDegreeSize));
}


float World::get_mountain_force(int a) {
	float re = 0;
	for (int i = 0; i < int(lp[a].c.size()); i++) {
		re += get_mountain_force_between(lp[a].c[i]);
	}
	re *= mountainHeight;
	re /= lp[a].c.size();
	if (crust[lp[a].cr].type == 0) {
		re /= crustSeaMountDivide;
	}
	if (lp[a].cr_type == 0) {
		re /= subCrustSeaMountDivide;
	}
	return re;
}


void World::init_height() {
	unite_random_crust(lp.size() - crustNu, lp.size() - crustNu * waterationCrustMult);
	for (int i = 0; i < int(lp.size()); i++) {
		lp[i].v = vector_mult(lp[i].x, crust[lp[i].cr].v);
		lp[i].v = vector_scale(lp[i].v, lp[i].vCof / mountCoefMult + 1.0f);
	}
	for (int i = 0; i < int(lp.size()); i++) {
		for (int j = 0; j < int(lp[i].c.size()); j++) {
			lp[i].c[j].v_to = vector_substr(lp[i].x, lp[lp[i].c[j].p].x);
			lp[i].c[j].mountain_project = project(vector_substr(lp[i].v, lp[lp[i].c[j].p].v), lp[i].c[j].v_to);
			float cof = (lp[i].vCof / mountCoefSubMult + 1.0f) * (lp[lp[i].c[j].p].vCof / mountCoefSubMult + 1.0f);
			if (cof < mountForceToSpawn) {
				lp[i].c[j].mountain_project = vector_scale(lp[i].c[j].mountain_project, 0.0f);
			}
		}
	}
	for (int i = 0; i < int(lp.size()); i++) {
		lp[i].dh += get_mountain_force(i);
		if (crust[lp[i].cr].type == 0) {
			lp[i].dh += oceanDepth;
		}
		else if (lp[i].cr_type == 0) {
			lp[i].dh += oceanSubDepth;
		}
		else {
			lp[i].dh += landSubDepth;
		}
	}
}


void World::stabilize_height() {
	float cof;
	for (int i = 0; i < int(lp.size()); i++) {
		float nh = 0.0;
		lp[i].cudh = float(lp[i].dh * conservativeHeight);
		for (int j = 0; j < int(lp[i].c.size()); j++) {
			cof = lp[lp[i].c[j].p].h - lp[i].h;
			if (cof > 0) {
				cof *= upStabilisation;
			}
			else {
				cof = 0;
			}
			nh += cof;
		}
		nh /= lp[i].c.size();
		lp[i].cudh += nh;
	}
	for (int i = 0; i < int(lp.size()); i++) {
		lp[i].h = lp[i].cudh * stabilisationSpeed + lp[i].h * (1 - stabilisationSpeed);
	}
}

void World::bfsSubHeightRiver(bool toAct)
{
	pair<float, int> cu = *fi.begin();
	int i = cu.second;
	lp[i].subHeightVis = 2;
	//cout << i << endl;
	fi.erase(cu);
	bool nowToAct = toAct;
	if (lp[i].h > 0) {
		nowToAct = true;
	}
	if (nowToAct) {
		float minH = maxeFloat;
		for (int j = 0; j < lp[i].c.size(); j++) {
			if (lp[lp[i].c[j].p].subHeightVis == 2) {
				minH = min(minH, lp[lp[i].c[j].p].h);
			}
		}
		lp[i].h = max(lp[i].h, minH + 0.1f);
	}
	for (int j = 0; j < lp[i].c.size(); j++) {
		if (lp[lp[i].c[j].p].subHeightVis == 0) {
			lp[lp[i].c[j].p].subHeightVis = 1;
			fi.insert(make_pair(lp[lp[i].c[j].p].h, lp[i].c[j].p));
		}
	}
	if (fi.size() > 0) {
		bfsSubHeightRiver(nowToAct);
	}
}

void World::subHeightRiver()
{
	for (int i = 0; i < seaPreserve; i++) {
		int j = rand() % lp.size();
		if (lp[j].h < 0) {
			fi.insert(make_pair(lp[j].h, j));
			lp[j].subHeightVis = 1;
		}
	}
	bfsSubHeightRiver(false);
	fi.clear();
}



float World::climate_town_chance(string c) {
	if (c == "mountain") {
		return 5.0;
	}
	if (c == "Af") {
		return 1.0;
	}
	if (c[0] == 'A') {
		return 5.0;
	}
	if (c == "BWh") {
		return 1.0;
	}
	if (c == "BSk") {
		return 10.0;
	}
	if (c[0] == 'B') {
		return 5.0;
	}
	if (c[0] == 'C' && c[1] == 's') {
		return 150.0;
	}
	if (c[0] == 'C' && c[2] == 'a') {
		return 20.0;
	}
	if (c[0] == 'C') {
		return 50.0;
	}
	if (c[2] == 'c') {
		return 1.0;
	}
	return 20.0;
}


float World::get_town_chances(int i) {
	int k;
	string cl;
	string c = lp[i].climateType;
	if (c == "river" || c == "lake" || c == "oceanic") {
		return 0;
	}
	float chance = climate_town_chance(c);
	bool near_sea = false;
	bool near_river = false;
	bool near_lake = false;
	for (int j = 0; j < int(lp[i].c.size()); j++) {
		k = lp[i].c[j].p;
		cl = lp[k].climateType;
		if (cl == "river") {
			near_river = true;
		}
		if (cl == "oceanic") {
			near_sea = true;
		}
		if (cl == "lake") {
			near_lake = true;
		}
	}
	if (near_river && c[0] == 'B') {
		return 200;
	}
	if (near_river && c[0] == 'A') {
		return 75;
	}
	if (near_sea && near_river) {
		return max(chance * 2 + 100, 150.0f);
	}
	if (near_river) {
		return chance + 50;
	}
	if (near_lake) {
		return chance + 30;
	}
	if (near_sea) {
		return max(chance * 2, 50.0f);
	}
	if (lp[i].winter_flow + lp[i].summer_flow > 400) {
		return chance + 20;
	}
	return chance;
}


void World::bfs_regions(int cu_in) {
	int k, l;
	int p = bfs_region_vertices[cu_in].first;
	int region = bfs_region_vertices[cu_in].second;
	for (int j = 0; j < int(lp[p].c.size()); j++) {
		k = lp[p].c[j].p;
		if (lp[k].town_nu == -1 && randomrandom() > 0) {
			lp[k].town_nu = region;
			regions[region].p.push_back(k);
			bfs_region_vertices.push_back(make_pair(k, region));
			if (lp[k].town_nu >= 0) {
				l = lp[k].town_nu;
				if (lp[k].h < 0 || lp[k].climateType == "river" || lp[k].climateType == "lake") {
					regions[region].marine_borders.insert(l);
					regions[l].marine_borders.insert(region);
				}
				else {
					regions[region].land_borders.insert(l);
					regions[l].land_borders.insert(region);
				}
			}
		}
	}
}


void World::get_regions() {
	int k, cuIn;
	for (int i = 0; i < int(regions.size()); i++) {
		if (lp[regions[i].t].town_nu == -1) {
			k = i;
			lp[regions[i].t].town_nu = k;
			regions[i].p.push_back(regions[i].t);
			bfs_region_vertices.push_back(make_pair(regions[i].t, k));
		}
	}
	cuIn = 0;
	while (cuIn < int(bfs_region_vertices.size())) {
		bfs_regions(cuIn);
		cuIn += 1;
	}
}


//Grain
//Meat
//Wood
//Horse
//Clay
//Borealis goods
//Australis goods
//Occidentalis goods
//Orientalis goods
//Mountain goods


bool World::is_water(int i) {
	string c = lp[i].climateType;
	if (c == "oceanic" || c == "lake" || c == "river") {
		return true;
	}
	return false;
}


void World::get_goods() {
	int i, co;
	float d;
	string c;
	for (int j = 0; j < int(regions.size()); j++) {
		for (int k = 0; k < int(regions[j].p.size()); k++) {
			i = regions[j].p[k];
			if (!is_water(i)) {
				c = lp[i].climateType;
				for (int l = 0; l < int(lp[i].c.size()); l++) {
					co = lp[i].c[l].p;
					if (lp[co].climateType == "river") {
						regions[j].good[1] += 10.0f;
						regions[j].good[4] += 10.0f;
						if (c[0] == 'B') {
							d = lp[co].summer_flow - lp[co].winter_flow;
							if (d < 0) {
								d = -d;
							}
							regions[j].good[0] += d + 15;
						}
						if (c[0] == 'C') {
							regions[j].good[0] += 20;
						}
					}
					if (lp[co].climateType == "lake") {
						regions[j].good[1] += 15;
						regions[j].good[4] += 20;
					}
					if (lp[co].climateType == "oceanic") {
						regions[j].good[1] += float(pow(50.0, (1 - lp[co].water_temp)));
					}
				}
				if (c == "Aw") {
					regions[j].good[0] += 2;
					regions[j].good[2] += 2;
					regions[j].good[6] += 5;
					continue;
				}
				if (c[0] == 'A') {
					regions[j].good[0] += 1;
					regions[j].good[2] += 3;
					regions[j].good[6] += 5;
					continue;
				}
				if (c == "BWh") {
					continue;
				}
				if (c[0] == 'B') {
					regions[j].good[1] += 2;
					regions[j].good[3] += 5;
					continue;
				}
				if (c[0] == 'C' && c[1] == 's') {
					regions[j].good[0] += 15;
					regions[j].good[7] += 7;
					continue;
				}
				if (c[0] == 'C' && c[2] == 'a') {
					regions[j].good[0] += 8;
					regions[j].good[2] += 6;
					regions[j].good[8] += 5;
					continue;
				}
				if (c[0] == 'C') {
					regions[j].good[0] += 4;
					regions[j].good[1] += 4;
					regions[j].good[2] += 4;
					regions[j].good[3] += 1;
					regions[j].good[7] += 3;
					continue;
				}
				if (c[0] == 'D' && c[2] == 'a') {
					regions[j].good[1] += 4;
					regions[j].good[3] += 5;
					continue;
				}
				if (c[0] == 'D' && c[2] == 'b') {
					regions[j].good[0] += 2;
					regions[j].good[1] += 3;
					regions[j].good[2] += 4;
					regions[j].good[3] += 2;
					regions[j].good[5] += 3;
					continue;
				}
				if (c[0] == 'D') {
					regions[j].good[2] += 5;
					regions[j].good[5] += 7;
					continue;
				}
				if (c == "mountain") {
					regions[j].good[1] += 4;
					regions[j].good[2] += 4;
					regions[j].good[9] += 5;
					continue;
				}
			}
		}
	}
}





void World::dfs_lake(int cu, int lake_in, float h, int lakes) {
	int k;
	lp[cu].flow_went = true;
	lp[cu].lake_flow = lake_in;
	lp[lake_in].lake_size += 1;
	lp[cu].lake_nu = lakes + 1;
	for (int j = 0; j < int(lp[cu].c.size()); j++) {
		k = lp[cu].c[j].p;
		if (lp[k].h > h && !lp[k].flow_went) {
			if (int(lake_dfs.size()) < lakes + 2) {
				lake_dfs.push_back(set <pair <float, int> >());
			}
			lake_dfs[lakes + 1].insert(make_pair(lp[k].h, k));
		}
		if (lp[k].flow_went || lp[k].h < 0 || lp[k].h > h) {
			continue;
		}
		dfs_lake(k, lake_in, h, lakes);
	}
}


void World::bfs_flow(int cu, int lakes) {
	int k;
	if (lp[cu].flow_went) {
		return;
	}
	lp[cu].flow_went = true;
	lp[cu].lake_nu = lakes;
	for (int j = 0; j < int(lp[cu].c.size()); j++) {
		k = lp[cu].c[j].p;
		if (lp[k].flow_went || lp[k].h < 0) {
			continue;
		}
		if (lp[k].h < lp[cu].h) {
			dfs_lake(k, cu, lp[cu].h, lakes);
		}
		else {
			lake_dfs[lakes].insert(make_pair(lp[k].h, k));
		}
	}
}





void World::get_lake_flow() {
	int cu_row = 0;
	for (int i = 0; i < int(lp.size()); i++) {
		if (lp[i].isCoastal) {
			fi.insert(make_pair(lp[i].h, i));
		}
	}
	lake_dfs.push_back(fi);
	while (true) {
		if (lake_dfs[cu_row].size()) {
			fis = *lake_dfs[cu_row].begin();
			lake_dfs[cu_row].erase(fis);
			bfs_flow(fis.second, cu_row);
		}
		else {
			if (int(lake_dfs.size()) > cu_row + 1) {
				cu_row += 1;
			}
			else {
				return;
			}
		}
	}
}


void World::get_river_flow() {
	for (int i = 0; i < int(lp.size()); i++) {
		if (lp[i].h >= 0) {
			valid.clear();
			for (int j = 0; j < int(lp[i].c.size()); j++) {
				int k = lp[i].c[j].p;
				if (lp[k].h < lp[i].h && lp[k].lake_nu <= lp[i].lake_nu) {
					valid.push_back(k);
				}
			}
			if (valid.size() > 0) {
				lp[i].flow_to = valid[rand() % valid.size()];
			}
			else {
				lp[i].flow_to = lp[i].lake_flow;
			}
		}
	}
}


float World::get_basic_flow(float prec) {
	return float(pow(200, prec));
}


void World::get_rain_amount() {
	for (int i = 0; i < int(lp.size()); i++) {
		if (lp[i].h >= 0) {
			if (lp[i].climateType != "mountain") {
				lp[i].basic_summer_flow = get_basic_flow(lp[i].summer_air_prec);
				lp[i].basic_winter_flow = get_basic_flow(lp[i].winter_air_prec);
			}
			else {
				if (lp[i].x.z < 0.5 && lp[i].x.z > -0.5) {
					lp[i].basic_summer_flow = get_basic_flow(0.8f);
					lp[i].basic_winter_flow = get_basic_flow(0.8f);
				}
				else {
					lp[i].basic_summer_flow = get_basic_flow(0.85f);
					lp[i].basic_winter_flow = get_basic_flow(0.75f);
				}
			}
		}
	}
}


void World::get_flow() {
	int i, est;
	float oz_h;
	for (int j = 0; j < int(sorted_height.size()); j++) {
		i = sorted_height[j].second;
		lp[i].summer_flow += lp[i].basic_summer_flow;
		lp[i].winter_flow += lp[i].basic_winter_flow;
		est = lp[i].flow_to;
		if (lp[i].water_lake_flow > 0.1) {
			oz_h = sqrt(lp[i].water_lake_flow) * 100 * (lp[i].summer_air_prec + lp[i].winter_air_prec) / lp[i].lake_size;
			if (lp[i].lake_height + oz_h >= lp[i].h) {
				lp[i].lake_top = lp[i].h;
				lp[i].summer_flow += lp[i].water_lake_flow;
				lp[i].winter_flow += lp[i].water_lake_flow;
			}
			else {
				lp[i].lake_top = lp[i].lake_height + oz_h;
			}
		}
		//cout << lp[i].h << " " << i << " " << est << " " << lp.size() << endl;
		if (est == -1) {
			continue;
		}
		if (lp[i].h > lp[est].h) {
			if (lp[i].x.z * lp[i].x.z > 0) {
				lp[est].summer_flow += lp[i].summer_flow;
				lp[est].winter_flow += lp[i].winter_flow;
			}
			else {
				lp[est].summer_flow += lp[i].winter_flow;
				lp[est].winter_flow += lp[i].summer_flow;
			}
		}
		else {
			lp[est].water_lake_flow += lp[i].winter_flow / 2 + lp[i].summer_flow / 2;
			lp[est].lake_height = min(lp[est].lake_height, lp[i].h);
		}
	}
}





float World::get_temp_diff(float za, float zb) {
	float a = za;
	float b = zb;
	if (a < 0) {
		a *= -1;
	}
	if (b < 0) {
		b *= -1;
	}
	a = 6.0f * asin(a) / 3.1415f;
	b = 6.0f * asin(b) / 3.1415f;
	return b - a;
}


void World::iterate_water_temp() {
	float t, lv, sumT, sumL;
	for (int i = 0; i < int(lp.size()); i++) {
		lp[i].water_dtemp = 0;
		if (lp[i].h < 0) {
			sumT = 0;
			sumL = 0;
			for (int j = 0; j < int(lp[i].c.size()); j++) {
				if (lp[lp[i].c[j].p].h < 0) {
					if (lp[i].c[j].water_go) {
						t = lp[lp[i].c[j].p].water_temp - lp[i].c[j].temp_diff;
						lv = lp[i].c[j].water_len;
						sumT += t * lv;
						sumL += lv;
					}
				}
			}
			if (sumL > 0.01) {
				lp[i].water_dtemp = sumT / sumL;
			}
			else {
				lp[i].water_dtemp = lp[i].water_temp;
			}
		}
	}
	for (int i = 0; i < int(lp.size()); i++) {
		lp[i].water_temp = 2 * lp[i].water_temp / 3 + lp[i].water_dtemp / 3;
	}
}


void World::iterate_air_temp() {
	float sumPW, sumPS, sumLW, sumLS, wlv, slv, wp, sp, perP;
	for (int i = 0; i < int(lp.size()); i++) {
		lp[i].summer_dair_prec = 0;
		lp[i].winter_dair_prec = 0;
		sumPW = 0;
		sumPS = 0;
		sumLW = 0;
		sumLS = 0;
		for (int j = 0; j < int(lp[i].c.size()); j++) {
			if (!lp[i].c[j].wind_summer_go && !lp[i].c[j].wind_winter_go) {
				continue;
			}
			wlv = lp[i].c[j].wind_winter_len;
			slv = lp[i].c[j].wind_summer_len;
			if (lp[i].c[j].wind_winter_go) {
				wp = lp[lp[i].c[j].p].winter_air_prec;
				sumPW += wp * wlv;
				sumLW += wlv;
			}
			if (lp[i].c[j].wind_summer_go) {
				sp = lp[lp[i].c[j].p].summer_air_prec;
				sumPS += sp * slv;
				sumLS += slv;
			}
		}
		if (sumLS > 0.01) {
			sumPS = sumPS / sumLS;
		}
		else {
			sumPS = lp[i].summer_air_prec;
		}
		if (sumLW > 0.01) {
			sumPW = sumPW / sumLW;
		}
		else {
			sumPW = lp[i].winter_air_prec;
		}
		sumPW = 0.992f * sumPW + 0.008f * (1 - lp[i].air_pressure);
		sumPS = 0.992f * sumPS + 0.008f * (1 - lp[i].air_pressure);
		if (lp[i].h < 0) {
			sumPW = 0.98f * sumPW + 0.015f + 0.005f * lp[i].water_temp;
			sumPS = 0.98f * sumPS + 0.015f + 0.005f * lp[i].water_temp;
		}
		else {
			perP = lp[i].h * lp[i].h / 100000000;
			if (perP > 1) {
				perP = 1;
			}
			sumPW = (1.0f - perP) * sumPW;
			sumPS = (1.0f - perP) * sumPS;
		}
		if (sumPW < 0) {
			sumPW = 0;
		}
		if (sumPS < 0) {
			sumPS = 0;
		}
		lp[i].winter_dair_prec = sumPW;
		lp[i].summer_dair_prec = sumPS;
	}
	for (int i = 0; i < int(lp.size()); i++) {
		lp[i].winter_air_prec = 2 * lp[i].winter_air_prec / 3 + lp[i].winter_dair_prec / 3;
		lp[i].summer_air_prec = 2 * lp[i].summer_air_prec / 3 + lp[i].summer_dair_prec / 3;
	}
}




void World::get_coastal() {
	for (int i = 0; i < int(lp.size()); i++) {
		if (lp[i].h < 0) {
			for (int j = 0; j < int(lp[i].c.size()); j++) {
				if (lp[lp[i].c[j].p].h >= 0) {
					lp[i].isCoastal = true;
				}
			}
		}
	}
}


void World::get_coastal_normale() {
	for (int i = 0; i < int(lp.size()); i++) {
		if (lp[i].isCoastal) {
			int n = 0;
			TPoint base_normale = TPoint();
			for (int j = 0; j < int(lp[i].c.size()); j++) {
				if (lp[lp[i].c[j].p].h >= 0) {
					n += 1;
					TPoint v = vector_substr(lp[lp[i].c[j].p].x, lp[i].x);
					TPoint w = vector_mult(v, lp[i].x);
					if ((vector_mult(v, lp[i].x).z < 0) ^ (dot_mult(w, project(lp[i].upd_wind_v, h)) > 0)) {
						w = vector_scale(w, -1);
					}
					base_normale = vector_add(base_normale, w);
				}
			}
			base_normale = normalize_t(base_normale);
			lp[i].coastal_normale = base_normale;
		}
	}
}


void World::get_water_speed() {
	for (int i = 0; i < int(height_groups.size()) - 1; i++) {
		int last_coast = -1;
		int group_len = height_groups[i + 1] - height_groups[i];
		int st = height_groups[i];
		for (int j = 0; j < 2 * group_len; j++) {
			int cun = st + j % group_len;
			if (lp[cun].isCoastal) {
				if (last_coast >= 0) {
					for (int k = last_coast; k <= j; k++) {
						int cu = st + k % group_len;
						int wc = st + last_coast % group_len;
						TPoint nv = normalize_t(lp[cu].upd_wind_v);
						TPoint west_coast = vector_scale(lp[wc].coastal_normale, (float)(j - k) * (j - k));
						TPoint east_coast = vector_scale(lp[cun].coastal_normale, (float)(k - last_coast) * (k - last_coast));
						TPoint strait_v = vector_scale(nv, (float)2 * (j - k) * (k - last_coast));
						lp[cu].water_v = normalize_t(vector_add(vector_add(west_coast, east_coast), strait_v));
						last_coast = j;
					}
				}
			}
		}
		if (last_coast == -1) {
			for (int j = st; j < st + group_len; j++) {
				lp[j].water_v = normalize_t(lp[j].wind_v);
			}
		}
	}
}


void World::stabilize_water_speed() {
	for (int i = 0; i < int(lp.size()); i++) {
		if (lp[i].h < 0) {
			TPoint nh = TPoint();
			int g = 0;
			for (int j = 0; j < int(lp[i].c.size()); j++) {
				int k = lp[i].c[j].p;
				if (lp[k].h < 0) {
					nh = vector_add(nh, lp[k].water_v);
					g += 1;
				}
			}
			nh = vector_scale(nh, (float)g);
			lp[i].dwater_v = nh;
		}
	}
	for (int i = 0; i < int(lp.size()); i++) {
		if (lp[i].h < 0) {
			lp[i].water_v = normalize_t(vector_add(vector_scale(lp[i].water_v, 0.7f), vector_scale(lp[i].dwater_v, 0.3f)));
		}
	}
}


TPoint World::get_wind(TPoint p, float tra, float trb) {
	if (p.z < 0) {
		TPoint pa = TPoint(p.x, p.y, -p.z);
		TPoint w = get_wind(pa, tra, trb);
		w.z *= -1;
		return w;
	}
	TPoint horn = vector_scale(vector_mult(p, h), 4.0f);
	TPoint vern = vector_mult(p, horn);
	if (p.z < sin(tra * 3.1415 / 180)) {
		return vector_add(vector_scale(horn, horWindMult), vector_scale(vern, verWindMult));
	}
	if (p.z < sin(trb * 3.1415 / 180)) {
		return vector_add(vector_scale(horn, -horWindMult), vector_scale(vern, -verWindMult));
	}
	return vector_add(vector_scale(horn, horWindMult), vector_scale(vern, verWindMult));
}


TPoint World::get_upd_wind(TPoint p) {
	if (p.z < 0) {
		TPoint pa = TPoint(p.x, p.y, -p.z);
		TPoint w = get_upd_wind(pa);
		w.z *= -1;
		return w;
	}
	TPoint horn = vector_scale(vector_mult(p, h), 4);
	TPoint vern = vector_mult(p, horn);
	if (p.z < sinV) {
		return vector_add(vector_scale(horn, -horWindMult), vector_scale(vern, -verWindMult));
	}
	if (p.z < sinVL) {
		return vector_add(vector_scale(horn, horWindMult), vector_scale(vern, verWindMult));
	}
	if (p.z < sinLXV) {
		return vector_add(vector_scale(horn, -horWindMult), vector_scale(vern, -verWindMult));
	}
	return vector_add(vector_scale(horn, horWindMult), vector_scale(vern, verWindMult));
}


float World::get_pressure(float z) {
	if (z < 0) {
		return get_pressure(-z);
	}
	if (z < 0.5) {
		return 2 * z;
	}
	if (z < sqrt(3) / 2) {
		return (sqrt(3.0f) / 2.0f - z) / (sqrt(3.0f) / 2.0f - 0.5f);
	}
	return (z - sqrt(3.0f) / 2.0f) / (1.0f - sqrt(3.0f) / 2.0f);
}





void World::initClimateColor()
{
	climateColor["Af"] = color_rgb(0, 0, 255);
	climateColor["Am"] = color_rgb(0, 120, 255);
	climateColor["Aw"] = color_rgb(70, 170, 250);
	climateColor["BWh"] = color_rgb(255, 0, 0);
	climateColor["BWk"] = color_rgb(255, 150, 150);
	climateColor["BSh"] = color_rgb(245, 165, 0);
	climateColor["BSk"] = color_rgb(255, 220, 100);
	climateColor["Csa"] = color_rgb(255, 255, 0);
	climateColor["Csb"] = color_rgb(200, 200, 0);
	climateColor["Csc"] = color_rgb(140, 140, 0);
	climateColor["Cwa"] = color_rgb(150, 255, 150);
	climateColor["Cwb"] = color_rgb(125, 225, 125);
	climateColor["Cwc"] = color_rgb(100, 200, 100);
	climateColor["Cfa"] = color_rgb(200, 255, 80);
	climateColor["Cfb"] = color_rgb(100, 255, 80);
	climateColor["Cfc"] = color_rgb(0, 255, 0);
	climateColor["Dsa"] = color_rgb(255, 0, 255);
	climateColor["Dsb"] = color_rgb(200, 0, 200);
	climateColor["Dsc"] = color_rgb(150, 50, 150);
	climateColor["Dwa"] = color_rgb(170, 175, 255);
	climateColor["Dwb"] = color_rgb(89, 120, 220);
	climateColor["Dwc"] = color_rgb(75, 80, 179);
	climateColor["Dfa"] = color_rgb(0, 255, 255);
	climateColor["Dfb"] = color_rgb(55, 200, 255);
	climateColor["Dfc"] = color_rgb(0, 125, 125);
	climateColor["mountain"] = color_rgb(101, 67, 33);
	climateColor["lake"] = color_rgb(220, 220, 255);
	climateColor["river"] = color_rgb(220, 220, 255);
	climateColor["oceanic"] = color_rgb(255, 255, 255);
}

color World::colorForZone(string z)
{
	return climateColor[z];
}

color World::colorForHeight(float h)
{
	if (h >= 0) {
		float x = log2(h + 200.0f) - log2(100.0f);
		if (x < 3) {
			x -= 1;
			return color_rgb(int(154 + x * 48), int(205 + x * 12), int(50 + x * 45));
		}
		if (x < 5) {
			x -= 3;
			return color_rgb(int(240 - x * 45), int(230 - x * 48), int(140 - x * 30));
		}
		if (rand() % 4 < 3) {
			return color_rgb(60, 38, 20);
		}
		return color_rgb(255, 255, 255);
	}
	float x = log2(-h + 200.0f) - log2(100.0f);
	if (x < 7) {
		x -= 1;
		return color_rgb(round(240 - 40 * x), round(248 - 40 * x), round(254 - 21 * x));
	}
	return color_rgb(0, 8, 128);
}

void World::paintPixel(int w, int h, color col, color(*c)[screenW][screenH])
{
	if (w >= 0 && w < screenW && h >= 0 && h < screenH) {
		(*c)[w][h] = col;
	}
}

void World::paintEllipse(int w, int h, double wr, double hr, color col, color(*c)[screenW][screenH])
{
	for (int nw = w - wr; nw <= w + wr; nw++) {
		for (int nh = h - hr; nh <= h + hr; nh++) {
			double wc = double(nw - w) / wr;
			double hc = double(nh - h) / hr;
			if (wc * wc + hc * hc < 1) {
				paintPixel(nw, nh, col, c);
			}
		}
	}
}

pair<int, int> World::mercator(TPoint a)
{
	int ny = -asin(a.z) * screenH / 3.141592f + screenH / 2 + screenMargin;
	int nx = atan2(a.y, a.x) * screenW / (2 * 3.141592f) + screenW / 2 + screenMargin;
	return make_pair(nx, ny);
}

int World::getRadii(float z)
{
	int pointNum = int(4 * pointRadii);
	if (pointRadii - z * pointRadii < 0.5 || pointRadii + z * pointRadii < 0.5) {
		pointNum = 1;
	}
	return screenW / pointNum;
}

void World::paintBMP(string fileName, color (* c)[screenW][screenH])
{
	FILE* f;
	unsigned char* img = NULL;
	int imSz = (screenW + screenMargin * 2) * (screenH + screenMargin * 2);
	int filesize = 54 + 3 * imSz;  //w is your image width, h is image height, both int
	int w = screenW + 2 * screenMargin;
	int h = screenH + 2 * screenMargin;
	img = (unsigned char*)malloc(3 * imSz);
	memset(img, 0, 3 * imSz);
	int r, g, b;
	for (int i = 0; i < screenW + screenMargin * 2; i++)
	{
		for (int j = 0; j < screenH + screenMargin * 2; j++)
		{
			int x = i; 
			int y = (screenH + screenMargin * 2 - 1) - j;
			if (i >= screenMargin && i < screenW + screenMargin && j >= screenMargin && j < screenH + screenMargin) {
				r = int((*c)[i - screenMargin][j - screenMargin].r * 1.0f);
				g = int((*c)[i - screenMargin][j - screenMargin].b * 1.0f);
				b = int((*c)[i - screenMargin][j - screenMargin].g * 1.0f);
			}
			else {
				r = 255;
				g = 255;
				b = 255;
			}
			if (r > 255) r = 255;
			if (g > 255) g = 255;
			if (b > 255) b = 255;
			if (r < 0) r = 0;
			if (g < 0) g = 0;
			if (b < 0) b = 0;
			img[(x + y * w) * 3 + 2] = (unsigned char)(r);
			img[(x + y * w) * 3 + 1] = (unsigned char)(b);
			img[(x + y * w) * 3 + 0] = (unsigned char)(g);
		}
	}

	unsigned char bmpfileheader[14] = { 'B','M', 0,0,0,0, 0,0, 0,0, 54,0,0,0 };
	unsigned char bmpinfoheader[40] = { 40,0,0,0, 0,0,0,0, 0,0,0,0, 1,0, 24,0 };
	unsigned char bmppad[3] = { 0,0,0 };

	bmpfileheader[2] = (unsigned char)(filesize);
	bmpfileheader[3] = (unsigned char)(filesize >> 8);
	bmpfileheader[4] = (unsigned char)(filesize >> 16);
	bmpfileheader[5] = (unsigned char)(filesize >> 24);

	bmpinfoheader[4] = (unsigned char)(w);
	bmpinfoheader[5] = (unsigned char)(w >> 8);
	bmpinfoheader[6] = (unsigned char)(w >> 16);
	bmpinfoheader[7] = (unsigned char)(w >> 24);
	bmpinfoheader[8] = (unsigned char)(h);
	bmpinfoheader[9] = (unsigned char)(h >> 8);
	bmpinfoheader[10] = (unsigned char)(h >> 16);
	bmpinfoheader[11] = (unsigned char)(h >> 24);

	f = fopen(fileName.c_str(), "wb");
	fwrite(bmpfileheader, 1, 14, f);
	fwrite(bmpinfoheader, 1, 40, f);
	for (int i = 0; i < h; i++)
	{
		fwrite(img + (w * (h - i - 1) * 3), 3, w, f);
		fwrite(bmppad, 1, 0, f);
	}

	free(img);
	fclose(f);
}

void World::paintMaps()
{
	for (int i = 0; i < int(lp.size()); i++) {
		pair<int, int> c = mercator(lp[i].x);
		int up = int(screenH / (2 * pointRadii * sqrt(1.03 - lp[i].x.z * lp[i].x.z)));
		int right = getRadii(lp[i].x.z);
		if (lp[i].climateType == "lake" || lp[i].climateType == "river") {
			paintEllipse(c.first, c.second, right, up, colorForHeight(-10.0), &PhysMap);
		} 
		else {
			//cout << c.first << " " << c.second << " "<< right << " " <<up << " "<<lp[i].h<<endl;
			//cout << t.r << " " << t.g << " " << t.b << endl;
			paintEllipse(c.first, c.second, right, up,colorForHeight(lp[i].h), &PhysMap);
		}
		paintEllipse(c.first, c.second, right, up, colorForZone(lp[i].climateType), &ClimMap);
	}
	for (int i = 0; i < int(regions.size()); i++) {
		TPoint t = lp[regions[i].t].x;
		pair<int, int> c = mercator(t);
		paintEllipse(c.first - 2, c.second + 4, 2, 2, color_rgb(255, 0, 0), &PhysMap);
	}
	paintBMP("pic_physical_map.bmp", &PhysMap);
	paintBMP("pic_climate_map.bmp", &ClimMap);
}


int World::init_main() {
	srand((unsigned int)time(0));
	initPlaces();
	init_height();

	for (int i = 0; i < int(lp.size()); i++) {
		lp[i].h = lp[i].dh;
		lp[i].wind_v = get_wind(lp[i].x, 38, 64);
		lp[i].winter_wind_v = get_wind(lp[i].x, 33, 61);
		lp[i].summer_wind_v = get_wind(lp[i].x, 43, 67);
		lp[i].upd_wind_v = get_upd_wind(lp[i].x);
		lp[i].air_pressure = get_pressure(lp[i].x.z);
	}


	for (int j = 0; j < 3; j++) {
		for (int i = 0; i < int(lp.size()); i++) {
			lp[i].dh = lp[i].h * 3;
		}
		for (int k = 0; k < 120; k++) {
			stabilize_height();

		}
	}
	subHeightRiver();

	get_coastal();
	get_coastal_normale();
	get_water_speed();
	for (int j = 0; j < 40; j++) {
		stabilize_water_speed();
	}

	for (int j = 0; j < int(lp.size()); j++) {
		if (lp[j].h < 0) {
			lp[j].winter_air_prec = 1;
			lp[j].summer_air_prec = 1;
		}
		else {
			lp[j].winter_air_prec = 0;
			lp[j].summer_air_prec = 0;
		}
		for (int i = 0; i < int(lp[j].c.size()); i++) {
			lp[j].c[i].water_project = project(lp[lp[j].c[i].p].water_v, lp[j].c[i].v_to);
			lp[j].c[i].wind_winter_project = project(lp[lp[j].c[i].p].winter_wind_v, lp[j].c[i].v_to);
			lp[j].c[i].wind_summer_project = project(lp[lp[j].c[i].p].summer_wind_v, lp[j].c[i].v_to);
			if (dot_mult(lp[j].c[i].water_project, lp[j].c[i].v_to) > 0) {
				lp[j].c[i].water_go = true;
			}
			if (dot_mult(lp[j].c[i].wind_winter_project, lp[j].c[i].v_to) > 0) {
				lp[j].c[i].wind_winter_go = true;
			}
			if (dot_mult(lp[j].c[i].wind_summer_project, lp[j].c[i].v_to) > 0) {
				lp[j].c[i].wind_summer_go = true;
			}
			lp[j].c[i].temp_diff = get_temp_diff(lp[j].x.z, lp[lp[j].c[i].p].x.z);
			lp[j].c[i].water_len = length(lp[j].c[i].water_project);
			lp[j].c[i].wind_summer_len = length(lp[j].c[i].wind_summer_project);
			lp[j].c[i].wind_winter_len = length(lp[j].c[i].wind_winter_project);
		}
	}



	for (int i = 0; i < 250; i++) {
		iterate_water_temp();
	}


	for (int i = 0; i < 600; i++) {
		iterate_air_temp();
	}


	get_climate();


	get_lake_flow();


	get_river_flow();


	get_rain_amount();



	for (int i = 0; i < int(lp.size()); i++) {
		if (lp[i].h > 0) {
			sorted_height.push_back(make_pair(make_pair(-lp[i].lake_nu, -lp[i].h), i));
		}
	}
	sort(sorted_height.begin(), sorted_height.end());
	get_flow();
	for (int i = 0; i < int(lp.size()); i++) {
		if (lp[i].h >= 0) {
			if (lp[i].lake_flow != -1) {
				if (lp[i].h <= lp[lp[i].lake_flow].lake_top && lp[lp[i].lake_flow].water_lake_flow > 200000) {
					lp[i].climateType = "lake";
				}
			}
			else {
				if (lp[i].summer_flow + lp[i].winter_flow > 5000) {
					lp[i].climateType = "river";
				}
			}
		}
	}
	for (int i = 0; i < int(lp.size()); i++) {
		lp[i].town_chance = get_town_chances(i);
		town_shuffle.push_back(i);
		sum_town_score += lp[i].town_chance;
	}
	random_shuffle(town_shuffle.begin(), town_shuffle.end());
	for (int i = 0; i < townNu; i++) {
		Region region_construct = Region();
		region_construct.p.clear();
		regions.push_back(region_construct);
	}
	for (int i = 0; i < int(lp.size()); i++) {
		lp[i].rG = rand_in_sphere();
		cu_town_score += lp[town_shuffle[i]].town_chance;
		while ((cu_town + sqrt(2) - 1) * sum_town_score / townNu < cu_town_score) {
			regions[cu_town].t = town_shuffle[i];
			cu_town += 1;
		}
		lp[i].ran = rand();
	}
	get_regions();
	get_goods();
	paintMaps();
	return 0;
}
