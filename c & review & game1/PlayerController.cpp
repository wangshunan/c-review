#include<DxLib.h>
#include"PlayerController.h"
#include"DrawGraph.h"
#include"main.h"
#include"MapData.h"
#include"Init.h"
#include"enemies.h"
#include"KeyBoardUpdata.h"

BOOL _akey_prev;
PlayerStatus _playerstatus;

void PlayerUpdata() {

	_playerstatus.movecounter++;
	_playerstatus.movecounter %= MOVERATE;

	int hx = _playerstatus.posx;
	int hy = _playerstatus.posy;
	float mv = 1.0f;

	if ( _push[ KEY_INPUT_UP ] == 1 ) {
		hy -= mv;
	} else 
	if ( _push[ KEY_INPUT_DOWN ] == 1 ) {
		hy += mv;
	} else
	if ( _push[ KEY_INPUT_LEFT ] == 1 ){
		hx -= mv;
	} else
	if ( _push[ KEY_INPUT_RIGHT ] == 1 ) {
		hx += mv;
	}
	if ( _mapdata[hy][hx] == MPITEM_KEY ) {
		_mapdata[hy][hx] = MPITEM_BACK;
		_playerstatus.key = TRUE;
	}

	if ( _mapdata[hy][hx] == MPITEM_GOAL && _playerstatus.key == TRUE ) {
		_mapdata[hy][hx] = MPITEM_BACK;
		_gamestate = GAME_CLEAR;
		_timerstart = _lasttime;
	}

	if ( _mapdata[hy][hx] == MPITEM_BACK ) {
		_playerstatus.posx = hx;
		_playerstatus.posy = hy;
	}
}

void CollisionDetection() {
	for ( int i = 0; i < ENEMY_MAX; i++ ) {
		if ( _playerstatus.posx == _enemystatus[i].posx && 
			 _playerstatus.posy == _enemystatus[i].posy) {
			_gamestate = GAME_OVER;
			_timerstart = _lasttime;
		}
	}
	for ( int i = 0; i < FIRE_MAX; i++ ) {
		if ( _playerstatus.posx == _firedata[i].posx && 
			 _playerstatus.posy == _firedata[i].posy) {
			if ( _firedata[i].activation == TRUE ) {
				_gamestate = GAME_OVER;
				_timerstart = _lasttime;
			}
		}
	}
}

void TitleController() {
	//Zキーチェックして画面を切り替え
	if ( _push[ KEY_INPUT_Z ] == 1 ) {
		_gamestate  = GAME_MAIN;
		InitStage();
	}
}