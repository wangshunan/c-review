#pragma once
#include <string>

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

	void TextLoad( char *filename );
	void TextWrite( char *flie_name );

	TextData *_textdata;
};

