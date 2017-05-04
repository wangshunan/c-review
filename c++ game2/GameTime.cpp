#include<DxLib.h>
#include"GameTime.h"

GameTimePtr GameTime::_gametime;

GameTime::GameTime(){
}

GameTime::~GameTime(){
}


void GameTime::TimeUpdata() {
	_timecount ++;
	_nowtime = _timecount;
}

void GameTime::GetGameTime( GameTimePtr &temp ) {
	if (!_gametime) {
		_gametime = GameTimePtr(new GameTime);
	}
	temp = _gametime;
}