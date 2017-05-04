#pragma once
#include<DxLib.h>
#include"smart_ptr.h"
#include"ImageLoad.h"

PTR(DecisionCheck);

class DecisionCheck {
public:
	DecisionCheck();
	virtual ~DecisionCheck();

	void GetDecisionData(DecisionCheckPtr &temp);
protected:
	BOOL CheckBlockSub(float x, float y);
public:
	struct  AtariInfo {
		BOOL UL, UR, DL, DR, GL, GR;
	};
	AtariInfo CheckBlock(float x, float y);

	static DecisionCheckPtr _decisioncheck;
	MapDataPtr _mapdata;
};