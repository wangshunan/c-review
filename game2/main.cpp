#include <DxLib.h>
#include"GameUpdata.h"
#include"Game.h"


int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow ) {

	ChangeWindowMode(TRUE);
	SetGraphMode( 800, 600, 32 );

    if( DxLib_Init() == -1 )        // ＤＸライブラリ初期化処理
    {
         return -1;        // エラーが起きたら直ちに終了
    }
	// Game初期化
	sGame -> Init();
	// GameUpdata
	sGame -> Updata();

    DxLib_End();        // ＤＸライブラリ使用の終了処理

    return 0;        // ソフトの終了
}