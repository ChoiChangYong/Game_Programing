#include "Score.h"
#include <time.h>
#include <string>
#include <iostream>
using namespace std;



void Score::init(FILE* pFile)
{
	char name_[20] = "";
	fscanf(pFile, "%s %d %d %d %d %d %d %d %d \n", name_, &m_nScore, &m_nRound, &m_year, &m_month, &m_day, &m_hour, &m_min, &m_sec);
	m_strName = name_;
}

void Score::Draw()
{
	cout << "\t" << m_nScore << "��\t" << m_nRound << "�ܰ�\t" << m_year << "��" << m_month << "��" << m_day << "�� " << m_hour << "��" << m_min << "��" << m_sec << "��" << endl;
}
void Score::Draw_name()
{
	cout << m_strName;
}

int Score::getScore()
{
	return m_nScore;
}

void Score::Save(FILE * f)
{
	fprintf(f, "%s %d %d %d %d %d %d %d %d \n", m_strName.c_str(), m_nScore, m_nRound, m_year, m_month, m_day, m_hour, m_min, m_sec);
}
void Score::setName()
{
	string name;

	cout << "�̸��� �Է����ּ���.(�ִ� �ѱ� 3����)" << endl;
	cin >> name;

	m_strName = name;
}
Score::Score(int score, int round)
{
	time_t timer;
	struct tm *t;

	timer = time(NULL);
	t = localtime(&timer);

	m_nScore = score;
	m_nRound = round;
	m_year = t->tm_year + 1900;
	m_month = t->tm_mon + 1;
	m_day = t->tm_mday;
	m_hour = t->tm_hour;
	m_min = t->tm_min;
	m_sec = t->tm_sec;
}
Score::Score()
{
	m_nScore = 0;
	m_nRound = 0;
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
