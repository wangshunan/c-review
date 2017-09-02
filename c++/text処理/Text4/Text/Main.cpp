#include "DxLib.h"
#include "TextProcessing.h"
#include "KeyBoard.h"


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {

	// �e�N���X�f�[�^ ������
	TextDataProcessing *text = new TextDataProcessing();
	TextData *textdata = new TextData();
	InputProcess *input = new InputProcess();

	ChangeWindowMode(TRUE);
	SetGraphMode(1024, 768, 32);

	if (DxLib_Init() == -1)        
	{
		return -1;        
	}

	// �`���𗠂ɂ���
	SetDrawScreen(DX_SCREEN_BACK);

	// text �ǂݍ���
	text -> TextLoad("test.txt");

	// text data �擾
	textdata -> GetData( textdata );


	// �C���v�b�g�@data�@�擾
	input -> GetData( input );

	// ���̓X�C�b�`
	bool input_on = false;

	// Game Loop
	while ( ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0 ) {

		ClearDrawScreen();

		// ���t���[���L�[�{�[�h���͏�ԍX�V
		input -> CheckKey();

		if ( input->push[KEY_INPUT_Y] == 1 ) {
			// ���X�g�ǂݍ���\������e�L�X�g�ɒǉ�����
			text -> TextClear("test.txt");
			text -> TextLoad( "list.txt" );
			text -> TextWrite( "test.txt", textdata->_chardata );
			text -> TextLoad( "test.txt" );
		}

		// ���̓��[�hON
		if ( input -> push[KEY_INPUT_SPACE] == 1 ) {
			input_on = true;
		}

		// ���̓��[�h
		if ( input_on ) {
			// �\���e�L�X�g���N���A����
			text -> TextClear("test.txt");
			// ����
			text -> GetInput();
		}

		// ���̓��[�hOFF
		input_on = false;

		// �e�L�X�g�\��
		DrawString( 0, 0, textdata -> _chardata, textdata -> _color );

		ScreenFlip();
	}

	// �\���e�L�X�g���N���A����
	text->TextClear("test.txt");

	// �I���チ�������
	delete textdata;
	delete text;
	delete input;

	DxLib_End();        

	return 0;        
}