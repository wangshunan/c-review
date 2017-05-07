#include<DxLib.h>
#include"GameLogic.h"

GameLogicPtr GameLogic::_gamelogic;
GameLogic::GameLogic() {
	_gamestate = GameState::GameTitle;
}

GameLogic::~GameLogic() {

}

GameState::GameState() {

}

GameState::~GameState() {

}

void GameLogic::GetGameState( GameLogicPtr &temp ) {
	if ( !_gamelogic ) {
		_gamelogic = GameLogicPtr(new GameLogic);
	}
	temp = _gamelogic;
}

void GameLogic::SetGameState( const GameLogicPtr &gamestate ) {
	_gamelogic = gamestate;
}

void GameLogic::Init() {
	_gamestate = GAME_STATE::GameTitle;
}