#pragma once
#include"smart_ptr.h"

PTR( GameTime );

class GameTime{
public:
	GameTime();
	virtual ~GameTime();

	void GetGameTime( GameTimePtr &temp);
	void TimeUpdata();
	int _nowtime;
private:
	int _timecount;
	static GameTimePtr _gametime;
};