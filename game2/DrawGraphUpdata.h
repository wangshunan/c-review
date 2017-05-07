#pragma once
#include"ImageLoad.h"
#include"GameLogic.h"
#include"GameTime.h"
#include"Player.h"

PTR( Draw );

class Draw :public GameState{
public:
	Draw();
	virtual ~Draw();

	void DrawUpdata();
private:
	void DrawClearScreen();
	void DrawScreenFlip();
	void DrawTitle();
	void DrawMap();
	void DrawCharacter();
	void DrawPlayer();

	int _nowtime;
	const int SCROLL_STAPOS = 500;

	MapImageDataPtr _imagedata;
	GameLogicPtr _gamelogic;
	MapDataPtr _mapdata;
	GameTimePtr _gametime;
	CharacterImageDataPtr _chardata;
	PlayerUpDataPtr _playerdata;
};