#include "Score.h"
#include <time.h>
#include <iostream>
using namespace std;



void Score::setScore()
{
	m_nScore = m_nScore + 100;
}

int Score::getScore()
{
	return m_nScore;
}

void Score::Load(FILE * f)
{
	fscanf(f, "%s %d %d %d %d %d %d %d \n", m_name, &m_nScore, &m_year, &m_month, &m_day, &m_hour, &m_min, &m_sec);
}
void Score::OutputData()
{
	cout << m_year << "년" << m_month << "월" << m_day << "일 " << m_hour << "시" << m_min << "분" << m_sec << "초" << endl;
}

void Score::OutputData_name()
{
	cout << m_name << "   ";
}

void Score::Save(FILE * f, bool bNew_flag, char* p_chName)
{
	time_t timer;
	struct tm *t;

	timer = time(NULL);
	t = localtime(&timer);
	
	if (bNew_flag == true)
	{
		m_year = t->tm_year + 1900;
		m_month = t->tm_mon + 1;
		m_day = t->tm_mday;
		m_hour = t->tm_hour;
		m_min = t->tm_min;
		m_sec = t->tm_sec;
	}
	fprintf(f, "%s %d %d %d %d %d %d %d \n", m_name, m_nScore, m_year, m_month, m_day, m_hour, m_min, m_sec);
}

Score::Score()
{
	m_nScore = 0;
	m_year = 0;
	m_month = 0;
	m_day = 0;
	m_hour = 0;
	m_min = 0;
	m_sec = 0;
}


Score::~Score()
{
}
