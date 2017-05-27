#pragma once
#include<DxLib.h>
#include"smart_ptr.h"

PTR(Score);

class Score {
public:
	Score ();
	~Score ();

	void GetScoreData( ScorePtr &temp );
	
	int _score;

	static ScorePtr _scoredata;
};