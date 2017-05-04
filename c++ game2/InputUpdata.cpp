#include<DxLib.h>
#include"InputUpdata.h"

InputPtr Input::_inputptr;
Input::Input() {
}

Input::~Input() {

}

void Input::InputUpdata() {
	GetHitKeyStateAll( _tmpKey );
}

void Input::GetInput( InputPtr &temp ) {
	if (!_inputptr) {
		_inputptr = InputPtr( new Input );
	}
	temp = _inputptr;
}


int Input::PushKey( int key ) {
	_push = 0;
	if ( _tmpKey[ key ] == 1 ) {
		_hold = 1;
		if ( _oldKey == 0 ) {
			_oldKey = 1;
			_push = 1;
		} else {
			_push = 0;
		}
	} else {
		_hold = 0;
		_oldKey = 0;
	}

	return _push;
}

int Input::HoldKey( int key ) {
	_push = 0;
	if ( _tmpKey[ key ] == 1 ) {
		_hold = 1;
		if ( _oldKey == 0 ) {
			_oldKey = 1;
			_push = 1;
		} else {
			_push = 0;
		}
	} else {
		_hold = 0;
		_oldKey = 0;
	}

	return _hold;
}

int Input::Key( int key ) {
	return CheckHitKey( key );
}
