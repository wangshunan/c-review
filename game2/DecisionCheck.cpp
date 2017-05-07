#include<DxLib.h>
#include"DecisionCheck.h"

DecisionCheckPtr DecisionCheck::_decisioncheck;
DecisionCheck::DecisionCheck() {
	_mapdata->GetMapData(_mapdata);
}

DecisionCheck::~DecisionCheck() {

}

void DecisionCheck::GetDecisionData(DecisionCheckPtr &temp) {
	if (!_decisioncheck) {
		_decisioncheck = DecisionCheckPtr(new DecisionCheck);
	}
	temp = _decisioncheck;
}

DecisionCheck::AtariInfo DecisionCheck::CheckBlock(float x, float y, float rx, int sizex, int sizey){
	AtariInfo result;
	result.UL = CheckBlockSub(x, y, sizex, sizey);
	result.UR = CheckBlockSub(x + sizex - 1, y, sizex, sizey);
	result.DL = CheckBlockSub(x, y + sizey - 1 , sizex, sizey);
	result.DR = CheckBlockSub(x + sizex - 1, y + sizey - 1, sizex, sizey);
	result.GL = CheckBlockSub(rx , y + sizey , sizex, sizey);
	result.GR = CheckBlockSub(rx + sizex - 1, y + sizey, sizex, sizey);

	return result;
}

BOOL DecisionCheck::CheckBlockSub(float x, float y, int sizex, int sizey) {
	int mx = (int)(x / sizex);
	int my = (int)(y / sizey);

	//マップ範囲外ならTRUE
	if (mx < 0 || mx >= _mapdata-> _stagedata.mapwitdh || my < 0 || my >= _mapdata ->MAP_HEIGHT) {
		return TRUE;
	}

	if (_mapdata->_data[my][mx] != '0') {
		return TRUE;
	}

	return FALSE;
}