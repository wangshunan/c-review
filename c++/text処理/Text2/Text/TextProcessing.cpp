#include<DxLib.h>
#include <fstream>
#include <iostream>
#include <string>
#include <iterator>
#include <cstdlib>
#include"TextProcessing.h"

TextData *TextData::_data;

TextData::TextData() {
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
	//NULLだったら初期化
	if ( _data == NULL ) {
		_data = new TextData();
	}
	
	temp = _data;
}

void TextData::SetData( TextData &temp ) {
	//アドレスを_dataに渡す
	_data = &temp;
}

void TextData::DatatSizeSet( size_t size ) {

	//前回使用したメモリを解放する
	delete[] _chardata;

	//文字列サイズのメモリ確保
	_chardata = new char[ size + 1];
}

void TextDataProcessing::TextLoad( char *filename ) {

	//textdata
	_textdata->GetData(_textdata);

	//読み込み専用でテキストを開く
	std::ifstream ifs( filename, std::ios::in );

	//file check
	if (ifs.fail())
	{
		//エラー表示
		char* error = "読み込みError";

		//サイズ分メモリ確保
		_textdata->DatatSizeSet( strlen(error) );

		//文字列入れる
		_textdata -> _chardata = error;

		//データ入れ替え
		_textdata->SetData( *_textdata );

		return;
	}
	
	//テキスト読み込み
	std::string str((std::istreambuf_iterator<char>(ifs)),
		             std::istreambuf_iterator<char>());

	//文字列メモリ確保
	_textdata->DatatSizeSet( str.length() );

	//文字列入れる
	strcpy( _textdata -> _chardata, str.c_str() );

	//カラー設定
	_textdata->_color = GetColor( 255, 255, 255 );

	//データ入れ替え
	_textdata->SetData( *_textdata );

	//file close
	ifs.close();
	
}

void TextDataProcessing::TextWrite( char *file_name ) {

	//追加出力モードでテキストを開く
	std::fstream ofs( file_name, std::ios::in );

	//ファイルなければエラーを表示
	if (ofs.fail()) {
		//エラー表示
		char* error = "書き込みError";

		//サイズ分メモリ確保
		_textdata->DatatSizeSet( strlen(error) );

		//文字列入れる
		_textdata->_chardata = error;

		//データ入れ替え
		_textdata->SetData( *_textdata );

		return;
	} else {
		ofs.close();
		ofs.open( file_name, std::ios::app );
	}

	//追加出力
	ofs << "追加Test" << std::endl;

	ofs.close();
	
}