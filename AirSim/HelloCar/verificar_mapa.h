#pragma once

#include <stdlib.h>
#include "vehicles/car/api/CarRpcLibClient.hpp"
#include "common/common_utils/FileSystem.hpp"
#include <iostream>
#include <chrono>
#include <fstream>
#include <math.h>
#include <sstream>
#include <cstring>
#include <string>
#include "Waypoints.h"
#include "LateralControl.h"
#include "LongitudinalControl.h"
#include "pnmfile.h"
using namespace std;
using namespace segment;



image<uchar>* loadmap(const char *mapapbm) {
		image<uchar>* mapa = loadPBM(mapapbm);
		return mapa;
	}
image<uchar>* newmap(const char *mapapbm) {
	image<uchar>* mapa = new segment::image<unsigned char>(300, 300, false);
		mapa->init(1);
		return mapa;
	}


void savemap(image<uchar>* mapa, int x, int y){
	mapa->access[150 + x][150 + y] = 0;
}

bool offroad(image<uchar>* mapa, int x, int y){
	if (mapa->access[150 + x][150 + y] == 1) {
		return true;
		
	}
	else return false;
}
