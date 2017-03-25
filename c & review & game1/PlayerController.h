#pragma once
#ifndef __PlayerUpdata_H__
#define __PlayerUpdata_H__

#include<DxLib.h>

CONST int MOVERATE = 25;

struct PlayerStatus {
	int posx;
	int posy;
	int movecounter;
	BOOL key;
};

extern BOOL _akey_prev;
extern PlayerStatus _playerstatus;

void PlayerUpdata();
void TitleController();
void CollisionDetection();
void InitFire( int idex );

#endif