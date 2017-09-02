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

	//text data 取得
	textdata -> GetData( textdata );

	//テキストに追加出力
	text->TextWrite("test.txt");

	//Game Loop
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0) {

		ClearDrawScreen();

		//テキスト表示
		DrawString(0, 0, textdata->_chardata, textdata->_color);
		
		if ( CheckHitKey(KEY_INPUT_A) ) {
			//新しいテキストのデータを更新する
			text->TextLoad("test.txt");
		}

		ScreenFlip();
	}

	//終了後メモリ解放
	delete textdata;

	DxLib_End();        

	return 0;        
}