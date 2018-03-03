#include "Virus.h"
#include "Life.h"
#include "Score.h"
#include <iostream>
#include <ctime>
#include <Windows.h>
using namespace std;

#define SIZE_V 65
#define BLACK 0
#define LIGHTGRAY 7
#define YELLOW 14 

void textcolor(int foreground, int background)
{
	int color = foreground + background * 16;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}


void gotoxy(int y, int x)
{
	COORD Pos = { y - 1, x - 1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

void Virus::Init()
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

void Virus::Delete()
{
	if (m_bWord == true)
	{
		for (int i = 0; i < m_strWord.length(); i++)
		{
			gotoxy(m_y+i, m_x);
			cout << " ";
		}
	}
}
void Virus::Delete_all()
{
	for (int i = 0; i < m_strWord.length(); i++)
	{
		gotoxy(m_y+i, m_x);
		cout << " ";
		m_bWord = false;
	}
}

void Virus::Print(Life* pLife, int temp_flag_item_5, Score* pScore)
{
	if (m_bWord == true)
	{
		m_x++;
		gotoxy(m_y, m_x);
		
		for (int i = 0; i < m_strWord.length(); i++)
		{
			if (m_x == 19 && (m_y + i > 28 && m_y + i < 51))
			{
				pLife->Minus(pScore);
				m_bWord = false;
				break;
			}
		}

		if (m_bWord == true)
		{
			if (temp_flag_item_5 == 0)
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
			else
			{
				for (int i = 0; i < m_strWord.length(); i++)
				{
					cout << "*";
				}
			}

			if (m_x == 25)
			{
				for (int i = 0; i < m_strWord.length(); i++)
				{
					gotoxy(m_y + i, m_x);
					cout << " ";
				}

				m_bWord = false;

				pLife->Minus(pScore);
			}
		}
	}
}

string Virus::getWord()
{
	if (m_bWord == true)
		return m_strWord;
	else
		return "NotValue";
}

int Virus::getColor()
{
	return m_nColor;
}

void Virus::setDie()
{
	m_bWord = false;
}

Virus::Virus(char* w)
{
	//m_strWord = new char[30];

	m_x = 4;
	m_y = (rand() % SIZE_V) + 1;
	m_strWord = w;
	m_bWord = false;
	m_nColor = 0;
}

Virus::Virus()
{
}


Virus::~Virus()
{
}
