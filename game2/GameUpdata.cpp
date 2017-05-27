#include<DxLib.h>
#include"GameUpdata.h"
#include"GameLogic.h"
#include"MenuController.h"
#include"Player.h"

GameUpdata::GameUpdata():
	_drawupdata(DrawPtr(new Draw)),
	_titleUpdata(TitleControllerPtr(new TitleController)) {
	_gametime -> GetGameTime(_gametime);
	_playerdata -> GetPlayerData( _playerdata );
	_input->GetInput(_input);
	_gamelogic->GetGameState(_gamelogic);
}

GameUpdata::~GameUpdata(){

}


void GameUpdata::MainGameUpdata() {
	while( _input -> _getKey( KEY_INPUT_ESCAPE ) == 0 &&  ProcessMessage() == 0 ) {
		_gametime -> TimeUpdata(); // êŠ•Ï“®
		InputUpdata();
		_drawupdata -> DrawUpdata();
	}
}

void GameUpdata::InputUpdata() {


	switch (_gamelogic->_gamestate) {
	case GAME_STATE::GameTitle:
		_titleUpdata->TitleUpdata();
		break;
	case GAME_STATE::GamePlaying:
		_input->InputUpdata();
		_playerdata->UpData();
		break;
	case GAME_STATE::GameClear:
		break;
	case GAME_STATE::GameOver:
		_gamelogic->_gamestate = GameTitle;
		_playerdata->Init();
		break;
	default:
		break;
	}
}
 