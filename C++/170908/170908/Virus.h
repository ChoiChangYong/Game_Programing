#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Life;
class Score;
class Virus
{
private:
	int m_x;
	int m_y;
	string m_strWord;
	int m_nColor;
	bool m_bWord;
public:
	void Init();
	void Delete();
	void Delete_all();
	void Print(Life* pLife, int m_nItem_number, Score* pScore);

	string getWord();
	int getColor();
	void setDie();
	Virus(char* w);
	Virus();
	~Virus();
};