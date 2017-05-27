#pragma once
#include"smart_ptr.h"
#include"InputUpdata.h"
#include"GameTime.h"
#include"ImageLoad.h"
#include"DecisionCheck.h"
#include"Score.h"
#include"GameLogic.h"

PTR( PlayerUpData );

class PlayerData{
public:
	PlayerData();
	~PlayerData();

	int _animimg;
	std::vector<int> _nowanim;

	const float GRAVITY = -9.8f;
	const int OFFSET_HIGHT_UP = 16;
	const int OFFSET_HIGHT_DOWN = 8;
	const int OFFSET_WIDTH = 24;
	float _posx;
	float _posy;
	float hx;
	float hy;
	float _speedx;
	float _speedy;
	float _scrollx;
	int _imgsizex;
	int _imgsizey;
	int _frame;
	int _hp;
	int _animcounter;
	int _nowanimsize;
	bool _flipx;
	bool _isgrounded;
protected:
	static const int ANIM_FARM = 8;
};

class PlayerUpData:public PlayerData{
public:
	PlayerUpData();
	virtual ~PlayerUpData();

	void Init();
	void UpData();
	void GetPlayerData( PlayerUpDataPtr &temp );
	void CollisionCheck();
private:
	void AnimationUpdata();
	void PlayerController();
	void AnimChange( int anim[], int size );

	static PlayerUpDataPtr _playerdata;
	GameTimePtr _gametime;
	CharacterImageDataPtr _animimgdata;
	InputPtr _input;
	MapDataPtr _mapdata;
	DecisionCheckPtr _decisioncheck;
	ScorePtr _score;
	GameLogicPtr _gamelogic;
};
