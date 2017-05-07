#pragma once
#include "smart_ptr.h"
#include"GameUpdata.h"
#include"ImageLoad.h"

PTR( Game );

class Game {
public:
	static GamePtr GetInstance();
	virtual ~Game();

	void Init();
	void Updata();
private:
	Game();
private:
	static GamePtr _instance;
	GameUpdataPtr _gameupdata;
	MapDataPtr _mapdata;
};

#define sGame Game::GetInstance()