#include "DxLib.h"
#include"KeyBoardUpdata.h"

int _hold[ NUMBER_MAX ];
int _oldKey[ NUMBER_MAX ];
int _push[ NUMBER_MAX ];
char gTmpKey[ NUMBER_MAX ];

// キーの入力状態更新
void KeyboardUpdate() {
       GetHitKeyStateAll( gTmpKey ); 

	for ( int i = 0; i < NUMBER_MAX; i++ ) { 
		_push[ i ] = 0;
		if ( gTmpKey[ i ] == 1 ) {
			_hold[ i ] = 1;
			if ( _oldKey[ i ] == 0 ) {
				_oldKey[ i ] = 1;
				_push[ i ] = 1;
			} else {
				_push[ i ] = 0;
			}
		} else {
			_hold[ i ] = 0;
			_oldKey[ i ] = 0;
		}
	}
}
