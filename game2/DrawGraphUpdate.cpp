#include<DxLib.h>
#include"DrawGraphUpdate.h"
#include"ImageLoad.h"
#include"GameLogic.h"

Draw::Draw() {
	_imagedate = _imagedate -> GetImageDate();
	_gamelogic = _gamelogic -> GetGameState();
}

Draw::~Draw() {

}

void Draw::DrawClearScreen() {
	ClearDrawScreen();
}

void Draw::DrawScreenFlip() {
	ScreenFlip();
}

void Draw::DrawTitle() {
	DrawGraph( 0, 0, _imagedate -> _imagehandles.title, TRUE );
}

void Draw::DrawUpdate() {

	DrawClearScreen();

	switch ( _gamelogic -> _gamestate ) {
	case GAME_STATE::GameTitle:
		DrawTitle();
		break;
	case GAME_STATE::GamePlaying:
		break;
	case GAME_STATE::GameClear:
		break;
	case GAME_STATE::GameOver:
		break;
	default:
		break;
	}

	DrawScreenFlip();
}