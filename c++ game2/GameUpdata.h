#pragma once
#include"smart_ptr.h"
#include"GameTime.h"
#include"InputUpdata.h"
#include"ImageLoad.h"
#include"DrawGraphUpdata.h"
#include"Player.h"

PTR( GameUpdata );

class GameUpdata{
public:
	GameUpdata();
	virtual ~GameUpdata();

	void MainGameUpdata();
protected:
	GameTimePtr _gametime;
	InputPtr _input;
	DrawPtr _drawupdata;
	PlayerUpDataPtr _playerdata;
};