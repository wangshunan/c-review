#include<DxLib.h>
#include"GameUpdata.h"
#include"GameLogic.h"
#include"Player.h"

GameUpdata::GameUpdata():
	_drawupdata(DrawPtr(new Draw)){
	_gametime -> GetGameTime(_gametime);
	_playerdata -> GetPlayerData( _playerdata );
	_input->GetInput(_input);
}

GameUpdata::~GameUpdata(){

}


void GameUpdata::MainGameUpdata() {
	while( _input -> _getKey( KEY_INPUT_ESCAPE ) == 0 &&  ProcessMessage() == 0 ) {
		_gametime -> TimeUpdata(); // êŠ•Ï“®
		_input -> InputUpdata();
		_playerdata -> UpData();
		_drawupdata -> DrawUpdata();
	}
}
 