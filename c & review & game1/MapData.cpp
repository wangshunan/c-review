#include<DxLib.h>
#include"MapData.h"

MapData _posdata;

int _mapdataInit[MAP_HITGHT][MAP_WIDTH] = {
		//0  1  2  3  4  5  6  7  8  9  0  1  2  3  4  5
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
		{ 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 1, 0, 1, 1, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0, 0, 3 },
		{ 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 1, 1, 1, 1 },
		{ 1, 0, 1, 1, 1, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1 },
		{ 1, 0, 1, 0, 0, 1, 0, 2, 1, 0, 0, 1, 0, 1, 0, 1 },
		{ 1, 0, 1, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 1, 0, 1 },
		{ 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1 },
		{ 1, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1 },
		{ 1, 0, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1 },
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }
};

int _mapdata[MAP_HITGHT][MAP_WIDTH];

int _enemyposdata[MAP_HITGHT][MAP_WIDTH] {
	    //0  1  2  3  4  5  6  7  8  9  0  1  2  3  4  5
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,0 ,0 ,0 ,0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,2 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,0 ,0 ,0 ,0 },
		{ 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0 ,0 ,0 ,0 ,0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0 ,0 ,0 ,0 ,0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,0 ,0 ,0 ,0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,0 ,0 ,0 ,0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,0 ,0 ,0 ,0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,0 ,0 ,0 ,0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,0 ,0 ,0 ,0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,1 ,0 ,0 ,0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,0 ,0 ,0 ,0 }
};