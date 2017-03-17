#pragma once
#ifndef __LODING_H__
#define __LODING_H__
#include<Dxlib.h>
#include"enemies.h"

void LoadGameImage();
BOOL LoadGameImageCheck();

struct ImageHandles {
	int player;
	int gametitleimg;
	int mapitem[ 4 ];
	int enemyholi;
	int dragon;
	int fire;
};

extern ImageHandles _imagehandles;
extern int _middlefont;
extern int _largefont;

#endif