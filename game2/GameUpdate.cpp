#include<DxLib.h>
#include"GameUpdate.h"
#include"GameLogic.h"

GameUpdate::GameUpdate():
	_input(InputPtr(new Input)),
	_gametime(GameTimePtr(new GameTime)),
	_drawupdate(DrawPtr(new Draw)){
}

GameUpdate::~GameUpdate(){

}


void GameUpdate::MainGameUpdate() {
	while( _input -> _getKey( KEY_INPUT_ESCAPE ) == 0 &&  ProcessMessage() == 0 ) {
		_gametime -> TimeUpdate();
		_input -> InputUpdate();
		_drawupdate -> DrawUpdate();
	}
}
 