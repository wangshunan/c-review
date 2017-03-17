#pragma once
#ifndef __MAIN_H__
#define __MAIN_H__
#include<DxLib.h>


//ŠÔŒv‘ª—p•Ï”
extern int _lasttime;
extern float _frametime;
extern int _timerstart;

enum GameState{
	GAME_TITLE,
	GAME_MAIN,
	GAME_CLEAR,
	GAME_OVER
};

extern GameState _gamestate;

#endif