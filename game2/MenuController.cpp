#include<DxLib.h>
#include"MenuController.h"
#include"GameLogic.h"

TitleController::TitleController(){
	_gamelogic->GetGameState(_gamelogic);
}

TitleController::~TitleController(){
}

void TitleController::TitleInput() {
	if (CheckHitKey(KEY_INPUT_Z)) {
		_gamelogic->_gamestate = _gamelogic->GamePlaying;
	}
}

void TitleController::TitleUpdata() {
	TitleInput();
}