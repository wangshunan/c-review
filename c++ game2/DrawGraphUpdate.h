#pragma once
#include"ImageLoad.h"
#include"GameLogic.h"

PTR( Draw );

class Draw :public GameState{
public:
	Draw();
	virtual ~Draw();

	void DrawUpdate();
private:
	void DrawClearScreen();
	void DrawScreenFlip();
	void DrawTitle();

	ImageDatePtr _imagedate;
	GameLogicPtr _gamelogic;
	
};