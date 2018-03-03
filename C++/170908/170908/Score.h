#pragma once
#include <iostream>
class Score
{
private:
	char m_name[20];
	int m_nScore;
	int m_year;
	int m_month;
	int m_day;
	int m_hour;
	int m_min;
	int m_sec;
public:
	void setScore();
	int getScore();

	void Load(FILE* f);
	void OutputData();
	void OutputData_name();
	void Save(FILE* f, bool bNew_flag, char* p_chName);
	Score();
	~Score();
};

