#pragma once
#include<DxLib.h>

class  InputProcess {
public:
	InputProcess();
	virtual ~InputProcess();

	void GetData(InputProcess *&temp);
	void CheckKey();

public:
	int push[256];
	int hold[256];

private:
	const int MAX = 256;
	int oldkey[256];
	int GetKey(int key_code);

public:
	static InputProcess *_data;
};