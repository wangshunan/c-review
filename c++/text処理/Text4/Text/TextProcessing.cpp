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
	//�@�J���[��char�f�[�^������
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
	// NULL�������珉����
	if ( _data == NULL ) {
		_data = new TextData();
	}
	
	temp = _data;
}

void TextData::SetData( TextData &temp ) {
	// �A�h���X��_data�ɓn��
	_data = &temp;
}

void TextData::DatatSizeSet( size_t size ) {

	// �O��g�p�������������������
	delete[] _chardata;

	// ������T�C�Y�̃������m��
	_chardata = new char[ size + 1];
}


// �e�L�X�g�f�[�^���[�h�֐�
void TextDataProcessing::TextLoad( char *file_name) {

	// textdata
	_textdata->GetData(_textdata);

	// �ǂݍ��ݐ�p�Ńe�L�X�g���J��
	ifstream ifs( file_name, std::ios::in );

	// file check
	if (ifs.fail())
	{
		//�G���[�\��
		char* error = "�ǂݍ���Error";

		// �T�C�Y���������m��
		_textdata->DatatSizeSet( strlen(error) );

		// ����������
		_textdata -> _chardata = error;

		// �f�[�^����ւ�
		_textdata->SetData( *_textdata );

		return;
	}
	
	// �e�L�X�g�ǂݍ���
	string str((istreambuf_iterator<char>(ifs)),
		             istreambuf_iterator<char>());

	// �����񃁃����m��
	_textdata->DatatSizeSet( str.length() );

	// ����������
	strcpy( _textdata -> _chardata, str.c_str() );

	// �J���[�ݒ�
	_textdata->_color = GetColor( 255, 255, 255 );

	// �f�[�^����ւ�
	_textdata->SetData( *_textdata );

	// file close
	ifs.close();
	
}


// �e�L�X�g�f�[�^�������ފ֐�
void TextDataProcessing::TextWrite( char *file_name, string str ) {

	// �ǉ��o�̓��[�h�Ńe�L�X�g���J��
	fstream ofs( file_name, ios::app );

	// �t�@�C���Ȃ���΃G���[��\��
	if (ofs.fail()) {
		// �G���[�\��
		char* error = "��������Error";

		// �T�C�Y���������m��
		_textdata->DatatSizeSet( strlen(error) );

		// ����������
		_textdata->_chardata = error;

		// �f�[�^����ւ�
		_textdata->SetData( *_textdata );

		return;
	}

	// �ǉ��o��
	ofs << str << endl;

	ofs.close();
	
}


// ���͂ɂ��f�[�^�̋L�^�ƃe�L�X�g�ւ̍X�V
void TextDataProcessing::GetInput() {

	char String[50];
	int InputHandle;
	string str;

	// �L�[���̓n���h�������(�L�����Z���Ȃ��S�p�����L�萔�l���͂���Ȃ�)
	InputHandle = MakeKeyInput(50, FALSE, FALSE, FALSE);

	// �쐬�����L�[���̓n���h�����A�N�e�B�u�ɂ���
	SetActiveKeyInput(InputHandle);

	// ���̓��[�v
	while (!ProcessMessage())
	{

		// ���͂��I�����Ă���ꍇ�͏I��
		if (CheckKeyInput(InputHandle) != 0) break;

		ClearDrawScreen();

		DrawString(0, 0, "�w���̖��O����͂��Ă��������A�I�������G���^�[�L�[�������Ă��������B", GetColor(255, 255, 255));

		// ���̓��[�h��`��
		DrawKeyInputModeString(640, 480);

		// ���͓r���̕������`��
		DrawKeyInputString(0, 16, InputHandle);

		ScreenFlip();
	}

	// ���͂��ꂽ��������擾
	GetKeyInputString(String, InputHandle);

	// �p�ς݂̃C���v�b�g�n���h�����폜����
	DeleteKeyInput(InputHandle);

	// char��string�ɕϊ�����
	str = String;

	// �����������
	FindKeyWord( str );

	// �e�L�X�g�f�[�^�ă��[�h
	TextLoad("test.txt");

}

void TextDataProcessing::FindKeyWord( string key_word ) {

	int s_pos;
	int e_pos;

	// �ǂݍ��ݐ�p�Ńe�L�X�g���J��
	ifstream ifs("Data.txt", std::ios::in);

	// file check
	if (ifs.fail())
	{
		//�G���[�\��
		char* error = "�ǂݍ���Error";

		// �T�C�Y���������m��
		_textdata->DatatSizeSet(strlen(error));

		// ����������
		_textdata->_chardata = error;

		// �f�[�^����ւ�
		_textdata->SetData(*_textdata);

		return;
	}

	// �e�L�X�g�ǂݍ���
	string str((istreambuf_iterator<char>(ifs)),
				istreambuf_iterator<char>());

	if ( str.find(key_word) != string::npos ) {
		s_pos = str.find(key_word);
		e_pos = str.find("\n", s_pos);
		str = str.substr(s_pos, e_pos - s_pos);
	} else {
		str = "���̖��O�̃f�[�^�͓���ł��܂���";
	}

	// file close
	ifs.close();

	TextWrite( "test.txt", str );

}

void TextDataProcessing::TextClear( char *file_name ) {

	// �ǂݍ��݃��[�h�ŊJ��
	fstream ifs( file_name, ios::in );

	// �t�@�C���Ȃ���΃G���[��\��
	if (ifs.fail()) {
		// �G���[�\��
		char* error = "��������Error";

		// �T�C�Y���������m��
		_textdata->DatatSizeSet(strlen(error));

		// ����������
		_textdata->_chardata = error;

		// �f�[�^����ւ�
		_textdata->SetData(*_textdata);

		return;
	}

	// �e�L�X�g�ǂݍ���
	string str((istreambuf_iterator<char>(ifs)),
		        istreambuf_iterator<char>());

	ifs.close();

	// �������݃��[�h�ŊJ��
	fstream ofs( file_name, ios::out );

	// Text���N���A����
	str = str.substr( 0, str.rfind("-") + 1);

	ofs << str << endl;

	ofs.close();
}
