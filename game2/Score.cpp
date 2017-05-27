#include<DxLib.h>
#include"Score.h"

ScorePtr Score::_scoredata;
Score::Score() {
	_score = 0;
}

Score::~Score() {

}

void Score::GetScoreData( ScorePtr &temp ){

	if (!_scoredata) {
		_scoredata = ScorePtr( new Score );
	}
	
	temp = _scoredata;
}