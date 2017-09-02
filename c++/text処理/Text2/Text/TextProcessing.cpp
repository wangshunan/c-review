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
	//NULL�������珉����
	if ( _data == NULL ) {
		_data = new TextData();
	}
	
	temp = _data;
}

void TextData::SetData( TextData &temp ) {
	//�A�h���X��_data�ɓn��
	_data = &temp;
}

void TextData::DatatSizeSet( size_t size ) {

	//�O��g�p�������������������
	delete[] _chardata;

	//������T�C�Y�̃������m��
	_chardata = new char[ size + 1];
}

void TextDataProcessing::TextLoad( char *filename ) {

	//textdata
	_textdata->GetData(_textdata);

	//�ǂݍ��ݐ�p�Ńe�L�X�g���J��
	std::ifstream ifs( filename, std::ios::in );

	//file check
	if (ifs.fail())
	{
		//�G���[�\��
		char* error = "�ǂݍ���Error";

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

void TextDataProcessing::TextWrite( char *file_name ) {

	//�ǉ��o�̓��[�h�Ńe�L�X�g���J��
	std::fstream ofs( file_name, std::ios::in );

	//�t�@�C���Ȃ���΃G���[��\��
	if (ofs.fail()) {
		//�G���[�\��
		char* error = "��������Error";

		//�T�C�Y���������m��
		_textdata->DatatSizeSet( strlen(error) );

		//����������
		_textdata->_chardata = error;

		//�f�[�^����ւ�
		_textdata->SetData( *_textdata );

		return;
	} else {
		ofs.close();
		ofs.open( file_name, std::ios::app );
	}

	//�ǉ��o��
	ofs << "�ǉ�Test" << std::endl;

	ofs.close();
	
}