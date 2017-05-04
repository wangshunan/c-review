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

DecisionCheck::AtariInfo DecisionCheck::CheckBlock(float x, float y){
	AtariInfo result;
	result.UL = CheckBlockSub(x, y);
	result.UR = CheckBlockSub(x + _mapdata -> CHIP_SIZE - 1, y);
	result.DL = CheckBlockSub(x, y + _mapdata->CHIP_SIZE - 1);
	result.DR = CheckBlockSub(x + _mapdata->CHIP_SIZE - 1, y + _mapdata->CHIP_SIZE - 1);
	result.GL = CheckBlockSub(x, y + _mapdata->CHIP_SIZE);
	result.GR = CheckBlockSub(x + _mapdata->CHIP_SIZE - 1, y + _mapdata->CHIP_SIZE);

	return result;
}

BOOL DecisionCheck::CheckBlockSub(float x, float y) {
	int mx = (int)(x / _mapdata->CHIP_SIZE);
	int my = (int)(y / _mapdata->CHIP_SIZE);

	//マップ範囲外ならTRUE
	if (mx < 0 || mx >= _mapdata-> _stagedata.mapwitdh || my < 0 || my >= _mapdata ->MAP_HEIGHT) {
		return TRUE;
	}

	if (_mapdata->_data[my][mx] != '0') {
		return TRUE;
	}

	return FALSE;
}