#include<DxLib.h>
#include"KeyBoard.h"

InputProcess *InputProcess::_data;

InputProcess::InputProcess() {

}

InputProcess::~InputProcess() {

}

void InputProcess::GetData(InputProcess *&temp) {
	//NULL‚¾‚Á‚½‚ç‰Šú‰»
	if (_data == NULL) {
		_data = new InputProcess();
	}

	temp = _data;
}

int InputProcess::GetKey(int key_code) {
	return CheckHitKey(key_code);
}

void InputProcess::CheckKey( ) {

	for (int i = 0; i < MAX; i++) {
		if (GetKey( i ) == 1) {
			hold[i] = 1;
			if (oldkey[i] == 0) {
				oldkey[i] = 1;
				push[i] = 1;
			}
			else {
				push[i] = 0;
			}
		}
		else {
			push[i] = 0;
			hold[i] = 0;
			oldkey[i] = 0;
		}
	}
}