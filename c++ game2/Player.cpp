#include <DxLib.h>
#include <vector>
#include"Player.h"
#include"InputUpdata.h"
#include"GameTime.h"
#include"ImageLoad.h"
#include"DecisionCheck.h"

PlayerUpDataPtr PlayerUpData::_playerdata;
PlayerData::PlayerData() {

}

PlayerData::~PlayerData() {

}

PlayerUpData::PlayerUpData() {
	_gametime -> GetGameTime( _gametime );
	_animimgdata -> GetCharacterImageData( _animimgdata );
	_input->GetInput( _input );
	_decisioncheck->GetDecisionData(_decisioncheck);

	Init();
}

PlayerUpData::~PlayerUpData() {

}

void PlayerUpData::GetPlayerData( PlayerUpDataPtr &temp ) {
	if (!_playerdata) {
		_playerdata = PlayerUpDataPtr(new PlayerUpData);
	}
	temp = _playerdata;
}

void PlayerUpData::Init() {
	_posx = 0;
	_posy = 8;
	_hp = 3;
	_animcounter = 0;
	_fps = 30;
	_flipx = FALSE;
}

void PlayerUpData::PlayerController() {

	float hx = _posx;
	float hy = _posy;

	// playerコントロール
	if ( _input->_getHoldKey(KEY_INPUT_RIGHT) == 1) {
		_speedx = 0.1;
		_flipx = FALSE;
	} 
	else if ( _input->_getHoldKey(KEY_INPUT_LEFT) == 1 ) {
		_speedx = -0.1;
		_flipx = TRUE;
	}
	else {
		_speedx = 0;
	}

	hx += _speedx;

	if (_isgrounded) {
		if (CheckHitKey(KEY_INPUT_SPACE) == 1) {
			_speedy = 7;
			_isgrounded = FALSE;
		}
	}

	DecisionCheck::AtariInfo atari = _decisioncheck->CheckBlock(hx * 50, hy * 50);
	if (_flipx == FALSE) {
		if (atari.DR == TRUE || atari.UR == TRUE) {
			hx = _posx;
		}
	}
	else {
		if (atari.DL == TRUE || atari.UL == TRUE) {
			hx = _posx;
		}
	}
	
	// スクロール補正
	if (hx * 50 - _scrollx > 450) {
		_scrollx += (hx - _posx) * 50 ;
	}

	if (hx * 50 < _scrollx) {
		hx = _posx;
	}

	//移動更新
	_speedy += GRAVITY / _fps;
	_posx = hx;
 	_posy -= _speedy / _fps;

	//接地判定
	if ( _posy >= 9.7 ) {
		_speedy = 0;
		_posy = 9.7;
		_isgrounded = TRUE;
	}

}


void PlayerUpData::AnimationUpdata() {

	if (_speedx != 0) {
		AnimChange(_animimgdata->_playerimg.run, std::size(_animimgdata->_playerimg.run));
	}
	else {
		AnimChange(_animimgdata->_playerimg.wait, std::size(_animimgdata->_playerimg.wait));
	}

	if (_speedy > 0) {
		AnimChange(_animimgdata->_playerimg.jumpup, std::size(_animimgdata->_playerimg.jumpup));
	}
	else if (_speedy < 0) {
		AnimChange(_animimgdata->_playerimg.jumpdown, std::size(_animimgdata->_playerimg.jumpdown));
	}

	if ( _gametime->_nowtime % 6 == 0 ) {
		_animcounter++;
	}

	if (_animcounter >= _nowanimsize) {
		_animcounter = 0;
	}

	 _animimg = _nowanim[_animcounter];
}


void PlayerUpData::AnimChange(int anim[], int size) {

	if (!_nowanim.empty()) {
		if (_nowanim[0] == anim[0]) {
			return;
		}
		if (_nowanim[0] != anim[0]) {
			_nowanim.clear();
		}
	}

	for (int i = 0; i <= size; i++) {
		if (anim[i] != 0) {
			_nowanim.push_back(anim[i]);
		}
		_nowanimsize = size;
	}
}

void PlayerUpData::UpData() {
	PlayerController();
	AnimationUpdata();
}