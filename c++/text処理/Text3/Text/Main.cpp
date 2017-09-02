#include "DxLib.h"
#include "TextProcessing.h"
#include "KeyBoard.h"


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {

	// 各クラスデータ 初期化
	TextDataProcessing *text = new TextDataProcessing();
	TextData *textdata = new TextData();
	InputProcess *input = new InputProcess();

	ChangeWindowMode(TRUE);
	SetGraphMode(1024, 768, 32);

	if (DxLib_Init() == -1)        
	{
		return -1;        
	}

	// 描画先を裏にする
	SetDrawScreen(DX_SCREEN_BACK);

	// text 読み込み
	text->TextLoad("test.txt");

	// text data 取得
	textdata -> GetData( textdata );

	// インプット　data　取得
	input -> GetData(input);

	// 入力スイッチ
	bool input_on = false;

	// Game Loop
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0) {

		ClearDrawScreen();

		// 毎フレームキーボード入力状態更新
		input -> CheckKey();
		
		// テキスト表示
		DrawString(0, 0, textdata->_chardata, textdata->_color);

		// 入力モードON
		if ( input->push[KEY_INPUT_SPACE] == 1 ) {
			input_on = true;
		}

		if (input_on) {
			text->GetInput();
		}

		// 入力モードOFF
		input_on = false;

		ScreenFlip();
	}

	// 終了後メモリ解放
	delete textdata;
	delete text;
	delete input;

	DxLib_End();        

	return 0;        
}