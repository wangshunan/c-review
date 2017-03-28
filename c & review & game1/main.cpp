#include<DxLib.h>
#include"PlayerController.h"
#include"DrawGraph.h"
#include"main.h"
#include"Loding.h"
#include"Init.h"
#include"enemies.h"
#include"KeyBoardUpdata.h"
#include <math.h>

// 1���[�v���Ԍv��
int _lasttime = 0;
float _frametime = 0;
int _timerstart;

GameState _gamestate = GAME_TITLE;

void GameTitleUpdata();
void MainGameUpdata();
void GameClearUpdata();
void GameOverUpdata();

int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow )
{
	ChangeWindowMode(TRUE);
	SetGraphMode( 800, 600, 32 );

	if( DxLib_Init() == -1 )		// �c�w���C�u��������������
	{
		return -1 ;			// �G���[���N�����璼���ɏI��
	}

	// �摜���[�h
	LoadGameImage();
	if ( LoadGameImageCheck() == FALSE ) {
		return -1;
	}

	while ( ProcessMessage() == 0 && CheckHitKey( KEY_INPUT_ESCAPE ) == 0 ) {
		//1���[�v���Ԍv��
		int curtime = GetNowCount();
		_frametime = (float)( curtime - _lasttime ) / 1000.0f;
		_lasttime = curtime;

		ClearDrawScreen();

		// keybord����updata
		KeyboardUpdate();

		//GameUpdata
		switch (_gamestate) {
		case GAME_TITLE:
			GameTitleUpdata();
			break;
		case GAME_MAIN:
			MainGameUpdata();
			break;
		case GAME_CLEAR:
			GameClearUpdata();
			break;
		case GAME_OVER:
			GameOverUpdata();
			break;
		default:
			break;
		}
		ScreenFlip();

	}

	DxLib_End() ;	// �c�w���C�u�����g�p�̏I������

	return 0 ;		// �\�t�g�̏I�� 
}

void GameTitleUpdata() {
	TitleController();
	DrawTitleGraph();
}

void MainGameUpdata() {
	PlayerUpdata();
	EnemyUpData();
	FireUpdata();
	CollisionDetection();
	DrawMainGame();
}

void GameClearUpdata() {
	DrawGameClearUpdata();
	if ( _lasttime - _timerstart > 5000 ) _gamestate = GAME_TITLE;
}

void GameOverUpdata() {
	DrawGameOverUpdata();
	if ( _lasttime - _timerstart > 5000 ) _gamestate = GAME_TITLE;
}