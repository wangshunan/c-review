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

	//�ǂݍ��ݏI�����������
	delete text;

	//text data �擾
	textdata -> GetData( *textdata );

	// Game Loop
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0) {
		//�e�L�X�g�\��
		DrawString(0, 0, textdata->_chardata, textdata->_color);
	}

	//�I���チ�������
	delete textdata;

	DxLib_End();        

	return 0;        
}