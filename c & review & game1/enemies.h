#pragma once
#ifndef __ENEMIES_H__
#define __ENEMIES_H__
#include<DxLib.h>

CONST int ENEMY_MAX = 4;
CONST int FIRE_MIN = 0;
CONST int FIRE_MAX = 3;
CONST int FIRE_STOP = 12;

enum MonsterType{
	MT_HOLI,
	MT_VERT,
	MT_DRAGON,
	MT_FIRE
};

struct EnemyStatus {
	int posx;
	int posy;
	int direction;
	int movecounter;
	BOOL living;
	MonsterType type;
};

struct FireData {
	int posx;
	int posy;
	BOOL activation;
};

extern int _firetimer;
extern int _firecounter;
extern BOOL reversion;
extern EnemyStatus _enemystatus[ENEMY_MAX];
extern FireData _firedata[FIRE_MAX];

void EnemyUpData();
void FireUpdata();

#endif