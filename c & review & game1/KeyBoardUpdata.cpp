#include "DxLib.h"
#include"KeyBoardUpdata.h"

int _hold[ NUMBER_MAX ];
int _push[ NUMBER_MAX ];

char tmpKey[ NUMBER_MAX ];
int oldKey[ NUMBER_MAX ];

// キーの入力状態更新
void KeyboardUpdate() {
    GetHitKeyStateAll( tmpKey ); 

	for ( int i = 0; i < NUMBER_MAX; i++ ) { 
		_push[ i ] = 0;
		if ( tmpKey[ i ] == 1 ) {
			_hold[ i ] = 1;
			if ( oldKey[ i ] == 0 ) {
				oldKey[ i ] = 1;
				_push[ i ] = 1;
			} else {
				_push[ i ] = 0;
			}
		} else {
			_hold[ i ] = 0;
			oldKey[ i ] = 0;
		}
	}
}
