#include<DxLib.h>
#include"PlayerController.h"
#include"DrawGraph.h"
#include"main.h"
#include"Loding.h"
#include"Init.h"
#include"enemies.h"
#include"KeyBoardUpdata.h"
#include <math.h>

int _lasttime = 0;
float _frametime = 0;
int _timerstart;


GameState _gamestate = GAME_TITLE;

void DrawGameTitle();
void DrawGameMain();
void DrawGameClear();
void GameOverUpdata();
void DrawPixelTest();

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


	// stage������
	InitStage();

	SetDrawScreen(DX_SCREEN_BACK);

	while ( ProcessMessage() == 0 && CheckHitKey( KEY_INPUT_ESCAPE ) == 0 ) {
		//1���[�v���Ԍv��
		int curtime = GetNowCount();
		_frametime = (float)( curtime - _lasttime ) / 1000.0f;
		_lasttime = curtime;

		ClearDrawScreen();

		// keybord����updata
		KeyboardUpdate();

		switch (_gamestate) {
		case GAME_TITLE:
			DrawGameTitle();
			break;
		case GAME_MAIN:
			DrawGameMain();
			break;
		case GAME_CLEAR:
			DrawGameClear();
			break;
		case GAME_OVER:
			GameOverUpdata();
			break;
		default:
			break;
		}
		ScreenFlip();

	}

	//WaitKey() ;				// �L�[���͑҂�

	DxLib_End() ;				// �c�w���C�u�����g�p�̏I������

	return 0 ;				// �\�t�g�̏I�� 
}

void DrawGameTitle() {
	TitleController();
	DrawTitleGraph();
}

void DrawGameMain() {
	PlayerUpdata();
	EnemyUpData();
	FireUpdata();
	CollisionDetection();
	DrawMainGame();
	DrawPixelTest();
}

void DrawGameClear() {
	DrawGameClearUpdata();
	if ( _lasttime - _timerstart > 5000 ) _gamestate = GAME_TITLE;
}

void GameOverUpdata() {
	DrawGameOverUpdata();
	if ( _lasttime - _timerstart > 5000 ) _gamestate = GAME_TITLE;
}

void DrawPixelTest() {
	for ( int y = 0; y <= 600; y++ ) {
		for ( int x = 0; x <= 800; x++ ) {
			int i = sqrt( ( ( x - _playerstatus.posx * 50 - 25 ) * ( x - _playerstatus.posx * 50 - 25 ) ) +(  y - _playerstatus.posy * 50 - 25 ) * ( ( y - _playerstatus.posy * 50 - 25 ) ) );
			if ( i > 120 ) {
				DrawPixel( x , y , GetColor( 0, 0, 0 ) );
			}
		}
	}
}