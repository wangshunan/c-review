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
	static TextData *_data;
};

class TextDataProcessing{
public:
	TextDataProcessing();
	virtual ~TextDataProcessing();

	void TextLoad( char *file_name );
	void TextWrite( char *file_name, std::string str );
	void TextClear( char *file_name );
	void FindKeyWord( std::string key_word );
	void GetInput();

private:
	bool _inputper = true;

	TextData *_textdata;
	InputProcess* _inputpro;
};

