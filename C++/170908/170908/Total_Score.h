#pragma once
#include <iostream>
#include <vector>
using namespace std;

class Score;

class Total_Score
{
private:
	vector<Score*> vScore;
	int Score_sort[50];
	int m_nTotal;
	int m_nCount;
	int m_nNum;
	FILE* m_pF;
public:
	void Load();
	void OutputData();
	void Save(Score* p_score, char* p_chName);
	void Sort();
	Total_Score();
	~Total_Score();
};

