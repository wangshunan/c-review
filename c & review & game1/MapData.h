#pragma once
#ifndef __MAPDATA_H__
#define __MAPDATA_H_
#include<DxLib.h>

CONST int IMG_CHIPSIZE = 50;
CONST int MAP_WIDTH = 16;
CONST int MAP_HITGHT = 12;

enum MapItem{
	MPITEM_BACK,MPITEM_ROCK, MPITEM_KEY, MPITEM_GOAL, MPITEM_ENEMY,MPITEM_DRAGON
};

struct MapData{
	CONST int START_POS_X = 1;
	CONST int START_POS_Y = 1;
	CONST int GOAL_POS_X = 15;
	CONST int GOAL_POS_Y = 3;
	CONST int KEY_POS_X = 7;
	CONST int KEY_POS_Y = 6;
};
extern int _mapdataInit[MAP_HITGHT][MAP_WIDTH];
extern int _mapdata[MAP_HITGHT][MAP_WIDTH];
extern MapData _posdata;
extern int _enemyposdata[MAP_HITGHT][MAP_WIDTH];

#endif