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
	BOOL CheckCoinSub(float x, float y);
public:
	struct  AtariInfo {
		BOOL UL, UR, DL, DR, GL, GR, COIN;
	};
	AtariInfo CheckBlock(float x, float y, float rx, float ry, int sizex, int sizey);
	AtariInfo CheckCoin(float x, float y, int sizex, int sizey, bool flipx);
	bool _iscollision;

	static DecisionCheckPtr _decisioncheck;
	MapDataPtr _mapdata;
};