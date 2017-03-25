#include<DxLib.h>
#include"enemies.h"
#include"PlayerController.h"
#include"MapData.h"

EnemyStatus _enemystatus[ENEMY_MAX];
FireData _firedata[FIRE_MAX];
int _firetimer = 0;
int _firecounter = 0;
BOOL reversion = FALSE;

void EnemyUpData() {
	for( int i = 0; i < ENEMY_MAX; i++ ) {
		if ( _enemystatus[i].type == MT_DRAGON ) {
			continue;
		}

		if ( _playerstatus.movecounter == 0 ) {
			int ex = _enemystatus[i].posx;
			int ey = _enemystatus[i].posy;

			ex +=_enemystatus[i].direction;

			if ( _mapdata[ey][ex] == MPITEM_BACK ) {
				_enemystatus[i].posx = ex;
				_enemystatus[i].posy = ey;
			} else {
				_enemystatus[i].direction *= -1;
			}
		}
	}
}

void FireUpdata() {
	_firetimer++;
	_firetimer %= FIRE_STOP;
	if ( _firetimer == 0 ) {
		if ( reversion == FALSE ) {
			_firedata[_firecounter].activation = TRUE;
			_firecounter++;
		}
		if ( reversion == TRUE ) {
			_firedata[_firecounter].activation = FALSE;
			_firecounter--;
		}
		if ( _firecounter > FIRE_MAX ) {
			reversion = TRUE;
			_firecounter = FIRE_MAX;
		} else if ( _firecounter < FIRE_MIN ) {
			_firecounter = 0;
			reversion = FALSE;
		}
	}
}