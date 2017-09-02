#include "DxLib.h"
#include "TextProcessing.h"


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {

	//textProcessing textdata ������
	TextDataProcessing *text = new TextDataProcessing();
	TextData *textdata = new TextData();

	ChangeWindowMode(TRUE);
	SetGraphMode(1024, 768, 32);

	if (DxLib_Init() == -1)        
	{
		return -1;        
	}

	//text �ǂݍ���
	text->TextLoad("test.txt");

	//text data �擾
	textdata -> GetData( textdata );

	//�e�L�X�g�ɒǉ��o��
	text->TextWrite("test.txt");

	//Game Loop
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0) {

		ClearDrawScreen();

		//�e�L�X�g�\��
		DrawString(0, 0, textdata->_chardata, textdata->_color);
		
		if ( CheckHitKey(KEY_INPUT_A) ) {
			//�V�����e�L�X�g�̃f�[�^���X�V����
			text->TextLoad("test.txt");
		}

		ScreenFlip();
	}

	//�I���チ�������
	delete textdata;

	DxLib_End();        

	return 0;        
}