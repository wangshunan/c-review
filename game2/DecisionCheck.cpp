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
	float x_l, x_r, y_u, y_d, rx_l, rx_r;
	x_l = x + 24;
	x_r = x + sizex - 24;
	y_u = y + 16;
	y_d = y + sizey - 10;
	rx_l = rx + 24;
	rx_r = rx + sizex - 24;
	result.UL = CheckBlockSub(x_l, y_u, sizex, sizey);
	result.UR = CheckBlockSub(x_r - 1, y_u, sizex, sizey);
	result.DL = CheckBlockSub(x_l, y_d - 1 , sizex, sizey);
	result.DR = CheckBlockSub(x_r - 1, y_d - 1, sizex, sizey);
	result.GL = CheckBlockSub(rx_l , y_d, sizex, sizey);
	result.GR = CheckBlockSub(rx_l - 1, y_d, sizex, sizey);

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