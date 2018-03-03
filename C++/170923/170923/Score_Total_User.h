#pragma once
#include "Scene.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Score;
class Score_Total_User :
	public Scene
{
private:
	vector<Score*> m_vScore;
	int m_nTotal;
	int m_nNum;
	FILE* m_pFile;
public:
	virtual void init();
	virtual int Input();
	virtual void Draw();
	virtual void Update();
	virtual void Release();
	void AddScore(Score * pScore);
	void Save();
	void Sort();
	Score_Total_User();
	~Score_Total_User();
};

