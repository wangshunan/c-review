#pragma once
#include"smart_ptr.h"

PTR( Input ); 

class Input{
public:
	Input();
	virtual ~Input();
	void InputUpdate();
	int _getPushKey( int number ) { return PushKey( number ); }
	int _getHoldKey( int number ) { return HoldKey( number ); }
	int _getKey( int number ) { return Key( number ); }
private:
	int _push;
	int _hold;
	int _oldKey;
	char _tmpKey[ 256 ];

	int PushKey( int key );
	int HoldKey( int key );
	int Key( int key );
};