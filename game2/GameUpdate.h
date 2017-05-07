#pragma once
#include"smart_ptr.h"
#include"GameTime.h"
#include"InputUpdate.h"
#include"ImageLoad.h"
#include"DrawGraphUpdate.h"

PTR( GameUpdate );

class GameUpdate{
public:
	GameUpdate();
	virtual ~GameUpdate();

	void MainGameUpdate();
protected:
	GameTimePtr _gametime;
	InputPtr _input;
	DrawPtr _drawupdate;
};