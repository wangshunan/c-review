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

DecisionCheck::AtariInfo DecisionCheck::CheckBlock(float x, float y, float rx, float ry, int sizex, int sizey) {
	AtariInfo result;
	float x_l, x_r, y_u, y_d, rx_l, rx_r;
	x_l = x + 22;
	x_r = x + sizex - 22;
	y_u = y + 18;
	y_d = y + sizey - 8;
	rx_l = rx + 22;
	rx_r = rx + sizex - 22;
	result.UL = CheckBlockSub(x_l, y_u);
	result.UR = CheckBlockSub(x_r, y_u);
	result.DL = CheckBlockSub(x_l, y_d - 1);
	result.DR = CheckBlockSub(x_r, y_d - 1);
	result.GL = CheckBlockSub(rx_l, y_d);
	result.GR = CheckBlockSub(rx_r - 1, y_d);

	if ((result.UL || result.UR) && !result.DL && !result.DR) {
		int mx;
		result.UL == TRUE ? mx = (int)(x_l / _mapdata->CHIP_SIZE) : mx = (int)(x_r / _mapdata->CHIP_SIZE);
		int my = (int)(y / _mapdata->CHIP_SIZE);
		if (_mapdata->_data[my][mx] == '1' && _mapdata->_data[my + 1][mx] != '1') {
			int py = (int)((ry + 16) / _mapdata->CHIP_SIZE);
			if (py > my) {
				_iscollision = TRUE;
			}
		}
	}
	else {
		_iscollision = FALSE;
	}

	if (CheckHitKey(KEY_INPUT_C)) {
		int i = 0;
	}

	return result;
}

DecisionCheck::AtariInfo DecisionCheck::CheckCoin(float x, float y, int sizex, int sizey, bool flipx) {
	AtariInfo result;
	float rx;

	// 左右距離offset
	if (flipx) {
		rx = x + 22 + 12;
	}
	else {
		rx = x + sizex - 32;
	}
	
	result.COIN = CheckCoinSub(rx, y + sizey / 2);

	return result;

}

BOOL DecisionCheck::CheckBlockSub(float x, float y) {
	int mx = (int)(x / _mapdata -> CHIP_SIZE);
	int my = (int)(y / _mapdata -> CHIP_SIZE);

	//マップ範囲外ならTRUE
	if (mx < 0 || mx >= _mapdata->_stagedata.mapwitdh) {
		return TRUE;
	}

	if (_mapdata->_data[my][mx] == '1') {
		return TRUE;
	}
	return FALSE;
}

BOOL DecisionCheck::CheckCoinSub(float x, float y) {
	int mx = (int)(x / _mapdata->CHIP_SIZE);
	int my = (int)(y / _mapdata->CHIP_SIZE);

	if (_mapdata->_data[my][mx] == '2') {
		_mapdata->_data[my][mx] = '0';
		return TRUE;
	}

	return FALSE;
}