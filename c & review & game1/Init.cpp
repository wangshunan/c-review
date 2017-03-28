#include<DxLib.h>
#include"PlayerController.h"
#include"MapData.h"
#include"Init.h"
#include"enemies.h"

void InitPlayer() {
	_playerstatus.posx = _posdata.START_POS_X;
	_playerstatus.posy = _posdata.START_POS_Y;
	_playerstatus.key = FALSE;
}

void InitEnemy() {
	int c = 0;
	for( int y = 0; y < MAP_HITGHT; y++ ) {
		for( int x = 0; x < MAP_WIDTH; x++ ) {
			if ( _enemyposdata[y][x] != 0 ) {
				_enemystatus[c].posx = x;
				_enemystatus[c].posy = y;
				_enemystatus[c].direction = -1;
				_enemystatus[c].living = TRUE;
				if ( _enemyposdata[y][x] == 2 ) {
					_enemystatus[c].type = MT_DRAGON;
					InitFire( c );
				} else {
					_enemystatus[c].type = MT_HOLI;
				}
				c++;
			}
		}
	}
}

void InitFire( int idex ) {
	for( int i = FIRE_MIN; i < FIRE_MAX; i++ ) {
		_firedata[i].posx = _enemystatus[idex].posx - i - 1;
		_firedata[i].posy = _enemystatus[idex].posy;
		_firedata[i].activation = FALSE;
	}
}

void InitMap() {
	for ( int y = 0; y < MAP_HITGHT; y++ ) {
		for( int x = 0; x < MAP_WIDTH; x++ ) {
			_mapdata[y][x] = _mapdataInit[y][x];
		}
	}
}

void InitStage() {
	InitMap();
	InitPlayer();
	InitEnemy();
}