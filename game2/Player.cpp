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
	_mapdata->GetMapData(_mapdata);
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
	_posx = -0.33;
	_posy = 1;
	_hp = 3;
	_animcounter = 0;
	_fps = 30;
	_flipx = FALSE;
}

void PlayerUpData::PlayerController() {

	hx = _posx;
	hy = _posy;

	// player�R���g���[��
	if (_input->_getHoldKey(KEY_INPUT_RIGHT) == 1) {
		_speedx = 0.1;
		_flipx = FALSE;
	}
	else if (_input->_getHoldKey(KEY_INPUT_LEFT) == 1) {
		_speedx = -0.1;
		_flipx = TRUE;
	}
	else {
		_speedx = 0;
	}

	if (_isgrounded) {
		if (CheckHitKey(KEY_INPUT_SPACE) == 1) {
			_speedy = 7;
			_isgrounded = FALSE;
		}
	}


	if (!_isgrounded) {
		_speedy += GRAVITY / _fps;
	}

	hx += _speedx;
    hy -= _speedy / _fps;
	
	// �X�N���[���␳
	if (hx * _imgsizey - _scrollx > 450) {
		_scrollx += (hx - _posx) * _imgsizey;
	}

	if ((hx * _imgsizey) + OFFSET_WIDTH < _scrollx) {
		hx = _posx;
	}

}


void PlayerUpData::AnimationUpdata() {

	if (_speedx != 0) {
		AnimChange(_animimgdata->_playerimg.run, std::size(_animimgdata->_playerimg.run));
	}
	else {
		AnimChange(_animimgdata->_playerimg.wait, std::size(_animimgdata->_playerimg.wait));
	}

	/*if (_speedy != 0) {
		AnimChange(_animimgdata->_playerimg.wait, std::size(_animimgdata->_playerimg.wait));
	}
	else if (_speedy < 0) {
		AnimChange(_animimgdata->_playerimg.jumpdown, std::size(_animimgdata->_playerimg.jumpdown));
	}*/

	if ( _gametime->_nowtime % 6 == 0 ) {
		_animcounter++;
	}

	if (_animcounter >= _nowanimsize) {
		_animcounter = 0;
	}

	 _animimg = _nowanim[_animcounter];
	 GetGraphSize(_animimg, &_imgsizex, &_imgsizey);
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

void PlayerUpData::CollisionCheck() {
	DecisionCheck::AtariInfo atari = _decisioncheck->CheckBlock(hx * _imgsizex, hy * _imgsizey, _posx * _imgsizex, _imgsizex, _imgsizey);
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

	if (atari.GL == TRUE || atari.GR == TRUE) {
		_speedy = 0;
		hy = (float)((int)( ( hy * _imgsizey + _imgsizey ) / _mapdata -> CHIP_SIZE ) * _mapdata->CHIP_SIZE - _imgsizey + OFFSET_HIGHT_DOWN) / _imgsizey;
		_isgrounded = TRUE;
	}
	else {
		_isgrounded = FALSE;
	}

	_posx = hx;
	_posy = hy;
}

void PlayerUpData::UpData() {
	PlayerController();
	AnimationUpdata();
	CollisionCheck();
}