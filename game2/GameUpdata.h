#pragma once
#include"smart_ptr.h"
#include"GameTime.h"
#include"InputUpdata.h"
#include"ImageLoad.h"
#include"DrawGraphUpdata.h"
#include"Player.h"
#include"GameLogic.h"
#include"MenuController.h"

PTR( GameUpdata );

class GameUpdata : public GameState {
public:
	GameUpdata();
	virtual ~GameUpdata();

	void MainGameUpdata();
	void InputUpdata();
protected:
	GameTimePtr _gametime;
	InputPtr _input;
	DrawPtr _drawupdata;
	PlayerUpDataPtr _playerdata;
	GameLogicPtr _gamelogic;
	TitleControllerPtr _titleUpdata;
};