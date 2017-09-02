#pragma once
#include <string>
#include"KeyBoard.h"

class TextData {
public :
	TextData();
	virtual ~TextData();

	void SetData( TextData &temp );
	void GetData( TextData *&temp );
	void DatatSizeSet( size_t size );

	char *_chardata;
	int _color;
	std::string temp;
	std::string _strdata;
	static TextData *_data;
};

class TextDataProcessing{
public:
	TextDataProcessing();
	virtual ~TextDataProcessing();

	void TextLoad( char *file_name );
	void TextWrite( char *file_name, std::string str, bool cover_mode );
	void TextClear( char *file_name );
	void FindKeyWord( std::string key_word );
	void WriteKeyWord(std::string key_word);
	void GetList();
	void GetInput();

	static int _inputcount;
private:
	bool _inputper = true;

	TextData *_textdata;
	InputProcess* _inputpro;
};

