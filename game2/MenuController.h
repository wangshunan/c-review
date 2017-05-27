#pragma once
#include<DxLib.h>
#include"smart_ptr.h"
#include"GameLogic.h"

PTR(TitleController);

class TitleController {
public:
	TitleController();
	~TitleController();

	void TitleInput();
	void TitleUpdata();
private:
	GameLogicPtr _gamelogic;
};
