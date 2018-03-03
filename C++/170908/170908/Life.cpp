#include "Life.h"
#include "Total_Score.h"
#include "Score.h"

#include <Windows.h>
#include <iostream>
#include <time.h>
using namespace std;

#define X 24
#define Y 30

void gotoxy_life(int y, int x)
{
	COORD Pos = { y - 1, x - 1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}


int Life::getLife()
{
	return m_nLife;
}

void Life::Plus()
{
	m_nLife++;
	for (int i = 0; i < m_nLife; i++)
	{
		gotoxy_life(Y + i * 2, X);
		cout << "■";
	}
}
void Life::Minus(Score* p_score)
{
	time_t timer;
	struct tm * t;

	for (int i = 0; i < m_nLife; i++)
	{
		gotoxy_life(Y + i * 2, X);
		cout << " ";
	}
	m_nLife--;
	if (m_nLife == 0)
	{
		char name[20];
		system("cls");
		cout << "G a m e O v e r ! ! !" << endl;

		timer = time(NULL);
		t = localtime(&timer);

		cout << "이름을 입력해주세요." << endl;
		cin >> name;

		pScore->Load();
		pScore->Save(p_score, name);
	}
	for (int i = 0; i < m_nLife; i++)
	{
		gotoxy_life(Y + i * 2, X);
		cout << "■";
	}
}

void Life::Print()
{
	for (int i = 0; i < m_nLife; i++)
	{
		gotoxy_life(Y + i*2, X);
		cout << "■";
	}
}

Life::Life()
{
	m_nLife = 10;
	pScore = new Total_Score();
}


Life::~Life()
{
}
