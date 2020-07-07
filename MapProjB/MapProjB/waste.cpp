


sorted_height = []

class TPoint :
	x = 0
	y = 0
	z = 0


	def tpoinT(x, y, z) :
	a = TPoint()
	a.x = x
	a.y = y
	a.z = z
	return a


	def length(a) :
	return math.sqrt(a.x * a.x + a.y * a.y + a.z * a.z)


	def distance(a, b) :
	res = (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y) + (a.z - b.z) * (a.z - b.z)
	return math.sqrt(res)


	def normalize(a) :
	zer = tpoinT(0, 0, 0)
	dis = distance(a, zer)
	return tpoinT(a.x / dis, a.y / dis, a.z / dis)


	def normalize_t(a) :
	res = math.sqrt(a.x * a.x + a.y * a.y + a.z * a.z)
	if res == 0 :
		return TPoint()
		re = TPoint()
		re.x = a.x / res
		re.y = a.y / res
		re.z = a.z / res
		return re


		class Color :
		r = 0
		g = 0
		b = 0


		def color_rgb(r, g, b) :
		c = Color()
		c.r = r
		if r < 0 :
			c.r = 0
			if r > 255 :
				c.r = 255
				c.g = g
				if g < 0 :
					c.g = 0
					if g > 255 :
						c.g = 255
						c.b = b
						if b < 0 :
							c.b = 0
							if b > 255 :
								c.b = 255
								return c


								class Connection :
								p = 0
								v_to = TPoint()
								mountain_project = TPoint()
								wind_summer_project = TPoint()
								wind_winter_project = TPoint()
								water_project = TPoint()
								water_go = False
								wind_summer_go = False
								wind_winter_go = False
								temp_diff = 0
								water_len = 0
								wind_summer_len = 0
								wind_winter_len = 0


								class Place :
								x = TPoint()
								c = []
								cr = 0
								v = TPoint()
								dh = 0
								cr_type = 0
								cudh = 0
								h = 0
								wind_v = TPoint()
								upd_wind_v = TPoint()
								dwater_v = TPoint()
								water_v = TPoint()
								water_temp = 0.5
								water_dtemp = 0
								isCoastal = False
								coastal_normale = TPoint()
								winter_air_prec = 0
								winter_dair_prec = 0
								summer_air_prec = 0
								summer_dair_prec = 0
								air_pressure = 0
								climateType = ""
								winter_wind_v = TPoint()
								summer_wind_v = TPoint()
								flow_went = False
								lake_flow = -1
								lake_nu = 0
								lake_size = 0
								flow_to = 0
								basic_summer_flow = 0.0
								basic_winter_flow = 0.0
								summer_flow = 0.0
								winter_flow = 0.0
								lake_height = 10000.0
								lake_top = 0
								water_lake_flow = 0
								town_chance = 0.0
								town_nu = -1


								class Crust :
								p = []
								type = 0
								c = set()
								v = TPoint()
								dh = 0


								class Region :
								t = 0
								p = []
								marine_borders = set()
								land_borders = set()
								good = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0]


								regions = []


								def vector_mult(a, b) :
								c = TPoint()
								c.x = a.y * b.z - a.z * b.y
								c.y = -a.x * b.z + a.z * b.x
								c.z = a.x * b.y - a.y * b.x
								return c


								def dot_mult(a, b) :
								return a.x * b.x + a.y * b.y + a.z * b.z


								def project(a, b) :
								co = dot_mult(a, b) / dot_mult(b, b)
								c = TPoint()
								c.x = co * b.x
								c.y = co * b.y
								c.z = co * b.z
								return c


								def vector_add(a, b) :
								c = TPoint()
								c.x = b.x + a.x
								c.y = b.y + a.y
								c.z = b.z + a.z
								return c


								def vector_substr(a, b) :
								c = TPoint()
								c.x = a.x - b.x
								c.y = a.y - b.y
								c.z = a.z - b.z
								return c


								def vector_scale(v, c) :
								a = TPoint()
								a.x = v.x * c
								a.y = v.y * c
								a.z = v.z * c
								return a


								screenList = []

								for j in range(0, fileNu) :
									screenMatrix = []
									for i in range(0, screenH + 2 * screenMargin) :
										screenLine = []
										for i in range(0, 3 * screenW + 6 * screenMargin) :
											s = int()
											screenLine += [s]
											h = screenLine
											screenMatrix += [h]
											h = screenMatrix
											screenList += [h]


											crust = []
											lp = []
											cuHeight = -pointRadii
											lastNu = 0
											lastIn = 0
											white = color_rgb(255, 255, 255)
											switch = 1
												h = TPoint()
												h.x = 0
												h.y = 0
												h.z = 1
												height_groups = []
												sinV = math.sin(math.pi / 36)
												sinVL = math.sin(math.pi / 4)
												sinLXV = math.sin(13 * math.pi / 36)


												def paint_pixel(x, y, color, file) :
												if (x >= 0) and (y >= 0) and (x < screenW + 2 * screenMargin) and (y < screenH + 2 * screenMargin) :
													screenList[file][y][3 * x] = color.r
													screenList[file][y][3 * x + 1] = color.g
													screenList[file][y][3 * x + 2] = color.b


													def paint_rect(a, b, color, file) :
													for x in range(round(a.x), round(b.x)) :
														for y in range(round(a.y), round(b.y)) :
															paint_pixel(x, y, color, file)


															def paint_ellipse(a, b, color, file) :
															cx = (a.x + b.x) / 2
															cy = (a.y + b.y) / 2
															rx = cx - a.x
															ry = cy - a.y
															for x in range(math.trunc(a.x), math.trunc(b.x)) :
																for y in range(math.trunc(a.y), math.trunc(b.y)) :
																	if (x - cx) * (x - cx) / (rx * rx) + (y - cy) * (y - cy) / (ry * ry) < 1 :
																		paint_pixel(x, y, color, file)


																		def rand_in_sphere() :
																		while 1 :
																			x = random.random()
																			y = random.random()
																			z = random.random()
																			p = TPoint()
																			p.x = x
																			p.y = y
																			p.z = z
																			if x * x + y * y + z * z < 1:
return p


def add_connection(a, b) :
	a_connect = Connection()
	b_connect = Connection()
	a_connect.p = a
	b_connect.p = b
	lp[a].c.append(b_connect)
	lp[b].c.append(a_connect)


	def unite_crust(a, b) :
	for i in crust[b].p :
		lp[i].cr = a
		crust[a].p.append(i)
		crust[b].p.clear()
		oc = list(crust[b].c)
		for i in oc :
crust[i].c.discard(b)
crust[i].c.add(a)
crust[a].c = crust[a].c.union(crust[b].c)
crust[a].c.discard(a)
crust[a].c.discard(b)
crust[b].c.clear()


while cuHeight <= pointRadii + 0.5:
height_groups.append(len(lp))
circleHeight = cuHeight / pointRadii
circleRadii = math.sqrt(1 - circleHeight * circleHeight)
pointNum = round(4 * pointRadii)
if pointRadii - cuHeight < 0.5 or pointRadii + cuHeight < 0.5 :
	pointNum = 1
	angle = 0.0
	angleTurn = 2 * math.pi / pointNum
	while angle < 2 * math.pi - angleTurn / 2 :
		x = circleRadii * math.cos(angle)
		y = circleRadii * math.sin(angle)
		z = circleHeight
		p = tpoinT(x, y, z)
		t = Place()
		t.c = []
		t.x = p
		t.cr = len(lp)
		lp.append(t)
		cr = Crust()
		if random.random() > waterCrust:
cr.type = 1
		else:
cr.type = 0
cr.p = [len(lp) - 1]
crust.append(cr)
ap = round(angle / angleTurn)
if lastNu > 0:
ki = ap
kj = ap + 1
kk = ap - 1 + lastNu
ki %= lastNu
kj %= lastNu
kk %= lastNu
add_connection(len(lp) - 1, lastIn - lastNu + ki)
if lastNu > 1:
add_connection(len(lp) - 1, lastIn - lastNu + kj)
add_connection(len(lp) - 1, lastIn - lastNu + kk)
if angle > angleTurn / 2:
add_connection(len(lp) - 1, len(lp) - 2)
angle += angleTurn
lastNu = len(lp) - lastIn
lastIn += lastNu
if lastNu > 1:
add_connection(lastIn - 1, lastIn - lastNu)
cuHeight += 1
switch = -switch

height_groups.append(len(lp))
for i in range(0, len(lp)) :
	nc = []
	for j in lp[i].c :
		nc.append(j.p)
		crust[i].c = set(nc)
		crust[i].v = rand_in_sphere()

		free_crust = list(range(0, len(lp)))
		random.shuffle(free_crust)


		def randomize_crust_height() :
		for c in crust :
c.dh = (random.random() - 0.5) * 2 * crustRandomHeightMax
for p in lp :
p.dh += crust[p.cr].dh


def unite_random_crust(number, wateration) :
	for i in range(0, number) :
		if len(lp) - i == 300 or len(lp) - i == 200 or len(lp) - i == 100 or len(lp) - i == 50 :
			randomize_crust_height()
			if i == wateration :
				for j in lp :
j.cr_type = crust[j.cr].type
c = free_crust[len(lp) - i - 1]
k = random.choice(list(crust[c].c))
unite_crust(k, c)


def get_mountain_force_between(i) :
	d = i.mountain_project
	return ((d.x * d.x + d.y * d.y + d.z * d.z) * *1.25) * 2


	def get_mountain_force(a) :
	re = 0
	for i in lp[a].c :
		re += get_mountain_force_between(i)
		re *= mountainHeight
		re /= len(lp[a].c)
		if crust[lp[a].cr].type == 0 :
			re /= 3
			if lp[a].cr_type == 0 :
				re /= 3
				return re


				unite_random_crust(len(lp) - crustNu, len(lp) - crustNu * waterationCrustMult)
				for p in lp :
p.v = vector_mult(p.x, crust[p.cr].v)
for p in lp :
for con in p.c :
	con.to = vector_substr(p.x, lp[con.p].x)
	con.mountain_project = project(vector_substr(p.v, lp[con.p].v), con.to)


	for i in range(0, len(lp)) :
		lp[i].dh += get_mountain_force(i)
		if crust[lp[i].cr].type == 0 :
			lp[i].dh -= 2 * oceanDepth
			if lp[i].cr_type == 0 :
				lp[i].dh -= oceanDepth
			else :
				lp[i].dh += oceanDepth


				def color_for_height(h) :
				if h >= 0 :
					x = math.log2(h + 200) - math.log2(100)
					if x < 3 :
						x -= 1
						return color_rgb(round(154 + x * 48), round(205 + x * 12), round(50 + x * 45))
						if x < 7 :
							x -= 3
							return color_rgb(round(240 - x * 45), round(230 - x * 48), round(140 - x * 30))
							return color_rgb(60, 38, 20)
							x = math.log2(-h + 200) - math.log2(100)
							if x < 7 :
								x -= 1
								return color_rgb(round(240 - 40 * x), round(248 - 40 * x), round(254 - 21 * x))
								return color_rgb(0, 8, 128)


								def mercator(a) :
								ny = -math.asin(a.z) * screenH / math.pi + screenH / 2 + screenMargin
								nx = math.atan2(a.y, a.x) * screenW / (2 * math.pi) + screenW / 2 + screenMargin
								return Point(round(nx), round(ny))


								def get_radii(z) :
								pointNum = round(4 * pointRadii)
								if pointRadii - z * pointRadii < 0.5 or pointRadii + z * pointRadii < 0.5 :
									pointNum = 1
									return screenW / pointNum


									def mod(a) :
									if a > 0:
return a
return -a


def stabilize_height() :
	for p in lp :
nh = 0.0
p.cudh = p.dh * conservativeHeight
for j in p.c :
	nh += lp[j.p].h - p.h
	nh /= len(p.c)
	p.cudh += nh
	for p in lp :
p.h = p.cudh / 10 + 9 * p.h / 10


def get_wind(p, tra, trb) :
	if p.z < 0 :
		pa = tpoinT(p.x, p.y, -p.z)
		w = get_wind(pa, tra, trb)
		w.z *= -1
		return w
		horn = vector_scale(vector_mult(p, h), 4)
		vern = vector_mult(p, horn)
		if p.z < math.sin(tra * math.pi / 180) :
			return vector_add(vector_scale(horn, 0.5), vector_scale(vern, 0.5))
			if p.z < math.sin(trb * math.pi / 180) :
				return vector_add(vector_scale(horn, -0.5), vector_scale(vern, -0.5))
				return vector_add(vector_scale(horn, 0.5), vector_scale(vern, 0.5))


				def get_upd_wind(p) :
				if p.z < 0 :
					pa = tpoinT(p.x, p.y, -p.z)
					w = get_upd_wind(pa)
					w.z *= -1
					return w
					horn = vector_scale(vector_mult(p, h), 4)
					vern = vector_mult(p, horn)
					if p.z < sinV:
return vector_add(vector_scale(horn, -0.5), vector_scale(vern, -0.5))
if p.z < sinVL :
	return vector_add(vector_scale(horn, 0.5), vector_scale(vern, 0.5))
	if p.z < sinLXV :
		return vector_add(vector_scale(horn, -0.5), vector_scale(vern, -0.5))
		return vector_add(vector_scale(horn, 0.5), vector_scale(vern, 0.5))


		def get_pressure(z) :
		if z < 0 :
			return get_pressure(-z)
			if z < 0.5 :
				return 2 * z
				if z < math.sqrt(3) / 2 :
					return (math.sqrt(3) / 2 - z) / (math.sqrt(3) / 2 - 0.5)
					return (z - math.sqrt(3) / 2) / (1 - math.sqrt(3) / 2)


					def get_coastal() :
					for p in lp :
if p.h < 0 :
	for np in p.c :
		if lp[np.p].h >= 0 :
			p.isCoastal = True


			def get_coastal_normale() :
			for p in lp :
if p.isCoastal :
	n = 0
	base_normale = TPoint()
	for np in p.c :
		if lp[np.p].h >= 0 :
			n += 1
			v = vector_substr(lp[np.p].x, p.x)
			w = vector_mult(v, p.x)
			if (vector_mult(v, p.x).z < 0) ^ (dot_mult(w, project(p.upd_wind_v, h)) > 0) :
				w = vector_scale(w, -1)
				base_normale = vector_add(base_normale, w)
				base_normale = normalize_t(base_normale)
				p.coastal_normale = base_normale


				def get_water_speed() :
				for i in range(0, len(height_groups) - 1) :
					last_coast = -1
					group_len = height_groups[i + 1] - height_groups[i]
					st = height_groups[i]
					for j in range(0, 2 * group_len) :
						cun = st + j % group_len
						if lp[cun].isCoastal :
							if last_coast >= 0 :
								for k in range(last_coast, j + 1) :
									cu = st + k % group_len
									wc = st + last_coast % group_len
									nv = normalize_t(lp[cu].upd_wind_v)
									west_coast = vector_scale(lp[wc].coastal_normale, (j - k) * (j - k))
									east_coast = vector_scale(lp[cun].coastal_normale, (k - last_coast) * (k - last_coast))
									strait_v = vector_scale(nv, 2 * (j - k) * (k - last_coast))
									lp[cu].water_v = normalize_t(vector_add(vector_add(west_coast, east_coast), strait_v))
									last_coast = j
									if last_coast == -1:
for j in range(st, st + group_len) :
	lp[j].water_v = normalize_t(lp[j].wind_v)


	def stabilize_water_speed() :
	for p in lp :
if p.h < 0 :
	nh = TPoint()
	g = 0
	for j in p.c :
		if lp[j.p].h < 0 :
			nh = vector_add(nh, lp[j.p].water_v)
			g += 1
			nh = vector_scale(nh, g)
			p.dwater_v = nh
			for p in lp :
if p.h < 0 :
	p.water_v = normalize_t(vector_add(vector_scale(p.water_v, 0.7), vector_scale(p.dwater_v, 0.3)))


	def get_temp_diff(za, zb) :
	a = za
	b = zb
	if a < 0 :
		a *= -1
		if b < 0 :
			b *= -1
			a = 6 * math.asin(a) / math.pi
			b = 6 * math.asin(b) / math.pi
			return b - a


			def iterate_water_temp() :
			for p in lp :
p.water_dtemp = 0
if p.h < 0 :
	sumT = 0
	sumL = 0
	for np in p.c :
		if lp[np.p].h < 0 :
			if np.water_go :
				t = lp[np.p].water_temp - np.temp_diff
				lv = np.water_len
				sumT += t * lv
				sumL += lv
				if sumL > 0.01:
p.water_dtemp = sumT / sumL
				else:
p.water_dtemp = p.water_temp
for p in lp :
p.water_temp = 2 * p.water_temp / 3 + p.water_dtemp / 3


def iterate_air_temp() :
	for po in lp :
po.summer_dair_prec = 0
po.winter_dair_prec = 0
sumPW = 0
sumPS = 0
sumLW = 0
sumLS = 0
for np in po.c:
if not np.wind_summer_go and not np.wind_winter_go :
	continue
	wlv = np.wind_winter_len
	slv = np.wind_summer_len
	if np.wind_winter_go :
		wp = lp[np.p].winter_air_prec
		sumPW += wp * wlv
		sumLW += wlv
		if np.wind_summer_go :
			sp = lp[np.p].summer_air_prec
			sumPS += sp * slv
			sumLS += slv
			if sumLS > 0.01:
sumPS = sumPS / sumLS
			else:
sumPS = po.summer_air_prec
if sumLW > 0.01:
sumPW = sumPW / sumLW
else :
	sumPW = po.winter_air_prec
	sumPW = 0.98 * sumPW + 0.02 * (1 - po.air_pressure)
	sumPS = 0.98 * sumPS + 0.02 * (1 - po.air_pressure)
	if po.h < 0 :
		sumPW = 0.94 * sumPW + 0.045 + 0.015 * po.water_temp
		sumPS = 0.94 * sumPS + 0.045 + 0.015 * po.water_temp
	else:
perP = po.h * po.h / 30000000
if perP > 1:
perP = 1
sumPW = (1 - perP) * sumPW
sumPS = (1 - perP) * sumPS
if sumPW < 0 :
	sumPW = 0
	if sumPS < 0 :
		sumPS = 0
		po.winter_dair_prec = sumPW
		po.summer_dair_prec = sumPS
		for po in lp :
po.winter_air_prec = 2 * po.winter_air_prec / 3 + po.winter_dair_prec / 3
po.summer_air_prec = 2 * po.summer_air_prec / 3 + po.summer_dair_prec / 3


def color_for_zone(z) :
	if z == "Af" :
		return color_rgb(0, 0, 255)
		if z == "Am" :
			return color_rgb(0, 120, 255)
			if z == "Aw" :
				return color_rgb(70, 170, 250)
				if z == "BWh" :
					return color_rgb(255, 0, 0)
					if z == "BWk" :
						return color_rgb(255, 150, 150)
						if z == "BSh" :
							return color_rgb(245, 165, 0)
							if z == "BSk" :
								return color_rgb(255, 220, 100)
								if z == "Csa" :
									return color_rgb(255, 255, 0)
									if z == "Csb" :
										return color_rgb(200, 200, 0)
										if z == "Csc" :
											return color_rgb(140, 140, 0)
											if z == "Cwa" :
												return color_rgb(150, 255, 150)
												if z == "Cwb" :
													return color_rgb(125, 225, 125)
													if z == "Cwc" :
														return color_rgb(100, 200, 100)
														if z == "Cfa" :
															return color_rgb(200, 255, 80)
															if z == "Cfb" :
																return color_rgb(100, 255, 80)
																if z == "Cfc" :
																	return color_rgb(0, 255, 0)
																	if z == "Dsa" :
																		return color_rgb(255, 0, 255)
																		if z == "Dsb" :
																			return color_rgb(200, 0, 200)
																			if z == "Dsc" :
																				return color_rgb(150, 50, 150)
																				if z == "Dwa" :
																					return color_rgb(170, 175, 255)
																					if z == "Dwb" :
																						return color_rgb(89, 120, 220)
																						if z == "Dwc" :
																							return color_rgb(75, 80, 179)
																							if z == "Dfa" :
																								return color_rgb(0, 255, 255)
																								if z == "Dfb" :
																									return color_rgb(55, 200, 255)
																									if z == "Dfc" :
																										return color_rgb(0, 125, 125)
																										if z == "mountain" :
																											return color_rgb(101, 67, 33)
																											if z == "lake" :
																												return color_rgb(220, 220, 255)
																												if z == "river" :
																													return color_rgb(220, 220, 255)
																													return color_rgb(255, 255, 255)


																													def get_climate() :
																													for p in lp :
if p.h < 0 :
	p.climateType = "oceanic"
	continue
	if p.h > 1500 :
		p.climateType = "mountain"
		continue
		air_prec = (p.summer_air_prec + p.winter_air_prec) / 2
		max_prec = max(p.summer_air_prec, p.winter_air_prec)
		latitude = math.asin(p.x.z) * 180 / math.pi
		climate = ""
		if latitude < 0:
latitude = -latitude
if latitude - 2 * air_prec < 22 and max_prec > 0.5 :
	if max_prec > 0.7:
climate = "Af"
	else :
		if max_prec + air_prec / 2 > 0.9:
climate = "Am"
		else :
			climate = "Aw"
else:
if (latitude + 2 * air_prec < 50 and air_prec * 40 + latitude < 52) or latitude - 2 * air_prec < 22 :
	climate = "B"
	if air_prec * 40 + latitude < 44 :
		climate += "W"
	else :
		climate += "S"
		if latitude + 10 * max_prec < 39 :
			climate += "h"
		else :
			climate += "k"
else:
if latitude - 2 * air_prec < 54 and (max_prec > 0.6 or air_prec > 0.55) :
	climate = "C"
	if p.winter_air_prec - p.summer_air_prec > 0.15:
climate += "s"
	else :
		if p.winter_air_prec - p.summer_air_prec < -0.15 :
			climate += "w"
		else :
			climate += "f"
			if max_prec * 80 - latitude > 10 :
				climate += "a"
			else :
				if max_prec * 80 - latitude > -10:
climate += "b"
				else :
					climate += "c"
else:
climate = "D"
if p.winter_air_prec - p.summer_air_prec > 0.15:
climate += "s"
else :
	if p.winter_air_prec - p.summer_air_prec < -0.15 :
		climate += "w"
	else :
		climate += "f"
		if max_prec * 50 - latitude > -20 :
			climate += "a"
		else :
			if max_prec * 50 - latitude > -35:
climate += "b"
			else :
				climate += "c"
				p.climateType = climate


				lake_dfs = []


				def randint() :
				return random.randint(-(2 * *31) + 1, 2 * *31 - 1)


				def dfs_lake(cu, lake_in, h, lakes) :
				print(lp[cu].h, lake_in, lakes, "dfs_lake")
				lp[cu].flow_went = True
				lp[cu].lake_flow = lake_in
				lp[lake_in].lake_size += 1
				lp[cu].lake_nu = lakes + 1
				if len(lake_dfs) < lakes + 2:
lake_dfs.append(bintrees.RBTree())
lake_dfs[lakes + 1].insert((lp[cu].h, cu), randint())
for c in lp[cu].c :
	if lp[c.p].flow_went or lp[c.p].h < 0 or lp[c.p].h > h :
		continue
		dfs_lake(c.p, lake_in, h, lakes)


		def bfs_flow(cu, lakes) :
		print(lp[cu].h, lakes, "bfs_flow")
		if lp[cu].flow_went :
			return
			lp[cu].flow_went = True
			lp[cu].lake_nu = lakes
			for c in lp[cu].c :
				if lp[c.p].flow_went or lp[c.p].h < 0 :
					continue
					if lp[c.p].h < lp[cu].h :
						dfs_lake(c.p, cu, lp[cu].h, lakes)
					else :
						lake_dfs[lakes].insert((lp[c.p].h, c.p), randint())


						def get_lake_flow() :
						cu_row = 0
						fi = bintrees.RBTree()
						for i in range(0, len(lp)) :
							if lp[i].isCoastal :
								fi.insert((lp[i].h, i), randint())
								lake_dfs.append(fi)
								while True :
									if not lake_dfs[cu_row].is_empty() :
										fi = lake_dfs[cu_row].__min__()[0]
										lake_dfs[cu_row].discard(fi)
										bfs_flow(fi[1], cu_row)
									else :
										if len(lake_dfs) > cu_row + 1:
cu_row += 1
										else :
											return


											def get_river_flow() :
											for p in lp :
if p.h >= 0 :
	valid = []
	for c in p.c :
		if lp[c.p].h < p.h and lp[c.p].lake_nu <= p.lake_nu :
			valid.append(c.p)
			if len(valid) > 0 :
				p.flow_to = random.choice(valid)
			else :
				p.flow_to = p.lake_flow


				def get_basic_flow(prec) :
				return 200 * *prec


				def get_rain_amount() :
				for p in lp :
if p.h >= 0 :
	if p.climateType != "mountain" :
		p.basic_summer_flow = get_basic_flow(p.summer_air_prec)
		p.basic_winter_flow = get_basic_flow(p.winter_air_prec)
	else :
		if p.x.z < 0.5 and p.x.z > -0.5 :
			p.basic_summer_flow = get_basic_flow(0.95)
			p.basic_winter_flow = get_basic_flow(0.95)
		else :
			p.basic_summer_flow = get_basic_flow(1)
			p.basic_winter_flow = get_basic_flow(0.8)


			def get_flow() :
			for p in sorted_height :
i = p[2]
lp[i].summer_flow += lp[i].basic_summer_flow
lp[i].winter_flow += lp[i].basic_winter_flow
est = lp[i].flow_to
if lp[i].water_lake_flow > 0.1:
oz_h = math.sqrt(lp[i].water_lake_flow) * 100 * \
(lp[i].summer_air_prec + lp[i].winter_air_prec) / lp[i].lake_size
if lp[i].lake_height + oz_h >= lp[i].h:
lp[i].lake_top = lp[i].h
lp[i].summer_flow += lp[i].water_lake_flow
lp[i].winter_flow += lp[i].water_lake_flow
else:
lp[i].lake_top = lp[i].lake_height + oz_h
if lp[i].h > lp[est].h:
if lp[i].x.z * lp[i].x.z > 0:
lp[est].summer_flow += lp[i].summer_flow
lp[est].winter_flow += lp[i].winter_flow
else :
	lp[est].summer_flow += lp[i].winter_flow
	lp[est].winter_flow += lp[i].summer_flow
else:
lp[est].water_lake_flow += lp[i].winter_flow / 2 + lp[i].summer_flow / 2
lp[est].lake_height = min(lp[est].lake_height, lp[i].h)


def climate_town_chance(c) :
	if c == "mountain" :
		return 5.0
		if c == "Af" :
			return 1.0
			if c[0] == 'A' :
				return 5.0
				if c == "BWh" :
					return 1.0
					if c == "BSk" :
						return 10.0
						if c[0] == 'B' :
							return 5.0
							if c[0] == 'C' and c[1] == 's' :
								return 150.0
								if c[0] == 'C' and c[2] == 'a' :
									return 20.0
									if c[0] == 'C' :
										return 50.0
										if c[2] == 'c' :
											return 1.0
											return 20.0


											def get_town_chances(i) :
											c = lp[i].climateType
											if c == "river" or c == "lake" or c == "oceanic" :
												return 0
												chance = climate_town_chance(c)
												near_sea = False
												near_river = False
												near_lake = False
												for co in lp[i].c:
cl = lp[co.p].climateType
if cl == "river" :
	near_river = True
	if cl == "oceanic" :
		near_sea = True
		if cl == "lake" :
			near_lake = True
			if near_river and c[0] == 'B' :
				return 200
				if near_river and c[0] == 'A' :
					return 75
					if near_sea and near_river :
						return max(chance * 2 + 100, 150)
						if near_river :
							return chance + 50
							if near_lake :
								return chance + 30
								if near_sea :
									return max(chance * 2, 50)
									if lp[i].winter_flow + lp[i].summer_flow > 400:
return chance + 20
return chance


bfs_region_vertices = []


def bfs_regions(cu_in) :
	p = int(bfs_region_vertices[cu_in][0])
	print(p)
	region = int(bfs_region_vertices[cu_in][1])
	for io in lp[p].c :
		if lp[io.p].town_nu == -1 and random.random() > 0.5:
lp[io.p].town_nu = region
regions[region].p.append(int(io.p))
bfs_region_vertices.append((int(io.p), region))
if lp[io.p].town_nu >= 0 :
	l = int(lp[io.p].town_nu)
	if lp[io.p].h < 0 or lp[io.p].climateType == "river" or lp[io.p].climateType == "lake" :
		regions[region].marine_borders.add(l)
		regions[l].marine_borders.add(region)
	else :
		regions[region].land_borders.add(l)
		regions[l].land_borders.add(region)


		def get_regions() :
		for i in range(0, len(regions)) :
			if lp[regions[i].t].town_nu == -1 :
				k = int(i)
				lp[regions[i].t].town_nu = k
				regions[i].p.append(regions[i].t)
				bfs_region_vertices.append((regions[i].t, k))
				cuIn = 0
				while cuIn < len(bfs_region_vertices) :
					bfs_regions(cuIn)
					cuIn += 1

					#Grain
					#Meat
					#Wood
					#Horse
					#Clay
					#Borealis goods
					#Australis goods
					#Occidentalis goods
					#Orientalis goods
					#Mountain goods


					def is_water(i) :
					c = lp[i].climateType
					if c == "oceanic" or c == "lake" or c == "river" :
						return True
						return False


						def get_goods() :
						for r in regions :
for i in r.p :
	if not is_water(i) :
		c = lp[i].climateType
		for co in lp[i].c :
			if lp[co.p].climateType == "river" :
				r.good[1] += 10
				r.good[4] += 10
				if c[0] == 'B' :
					d = lp[co.p].summer_flow - lp[co.p].winter_flow
					if d < 0 :
						d = -d
						r.good[0] += d + 15
						if c[0] == 'C' :
							r.good[0] += 20
							if lp[co.p].climateType == "lake" :
								r.good[1] += 15
								r.good[4] += 20
								if lp[co.p].climateType == "oceanic" :
									r.good[1] += 50 * *(1 - lp[co.p].water_temp)
									if c == "Aw" :
										r.good[0] += 2
										r.good[2] += 2
										r.good[6] += 5
										continue
										if c[0] == 'A' :
											r.good[0] += 1
											r.good[2] += 3
											r.good[6] += 5
											continue
											if c == "BWh" :
												continue
												if c[0] == 'B' :
													r.good[1] += 2
													r.good[3] += 5
													continue
													if c[0] == 'C' and c[1] == 's' :
														r.good[0] += 15
														r.good[7] += 7
														continue
														if c[0] == 'C' and c[2] == 'a' :
															r.good[0] += 8
															r.good[2] += 6
															r.good[8] += 5
															continue
															if c[0] == 'C' :
																r.good[0] += 4
																r.good[1] += 4
																r.good[2] += 4
																r.good[3] += 1
																r.good[7] += 3
																continue
																if c[0] == 'D' and c[2] == 'a':
r.good[1] += 4
r.good[3] += 5
continue
if c[0] == 'D' and c[2] == 'b' :
	r.good[0] += 2
	r.good[1] += 3
	r.good[2] += 4
	r.good[3] += 2
	r.good[5] += 3
	continue
	if c[0] == 'D':
r.good[2] += 5
r.good[5] += 7
continue
if c == "mountain" :
	r.good[1] += 4
	r.good[2] += 4
	r.good[9] += 5
	continue


	def main() :
	for p in lp :
c = mercator(p.x)
up = math.ceil(screenH / (2 * pointRadii * math.sqrt(1.03 - p.x.z * p.x.z)))
right = get_radii(p.x.z)
d = Point(c.x, c.y)
d.y += up
d.x += right
c.y -= up
c.x -= right
if p.climateType == "lake" or p.climateType == "river":
paint_ellipse(c, d, color_for_height(-10.0), 0)
else:
paint_ellipse(c, d, color_for_height(p.h), 0)
paint_ellipse(c, d, color_for_zone(p.climateType), 2)
for t in regions :
p = lp[t.t]
c = mercator(p.x)
d = Point(c.x, c.y)
d.y += 6
c.y += 3
c.x -= 3
paint_ellipse(c, d, color_rgb(255, 0, 0), 0)
for i in range(0, fileNu) :
	for q in range(-8, 9) :
		nq = screenMargin + screenH / 2 - screenH * q / 18
		ncolor = color_rgb(100, 100, 100)
		if q == 0 :
			ncolor = color_rgb(255, 0, 0)
			paint_rect(Point(0, nq), Point(screenW + 2 * screenMargin, nq + 1), ncolor, i)
			paint_rect(Point(0, 0), Point(screenMargin, screenH + 2 * screenMargin), white, i)
			paint_rect(Point(0, 0), Point(screenW + 2 * screenMargin, screenMargin + screenH / 10), white, i)
			paint_rect(Point(screenW + screenMargin, 0), Point(screenW + 2 * screenMargin, screenH + 2 * screenMargin),
				white, i)
			paint_rect(Point(0, screenH + screenMargin - screenH / 10),
				Point(screenW + 2 * screenMargin, screenH + 2 * screenMargin), white, i)


			print("hello")
			for p in lp :
p.h = p.dh
p.wind_v = get_wind(p.x, 38, 64)
p.winter_wind_v = get_wind(p.x, 33, 61)
p.summer_wind_v = get_wind(p.x, 43, 67)
p.upd_wind_v = get_upd_wind(p.x)
p.air_pressure = get_pressure(p.x.z)


for j in range(0, 3) :
	for p in lp :
p.dh = p.h * 3
for i in range(0, 40) :
	stabilize_height()

	get_coastal()
	get_coastal_normale()
	get_water_speed()
	for j in range(0, 10) :
		stabilize_water_speed()


		for p in lp :
if p.h < 0 :
	p.winter_air_prec = 1
	p.summer_air_prec = 1
else :
	p.winter_air_prec = 0
	p.summer_air_prec = 0
	for i in range(0, len(p.c)) :
		p.c[i].water_project = project(lp[p.c[i].p].water_v, p.c[i].to)
		p.c[i].wind_winter_project = project(lp[p.c[i].p].winter_wind_v, p.c[i].to)
		p.c[i].wind_summer_project = project(lp[p.c[i].p].summer_wind_v, p.c[i].to)
		if dot_mult(p.c[i].water_project, p.c[i].to) > 0:
p.c[i].water_go = True
if dot_mult(p.c[i].wind_winter_project, p.c[i].to) > 0:
p.c[i].wind_winter_go = True
if dot_mult(p.c[i].wind_summer_project, p.c[i].to) > 0:
p.c[i].wind_summer_go = True
p.c[i].temp_diff = get_temp_diff(p.x.z, lp[p.c[i].p].x.z)
p.c[i].water_len = length(p.c[i].water_project)
p.c[i].wind_summer_len = length(p.c[i].wind_summer_project)
p.c[i].wind_winter_len = length(p.c[i].wind_winter_project)


for i in range(0, 40) :
	iterate_water_temp()


	for i in range(0, 120) :
		iterate_air_temp()

		get_climate()
		get_lake_flow()
		get_river_flow()
		get_rain_amount()

		town_shuffle = []
		sum_town_score = 0.0
		cu_town_score = 0.0
		cu_town = 0

		for i in range(0, len(lp)) :
			if lp[i].h > 0:
sorted_height.append((-lp[i].lake_nu, -lp[i].h, i))
sorted_height.sort()
get_flow()
for p in lp :
if p.h >= 0 :
	if p.lake_flow != -1 :
		if p.h <= lp[p.lake_flow].lake_top and lp[p.lake_flow].water_lake_flow > 800:
p.climateType = "lake"
		else :
			if p.summer_flow + p.winter_flow > 1600:
p.climateType = "river"
for i in range(0, len(lp)) :
	lp[i].town_chance = get_town_chances(i)
	town_shuffle.append(i)
	sum_town_score += lp[i].town_chance
	random.shuffle(town_shuffle)
	for i in range(0, townNu) :
		region_construct = Region()
		region_construct.p = []
		regions.append(region_construct)
		for i in range(0, len(lp)) :
			cu_town_score += lp[town_shuffle[i]].town_chance
			while (cu_town + math.sqrt(2) - 1) * sum_town_score / townNu < cu_town_score :
				regions[cu_town].t = town_shuffle[i]
				cu_town += 1
				get_regions()
				for r in regions :
r.marine_borders = list(r.marine_borders)
r.land_borders = list(r.land_borders)
print(len(r.p))
print("gh")
get_goods()


print("stab")
main()
f = open('physical_map.png', 'wb')
wa = png.Writer(screenW + 2 * screenMargin, screenH + 2 * screenMargin, greyscale = False)
wa.write(f, screenList[0])
f.close()
f = open('climate.png', 'wb')
wc = png.Writer(screenW + 2 * screenMargin, screenH + 2 * screenMargin, greyscale = False)
wc.write(f, screenList[2])
f.close()
