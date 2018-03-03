#include "Word.h"
#include "Game.h"
#include <Windows.h>
#include <iostream>
#include <ctime>
using namespace std;
#define SIZE_V 62
#define BLACK 0
#define LIGHTGRAY 7
#define YELLOW 14 

void textcolor(int foreground, int background)
{
	int color = foreground + background * 16;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
void Word::gotoxy(int y, int x)
{
	COORD Pos = { y - 1, x - 1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}


void Word::Init()
{
	if (m_bWord == false)
	{
		m_x = 4;
		m_y = (rand() % SIZE_V) + 1;
		m_bWord = true;

		int temp = 0;
		temp = rand() % 10;
		if (temp > 7)
			m_nColor = 1;
	}
}

void Word::Delete()
{
	if (m_bWord == true)
	{
		for (int i = 0; i < m_strWord.length(); i++)
		{
			gotoxy(m_y + i, m_x);
			cout << " ";
		}
	}
}

void Word::Delete_all()
{
	for (int i = 0; i < m_strWord.length(); i++)
	{
		gotoxy(m_y + i, m_x);
		cout << " ";
		m_bWord = false;
	}
}

void Word::Move()
{
	m_x++;
	gotoxy(m_y, m_x);
}
bool Word::Delete_LastLine()
{
	bool bDelete_flag = false;

	if (m_bWord == true)
	{
		for (int i = 0; i < m_strWord.length(); i++)
		{
			if ((m_x == 25) || (m_x == 19 && (m_y + i > 28 && m_y + i < 51)))
			{
				m_x = 4;
				m_y = (rand() % SIZE_V) + 1;
				m_bWord = false;
				bDelete_flag = true;
				break;
			}
		}
	}
	return bDelete_flag;
}
void Word::Print()
{
	if (m_bWord == true)
	{
			if (m_nColor == 1)
			{
				textcolor(YELLOW, BLACK);
				cout << m_strWord;
				textcolor(LIGHTGRAY, BLACK);
			}
			else
			{
				cout << m_strWord;
			}
	}
}
void Word::Print_Star_Item_5()
{
	if (m_bWord == true)
	{
		for (int i = 0; i < m_strWord.length(); i++)
		{
			cout << "*";
		}
	}
}

bool Word::Compare(string strWord)
{
	int Compare_flag = false;
	if (m_strWord == strWord)
	{
		Compare_flag = true;
	}
	return Compare_flag;
}

void Word::setDie()
{
	m_bWord = false;
}

int Word::getColor()
{
	return m_nColor;
}


void Word::onCheck(Game* pGame)
{
	pGame->ScoreUp();
}

Word::Word(char* word)
{
	srand((unsigned int)time(NULL));
	m_x = 4;
	m_y = (rand() % SIZE_V) + 1;
	m_strWord = word;
	m_bWord = false;
	m_nColor = 0;
}
Word::Word()
{

}

Word::~Word()
{
}
