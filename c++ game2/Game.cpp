#include<DxLib.h>
#include"Game.h"
#include"GameUpdata.h"
#include"ImageLoad.h"

GamePtr Game::_instance;

Game::Game():
	_gameupdata(GameUpdataPtr(new GameUpdata))
{
	_mapdata->GetMapData(_mapdata);
}


Game::~Game() {
	
}

GamePtr Game::GetInstance() {
	if ( !_instance ) {
		_instance = GamePtr(new Game);
	}
	return _instance;
}

void Game::Init() {
	LoadGameImage();
	_mapdata -> InitStage();
}

void Game::Updata() {
	_gameupdata -> MainGameUpdata();
}