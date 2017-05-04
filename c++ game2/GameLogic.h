#pragma once
#include"smart_ptr.h"

PTR( GameLogic );
PTR( GameState );

class GameState {
public:
	GameState();
	virtual ~GameState();
	enum GAME_STATE {
		GameTitle,
		GamePlaying,
		GameOver,
		GameClear
	};
};

class GameLogic :public GameState {
public:
	GameLogic();
	virtual ~GameLogic();

	void Init();
	void GetGameState( GameLogicPtr &temp );
	void SetGameState( const GameLogicPtr &gamestate );
	int _gamestate;
private:
	static GameLogicPtr _gamelogic;
};