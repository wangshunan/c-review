#include<DxLib.h>
#include"PlayerController.h"
#include"DrawGraph.h"
#include"main.h"
#include"MapData.h"
#include"Init.h"
#include"enemies.h"

BOOL _akey_prev;
PlayerStatus _playerstatus;

void PlayerUpdata() {

	_playerstatus.movecounter++;
	_playerstatus.movecounter %= MOVERATE;

	//player移動
	int key = GetJoypadInputState( DX_INPUT_KEY_PAD1 );
	if ( _playerstatus.movecounter == 0 ) {
		int hx = _playerstatus.posx;
		int hy = _playerstatus.posy;
		float mv = 1.0f;

		if ( key & PAD_INPUT_UP )  hy -= mv;
		if ( key & PAD_INPUT_DOWN ) hy += mv;
		if ( key & PAD_INPUT_LEFT ) hx -= mv;
		if ( key & PAD_INPUT_RIGHT ) hx += mv;

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
	int key = GetJoypadInputState( DX_INPUT_KEY_PAD1 );
	//Zキーチェックして画面を切り替え
	if ( IsKeyTrigger( key ) == TRUE ) {
		_gamestate  = GAME_MAIN;
		InitStage();
	}
}


BOOL IsKeyTrigger( int key ) {
	if ( key & PAD_INPUT_A ) {
		if ( _akey_prev == FALSE ) {
			_akey_prev = TRUE;
			return TRUE;
		}
	} else {
		_akey_prev = FALSE;
	}
	return FALSE;
}