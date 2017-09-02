#include<DxLib.h>
#include <fstream>
#include <iostream>
#include <string>
#include <iterator>
#include <cstdlib>
#include"TextProcessing.h"
#include"KeyBoard.h"

using namespace std;

TextData *TextData::_data;

TextData::TextData() {
	//　カラーとcharデータ初期化
	_color = GetColor( 255, 255, 255 );
	_chardata = new char;
}

TextData::~TextData() {
	
}

TextDataProcessing::TextDataProcessing() {

}

TextDataProcessing::~TextDataProcessing() {
}

void TextData::GetData( TextData *&temp ) {
	// NULLだったら初期化
	if ( _data == NULL ) {
		_data = new TextData();
	}
	
	temp = _data;
}

void TextData::SetData( TextData &temp ) {
	// アドレスを_dataに渡す
	_data = &temp;
}

void TextData::DatatSizeSet( size_t size ) {

	// 前回使用したメモリを解放する
	delete[] _chardata;

	// 文字列サイズのメモリ確保
	_chardata = new char[ size + 1];
}


// テキストデータロード関数
void TextDataProcessing::TextLoad( char *file_name) {

	// textdata
	_textdata->GetData(_textdata);

	// 読み込み専用でテキストを開く
	ifstream ifs( file_name, std::ios::in );

	// file check
	if (ifs.fail())
	{
		//エラー表示
		char* error = "読み込みError";

		// サイズ分メモリ確保
		_textdata->DatatSizeSet( strlen(error) );

		// 文字列入れる
		_textdata -> _chardata = error;

		// データ入れ替え
		_textdata->SetData( *_textdata );

		return;
	}
	
	// テキスト読み込み
	string str((istreambuf_iterator<char>(ifs)),
		             istreambuf_iterator<char>());

	// 文字列メモリ確保
	_textdata->DatatSizeSet( str.length() );

	// 文字列入れる
	strcpy( _textdata -> _chardata, str.c_str() );

	// カラー設定
	_textdata->_color = GetColor( 255, 255, 255 );

	// データ入れ替え
	_textdata->SetData( *_textdata );

	// file close
	ifs.close();
	
}


// テキストデータ書き込む関数
void TextDataProcessing::TextWrite( char *file_name, string str ) {

	// 追加出力モードでテキストを開く
	fstream ofs( file_name, ios::app );

	// ファイルなければエラーを表示
	if (ofs.fail()) {
		// エラー表示
		char* error = "書き込みError";

		// サイズ分メモリ確保
		_textdata->DatatSizeSet( strlen(error) );

		// 文字列入れる
		_textdata->_chardata = error;

		// データ入れ替え
		_textdata->SetData( *_textdata );

		return;
	}

	// 追加出力
	ofs << str << endl;

	ofs.close();
	
}


// 入力によりデータの記録とテキストへの更新
void TextDataProcessing::GetInput() {

	char String[50];
	int InputHandle;
	string str;

	// キー入力ハンドルを作る(キャンセルなし全角文字有り数値入力じゃなし)
	InputHandle = MakeKeyInput(50, FALSE, FALSE, FALSE);

	// 作成したキー入力ハンドルをアクティブにする
	SetActiveKeyInput(InputHandle);

	// 入力ループ
	while (!ProcessMessage())
	{

		// 入力が終了している場合は終了
		if (CheckKeyInput(InputHandle) != 0) break;

		ClearDrawScreen();

		DrawString(0, 0, "学生の名前を入力してください、終わったらエンターキーを押してください。", GetColor(255, 255, 255));

		// 入力モードを描画
		DrawKeyInputModeString(640, 480);

		// 入力途中の文字列を描画
		DrawKeyInputString(0, 16, InputHandle);

		ScreenFlip();
	}

	// 入力された文字列を取得
	GetKeyInputString(String, InputHandle);

	// 用済みのインプットハンドルを削除する
	DeleteKeyInput(InputHandle);

	// charをstringに変換する
	str = String;

	// 文字列を検索
	FindKeyWord( str );

	// テキストデータ再ロード
	TextLoad("test.txt");

}

void TextDataProcessing::FindKeyWord( string key_word ) {

	int s_pos;
	int e_pos;

	// 読み込み専用でテキストを開く
	ifstream ifs("Data.txt", std::ios::in);

	// file check
	if (ifs.fail())
	{
		//エラー表示
		char* error = "読み込みError";

		// サイズ分メモリ確保
		_textdata->DatatSizeSet(strlen(error));

		// 文字列入れる
		_textdata->_chardata = error;

		// データ入れ替え
		_textdata->SetData(*_textdata);

		return;
	}

	// テキスト読み込み
	string str((istreambuf_iterator<char>(ifs)),
				istreambuf_iterator<char>());

	if ( str.find(key_word) != string::npos ) {
		s_pos = str.find(key_word);
		e_pos = str.find("\n", s_pos);
		str = str.substr(s_pos, e_pos - s_pos);
	} else {
		str = "この名前のデータは特定できません";
	}

	// file close
	ifs.close();

	TextWrite( "test.txt", str );

}

void TextDataProcessing::TextClear( char *file_name ) {

	// 読み込みモードで開く
	fstream ifs( file_name, ios::in );

	// ファイルなければエラーを表示
	if (ifs.fail()) {
		// エラー表示
		char* error = "書き込みError";

		// サイズ分メモリ確保
		_textdata->DatatSizeSet(strlen(error));

		// 文字列入れる
		_textdata->_chardata = error;

		// データ入れ替え
		_textdata->SetData(*_textdata);

		return;
	}

	// テキスト読み込み
	string str((istreambuf_iterator<char>(ifs)),
		        istreambuf_iterator<char>());

	ifs.close();

	// 書き込みモードで開く
	fstream ofs( file_name, ios::out );

	// Textをクリアする
	str = str.substr( 0, str.rfind("-") + 1);

	ofs << str << endl;

	ofs.close();
}
