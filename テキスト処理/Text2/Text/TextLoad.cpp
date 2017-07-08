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
	//�f�[�^�ݒu
	_data = &temp;
}

void TextData::DatatSizeSet( size_t size ) {
	//������T�C�Y�̃������m��
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
		//�G���[�\��
		char* error = "Error";

		//�T�C�Y���������m��
		_textdata->DatatSizeSet( strlen(error) );

		//����������
		_textdata -> _chardata = error;

		//�f�[�^����ւ�
		_textdata->SetData( *_textdata );

		return;
	}
	
	//�e�L�X�g�ǂݍ���
	std::string str((std::istreambuf_iterator<char>(ifs)),
		           std::istreambuf_iterator<char>());
	//�����񃁃����m��
	_textdata->DatatSizeSet( str.length() );

	//����������
	strcpy( _textdata -> _chardata, str.c_str() );

	//�J���[�ݒ�
	_textdata->_color = GetColor( 255, 255, 255 );

	//�f�[�^����ւ�
	_textdata->SetData( *_textdata );

	//file close
	ifs.close();
	
}