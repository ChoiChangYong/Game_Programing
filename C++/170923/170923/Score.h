#pragma once
#include "Scene.h"
#include <string>
using namespace std;
class Score 
{
private:
	string m_strName;
	int m_nScore;
	int m_nRound;
	int m_year;
	int m_month;
	int m_day;
	int m_hour;
	int m_min;
	int m_sec;
public:
	void init(FILE* pFile);
	void Draw();

	void Draw_name();

	int getScore();

	void Save(FILE * f);

	void setName();

	Score(int score, int round);

	Score();
	~Score();
};

