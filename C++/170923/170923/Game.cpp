#include "Game.h"
#include "Word.h"
#include "Score_Total_User.h"
#include "Score.h"
#include "Item_0_None.h"
#include "Item_1_Fast.h"
#include "Item_2_Slow.h"
#include "Item_3_Stop.h"
#include "Item_4_Heal.h"
#include "Item_5_Blind.h"
#include "Item_6_AllDelete.h"

#include <time.h>
#include <ctime>
#include <iostream>
#include <Windows.h>
#include <conio.h>
using namespace std;
#define X_ 21
#define Y_ 31
#define X_Life 24
#define Y_Life 30

// 커서의 x 좌표를 조사한다. 
int wherex()
{
	CONSOLE_SCREEN_BUFFER_INFO BufInfo;



	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &BufInfo);
	return BufInfo.dwCursorPosition.X;
}

// 커서의 y좌표를 조사한다. 
int wherey()
{
	CONSOLE_SCREEN_BUFFER_INFO BufInfo;



	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &BufInfo);
	return BufInfo.dwCursorPosition.Y;
}

//////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////

void Game::Print_user_input()
{
	gotoxy(29, 19);
	cout << "┌";
	gotoxy(31, 19);
	cout << "─────────";
	gotoxy(30, 20);
	cout << "                   ";
	gotoxy(30, 22);
	cout << "                   ";
	gotoxy(29, 23);
	cout << "└";
	gotoxy(29, 20);
	cout << "│";
	gotoxy(29, 21);
	cout << "│";
	gotoxy(29, 22);
	cout << "│";
	gotoxy(49, 19);
	cout << "┐";
	gotoxy(31, 23);
	cout << "─────────";
	gotoxy(49, 23);
	cout << "┘";
	gotoxy(49, 20);
	cout << "│";
	gotoxy(49, 21);
	cout << "│";
	gotoxy(49, 22);
	cout << "│";
}
void Game::Print_ItemUsed()
{
	gotoxy(1, 26);
	cout << "┌";
	gotoxy(3, 26);
	cout << "───────────";
	gotoxy(1, 29);
	cout << "└";
	gotoxy(1, 27);
	cout << "│";
	gotoxy(1, 28);
	cout << "│";
	gotoxy(23, 26);
	cout << "┐";
	gotoxy(3, 29);
	cout << "───────────";
	gotoxy(23, 29);
	cout << "┘";
	gotoxy(23, 27);
	cout << "│";
	gotoxy(23, 28);
	cout << "│";
}
void Game::Print_LastLine()
{
	gotoxy(1, 25);
	cout << "───────────────────────────────────────";
}
void Game::Print_Top()
{
	gotoxy(1, 1);
	cout << "**************************** 베네치아 타자게임 *****************************" << endl;
	gotoxy(1, 3);
	cout << "***************************** 단계: " << m_nRound << "  점수: " << m_nScore << " **************************" << endl;
}
void Game::Print_Round()
{
	gotoxy(37, 3);
	cout << m_nRound;
}
void Game::Print_Score()
{
	gotoxy(46, 3);
	cout << m_nScore << " ";
}

void Game::Print_Life()
{
	if (m_nLife >= 0)
	{
		for (int i = 0; i < m_nLife; i++)
		{
			gotoxy(Y_Life + i * 2, X_Life);
			cout << "■";
		}
	}
}
void Game::Print_Life_Minus()
{
	if (m_nLife >= 0)
	{
		for (int i = 0; i < m_nLife; i++)
		{
			gotoxy(Y_Life + i * 2, X_Life);
			cout << " ";
		}
		m_nLife--;
		for (int i = 0; i < m_nLife; i++)
		{
			gotoxy(Y_Life + i * 2, X_Life);
			cout << "■";
		}

	}
}

//////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////

void Game::RoundUp()
{
	for (int i = 0; i < m_nWord_total; i++)
	{
		m_vWord[i]->Delete_all();
	}

	if (m_nRound < 6)
	{
		m_nRound++;

		system("cls");
		gotoxy(30, 15);
		cout << m_nRound << "단계로 올라갑니다.";
		Sleep(2000);
		gotoxy(30, 15);
		cout << "                        ";

		system("cls");
		Draw();
	}
}

//////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////

bool Game::GameOver()
{
	if (m_nLife == 0)
	{
		bGameOver_flag = true;
		system("cls");
		cout << "G a m e O v e r ! ! !" << endl;
		Sleep(1000);
		Save();
	}
	return bGameOver_flag;
}

bool Game::GameClear()
{
	bGameOver_flag = true;
	system("cls");
	cout << "☆ ★ ☆ ★ G a m e C l e a r ☆ ★ ☆ ★" << endl;
	Sleep(1000);
	Save();
	return bGameOver_flag;
}

//////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////
void Game::Save()
{
	Score* pScore = new Score(m_nScore, m_nRound);
	pScore->setName();

	Score_Total_User* pTotalUser = new Score_Total_User();
	pTotalUser->init();
	pTotalUser->AddScore(pScore);

	pTotalUser->Save();
}

//////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////

void Game::ScoreUp()
{
	m_nScore = m_nScore + 100;
}
void Game::Item_Time_Check(int m_nGame_Time_Check)
{
	if (m_nItem_Time_Check + 5 >= 60)
	{
		m_nItem_Time_Check = m_nItem_Time_Check - 60;
	}
	if (m_nGame_Time_Check == (m_nItem_Time_Check + 5))
	{
		ItemDelete();
	}
}
void Game::Use_Item_1_Fast()
{
	timer = time(NULL);
	t = localtime(&timer);

	m_nItem_1_Fast = -40;
	m_nItem_Time_Check = t->tm_sec;

	ScoreUp();
	ItemUse("아이템 발동!!!", "1. 빨리 떨어지기");
}
void Game::Use_Item_2_Slow()
{
	timer = time(NULL);
	t = localtime(&timer);

	m_nItem_2_Slow = 40;
	m_nItem_Time_Check = t->tm_sec;

	ScoreUp();
	ItemUse("아이템 발동!!!", "2. 천천히 떨어지기");
}
void Game::Use_Item_3_Stop()
{
	timer = time(NULL);
	t = localtime(&timer);

	m_nItem_3_Stop = true;
	m_nItem_Time_Check = t->tm_sec;

	ScoreUp();
	ItemUse("아이템 발동!!!", "3. 멈추기");
}
void Game::Use_Item_4_Heal()
{
	timer = time(NULL);
	t = localtime(&timer);

	m_nItem_Time_Check = t->tm_sec;

	m_nLife++;
	Print_Life();
	ScoreUp();
	ItemUse("아이템 발동!!!", "4. 체력회복");
}

void Game::Use_Item_5_Blind()
{
	timer = time(NULL);
	t = localtime(&timer);

	m_nItem_5_Blind = true;
	m_nItem_Time_Check = t->tm_sec;

	ScoreUp();
	ItemUse("아이템 발동!!!", "5. *로 글자 가리기");
}

void Game::Use_Item_6_AllDelete()
{
	timer = time(NULL);
	t = localtime(&timer);

	m_nItem_Time_Check = t->tm_sec;

	for (int i = 0; i < m_nWord_total; i++)
	{
		m_vWord[i]->Delete_all();
	}

	ScoreUp();
	ItemUse("아이템 발동!!!", "6. 전체 지우기");
}

void Game::ItemUse(string Item_name, string Item_effect)
{
	gotoxy(3, 27);
	cout << Item_name;
	gotoxy(3, 28);
	cout << Item_effect;
	gotoxy(1, 26);
	cout << "┌";
	gotoxy(3, 26);
	cout << "───────────";
	gotoxy(1, 29);
	cout << "└";
	gotoxy(1, 27);
	cout << "│";
	gotoxy(1, 28);
	cout << "│";
	gotoxy(23, 26);
	cout << "┐";
	gotoxy(3, 29);
	cout << "───────────";
	gotoxy(23, 29);
	cout << "┘";
	gotoxy(23, 27);
	cout << "│";
	gotoxy(23, 28);
	cout << "│";
}

void Game::ItemDelete()
{
	nRandom = 0;
	m_nItem_1_Fast = 0;
	m_nItem_2_Slow = 0;
	m_nItem_3_Stop = false;
	m_nItem_5_Blind = false;

	gotoxy(3, 27);
	cout << "              ";
	gotoxy(3, 28);
	cout << "                    ";
}

//////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////

void Game::Input_Word()
{
	gotoxy(Y_ + m_chInputData_index, X_);
	if (kbhit())
	{
		int nTemp;
		nTemp = getche();

		if (Y_ + m_chInputData_index < 48)
		{
			m_chInputData[m_chInputData_index] = nTemp;
			m_chInputData_index++;
		}

		//빽 스페이스바로 글자 지우기
		if (nTemp == 8)
		{
			//시작점 이상으로 지워지지 않게 함
			if (m_chInputData_index <= 2)
			{
				m_chInputData_index = 1;
			}
			else
			{
				if (Y_ + m_chInputData_index == 48)
				{
					cout << "  ";
				}
				m_chInputData_index--;
				m_chInputData[m_chInputData_index] = NULL;
				m_chInputData_index--;
				m_chInputData[m_chInputData_index] = NULL;

				gotoxy(Y_ + m_chInputData_index, X_);
				cout << " ";
			}
		}

		// 엔터 입력 시
		if (nTemp == 13)
		{
			for (int i = 1; i < m_chInputData_index - 1; i++)
			{
				m_strCopyData += m_chInputData[i];
			}
			for (int i = 1; i < m_chInputData_index - 1; i++)
			{
				gotoxy(Y_ + i, X_);
				cout << " ";
			}
			m_chInputData_index = 1;

			for (int i = 0; i < m_nWord_total; i++)
			{
				if (m_vWord[i]->Compare(m_strCopyData))
				{
					m_vWord[i]->Delete();
					m_vWord[i]->setDie();

					if (m_vWord[i]->getColor() == 1)
					{
						nRandom = rand() % 7;
						p_szItem[nRandom]->onCheck(this);
					}
					else
						m_vWord[i]->onCheck(this);

					Print_Score();
					break;
				}
			}
			m_strCopyData = "";
		}
	}
	for (int i = 1; i < m_chInputData_index; i++)
	{
		gotoxy(Y_ + i, X_);
		cout << m_chInputData[i];
	}
	gotoxy(Y_ + m_chInputData_index, X_);

}

//////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////

void Game::init()
{
	FILE* pFile;
	pFile = fopen("Hackers_Voca.txt", "r");
	if (pFile == 0)
		cout << "단어장 파일이 존재하지 않습니다." << endl;
	else
	{
		char szTemp[20];
		fscanf(pFile, "%d ", &m_nWord_total);

		while (m_nWord_total != 0 && m_nWord_count != m_nWord_total)
		{
			m_nWord_count++;

			fscanf(pFile, "%s \n", szTemp);
			Word* pWord = new Word(szTemp);
			m_vWord.push_back(pWord);
		}
	}
	fclose(pFile);
}

int Game::Input()
{
	cout << "시작단계를 선택해주세요. (1 - 5)" << endl;
	cin >> m_nRound;
	return 0;
}

void Game::Draw()
{
	Print_Top();
	Print_user_input();
	Print_LastLine();
	Print_ItemUsed();
	Print_Life();
}

void Game::Update()
{
	time_t timer;
	struct tm *t;
	timer = time(NULL);
	t = localtime(&timer);

	m_nGame_Time_Check = t->tm_sec;
	
	if (nRandom != 0)
		Item_Time_Check(m_nGame_Time_Check);

	if (m_nItem_3_Stop == false)
	{
		if (m_nTimer % (m_szRound[m_nRound - 1][0] + m_nItem_1_Fast) == 0)
		{
			for (int i = 0; i < m_nWord_total; i++)
			{
				m_vWord[i]->Delete();
			}
			for (int i = 0; i < m_nWord_total; i++)
			{
				m_vWord[i]->Move();

				if (m_vWord[i]->Delete_LastLine())
					Print_Life_Minus();
				
				if (m_nItem_5_Blind == true)
					m_vWord[i]->Print_Star_Item_5();
				else
					m_vWord[i]->Print();
			}
			int ntemp = 0;
			ntemp = rand() % (m_nWord_total);
			m_vWord[ntemp]->Init();
		}
		m_nTimer++;
		Sleep(10);
	}

	Input_Word();

	if (m_nScore == m_nRound * 500)
		RoundUp();

	if (m_nRound == 6)
		GameClear();

	GameOver();
}

void Game::Release()
{
}

Game::Game()
{
	srand((unsigned int)time(NULL));

	m_nRound = 1;
	m_nScore = 0;
	m_nWord_total = 0;
	m_nWord_count = 0;

	m_nTimer = 1;

	m_chInputData_index = 1;
	string m_strCopyData = "";

	m_nLife = 10;
	
	m_szRound[0][0] = 200;
	m_szRound[1][0] = 170;
	m_szRound[2][0] = 140;
	m_szRound[3][0] = 110;
	m_szRound[4][0] = 60;
	m_szRound[0][1] = 0;
	m_szRound[1][1] = 0;
	m_szRound[2][1] = 0;
	m_szRound[3][1] = 0;
	m_szRound[4][1] = 0;

	m_nGame_Time_Check = 0;
	m_nItem_Time_Check = 0;

	m_nItem_1_Fast = 0;
	m_nItem_2_Slow = 0;
	m_nItem_3_Stop = false;
	m_nItem_5_Blind = false;

	p_szItem[0] = new Item_0_None();
	p_szItem[1] = new Item_1_Fast();
	p_szItem[2] = new Item_2_Slow();
	p_szItem[3] = new Item_3_Stop();
	p_szItem[4] = new Item_4_Heal();
	p_szItem[5] = new Item_5_Blind();
	p_szItem[6] = new Item_6_AllDelete();

	nRandom = 0;
}


Game::~Game()
{
}
