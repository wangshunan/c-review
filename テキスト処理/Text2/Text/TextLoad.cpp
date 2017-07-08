#include<DxLib.h>
#include <fstream>
#include <iostream>
#include <string>
#include <iterator>
#include <cstdlib>
#include"TextLoad.h"

TextData *TextData::_data;

TextData::TextData() {
	_color = GetColor( 255, 255, 255 );
}

TextData::~TextData() {
	
}

TextDataProcessing::TextDataProcessing() {
	
}

TextDataProcessing::~TextDataProcessing() {
}

void TextData::GetData( TextData &temp ) {
	if ( _data == NULL ) {
		_data = new TextData;
	}
	
	temp = *_data;
}

void TextData::SetData( TextData &temp ) {
	//データ設置
	_data = &temp;
}

void TextData::DatatSizeSet( size_t size ) {
	//文字列サイズのメモリ確保
	_chardata = new char[ size + 1];
}

void TextDataProcessing::TextLoad( char *_filename ) {

	//textdata init
	_textdata = new TextData();

	//file open
	std::ifstream ifs( _filename );

	//file check
	if (ifs.fail())
	{
		//エラー表示
		char* error = "Error";

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