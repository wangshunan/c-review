#include <DxLib.h>
#include"GameUpdata.h"
#include"Game.h"


int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow ) {

	ChangeWindowMode(TRUE);
	SetGraphMode( 800, 600, 32 );

    if( DxLib_Init() == -1 )        // �c�w���C�u��������������
    {
         return -1;        // �G���[���N�����璼���ɏI��
    }
	// Game������
	sGame -> Init();
	// GameUpdata
	sGame -> Updata();

    DxLib_End();        // �c�w���C�u�����g�p�̏I������

    return 0;        // �\�t�g�̏I��
}