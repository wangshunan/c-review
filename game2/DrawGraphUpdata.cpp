#include<DxLib.h>
#include"DrawGraphUpdata.h"
#include"ImageLoad.h"
#include"GameLogic.h"
#include"GameTime.h"
#include"Player.h"

Draw::Draw() {
	_chardata -> GetCharacterImageData( _chardata );
	_imagedata -> GetMapImageData( _imagedata );
	_gamelogic -> GetGameState( _gamelogic );
	_mapdata -> GetMapData( _mapdata );
	_gametime -> GetGameTime( _gametime );
	_playerdata -> GetPlayerData(_playerdata);
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
	DrawGraph( 0, 0, _imagedata -> _imagehandles.title, TRUE );
	DrawStringToHandle(30, 450, "Z -> START", GetColor(255,0,255), _imagedata ->_middlefont);
	DrawStringToHandle(30, 490, "カーソルキーで移動", GetColor(255, 0, 255), _imagedata->_middlefont);
	DrawStringToHandle(30, 540, "Z -> JUMP X -> Ataack", GetColor(0, 0, 0), _imagedata->_middlefont);
}

void Draw::DrawMap() {

	int sc = (int) (_playerdata->_scrollx / _imagedata->CHIP_SIZE);
	int shiftx = (int)_playerdata->_scrollx % _imagedata->CHIP_SIZE;

	for (int y = 0; y < _mapdata -> MAP_HEIGHT; y++) {
		for (int x = 0; x < _mapdata -> MAP_WIDTH; x++) {
			if (_mapdata -> _data[y][x + sc] == '1' ) {
				DrawGraph(x * _imagedata -> CHIP_SIZE - shiftx, y * _imagedata -> CHIP_SIZE, _imagedata->_imagehandles.block, TRUE);
			}
		}
	}

}

void Draw::DrawPlayer() {

	int setoff = 8;
	if ()
	if (!_playerdata->_isgrounded) {
		DrawRotaGraph2((_playerdata->_posx * 50) - 8 - _playerdata->_scrollx,
			(_playerdata->_posy * 50) - 6,
			0, 0, 1, 0, _playerdata->_animimg,
			TRUE, _playerdata->_flipx);
	}
	else {
		DrawRotaGraph2((_playerdata->_posx * 50) - 8 - _playerdata->_scrollx,
			(int)(_playerdata->_posy * 50) - 6,
			0, 0, 1, 0, _playerdata->_animimg,
			TRUE, _playerdata->_flipx);
	}
}

void Draw::DrawCharacter() { 
	DrawPlayer();
}

void Draw::DrawUpdata() {

	DrawClearScreen();

	switch ( _gamelogic -> _gamestate ) {
	case GAME_STATE::GameTitle:
		DrawTitle();
		_gamelogic -> _gamestate = GAME_STATE::GamePlaying;
		break;
	case GAME_STATE::GamePlaying:
		DrawMap();
		DrawCharacter();
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