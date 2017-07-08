#include "DxLib.h"
#include "TextProcessing.h"


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {

	//textProcessing textdata 初期化
	TextDataProcessing *text = new TextDataProcessing();
	TextData *textdata = new TextData();

	ChangeWindowMode(TRUE);
	SetGraphMode(1024, 768, 32);

	if (DxLib_Init() == -1)        
	{
		return -1;        
	}

	//text 読み込み
	text->TextLoad("test.txt");

	//読み込み終了メモリ解放
	delete text;

	//text data 取得
	textdata -> GetData( *textdata );

	// Game Loop
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0) {
		//テキスト表示
		DrawString(0, 0, textdata->_chardata, textdata->_color);
	}

	//終了後メモリ解放
	delete textdata;

	DxLib_End();        

	return 0;        
}