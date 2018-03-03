#include "Game.h"
#include "Virus.h"
#include "Round.h"
#include "Score.h"
#include "Life.h"
#include "Item.h"
#include "Total_Score.h"

#include <time.h>
#include <ctime>
#include <conio.h>
#include <iostream>
#include <Windows.h>
#define X 21
#define Y 31
using namespace std;

void gotoxy_Game(int y, int x)
{
	COORD Pos = { y - 1, x - 1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

void Game::Input_print()
{
	gotoxy_Game(29, 19);
	cout << "┌";
	gotoxy_Game(31, 19);
	cout << "─────────";
	gotoxy_Game(30, 20);
	cout << "                   ";
	gotoxy_Game(30, 22);
	cout << "                   ";
	gotoxy_Game(29, 23);
	cout << "└";
	gotoxy_Game(29, 20);
	cout << "│";
	gotoxy_Game(29, 21);
	cout << "│";
	gotoxy_Game(29, 22);
	cout << "│";
	gotoxy_Game(49, 19);
	cout << "┐";
	gotoxy_Game(31, 23);
	cout << "─────────";
	gotoxy_Game(49, 23);
	cout << "┘";
	gotoxy_Game(49, 20);
	cout << "│";
	gotoxy_Game(49, 21);
	cout << "│";
	gotoxy_Game(49, 22);
	cout << "│";
}
void Game::LastLine_print()
{
	gotoxy_Game(1, 25);
	cout << "───────────────────────────────────────";
}
void Game::TopPrint()
{
	gotoxy_Game(1, 1);
	cout << "**************************** 베네치아 타자게임 *****************************" << endl;
	gotoxy_Game(1, 3);
	cout << "***************************** 단계: " << m_nRound_num << "  점수: " << pScore->getScore() << " ***************************" << endl;
}

void Game::RoundUp()
{
	time_t timer;
	struct tm * t;

	for (int i = 0; i < m_nVirus_total; i++)
	{
		m_vVirus[i]->Delete_all();
	}
	m_nRound_num++;

	if (m_nRound_num == 6)
	{
		FILE* f;
		char name[20];
		timer = time(NULL);
		t = localtime(&timer);

		system("cls");
		cout << "G a m e C l e a r ! ! !" << endl;
		cout << "이름을 입력해주세요." << endl;
		cin >> name;

		pTotalScore->Load();
		pTotalScore->Save(pScore, name);
	}

	system("cls");
	gotoxy_Game(30, 15);
	cout << m_nRound_num << "단계로 올라갑니다.";
	Sleep(2000);
	gotoxy_Game(30, 15);
	cout << "                        ";
	TopPrint();
	Input_print();
}

void Game::InputData()
{
	gotoxy_Game(Y + m_chInputData_index, X);
	if (kbhit())
	{
		int nTemp;
		nTemp = getche();

		if (Y + m_chInputData_index < 48)
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
				if (Y + m_chInputData_index == 48)
				{
					cout << "  ";
				}
				m_chInputData_index--;
				m_chInputData[m_chInputData_index] = NULL;
				m_chInputData_index--;
				m_chInputData[m_chInputData_index] = NULL;

				gotoxy_Game(Y + m_chInputData_index, X);
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
				gotoxy_Game(Y + i, X);
				cout << " ";
			}
			m_chInputData_index = 1;

			for (int i = 0; i < m_nVirus_total; i++)
			{
				if (m_strCopyData == m_vVirus[i]->getWord())
				{
					m_vVirus[i]->Delete();
					m_vVirus[i]->setDie();
					pScore->setScore();

					//아이템 발동 시
					if ((m_vVirus[i]->getColor()) == 1)
					{
						m_nItem_number = rand() % 6 + 1;
						m_nItem_number = 6;
						if (m_nItem_number == 1 || m_nItem_number == 2)
							Item_speed_1_2 = (pItem->ItemUsed(m_nItem_number));
						if (m_nItem_number == 3)
							Item_flag_3 = (pItem->ItemUsed(m_nItem_number));
						if (m_nItem_number == 4)
							pItem->ItemUsed(m_nItem_number, pLife);
						if (m_nItem_number == 5)
							Item_flag_5 = (pItem->ItemUsed(m_nItem_number));
						if (m_nItem_number == 6)
							pItem->ItemUsed(m_nItem_number, m_vVirus, m_nVirus_total);
					}

					TopPrint();
					break;
				}
			}
			m_strCopyData = "";
		}
	}
	for (int i = 1; i < m_chInputData_index; i++)
	{
		gotoxy_Game(Y + i, X);
		cout << m_chInputData[i];
	}
	gotoxy_Game(Y + m_chInputData_index, X);

}

void Game::Load()
{
	FILE* vFile;
	vFile = fopen("Hackers_Voca.txt", "r");
	if (vFile == 0)
		cout << "단어장 파일이 존재하지 않습니다." << endl;
	else
	{
		char szTemp[20];
		fscanf(vFile, "%d ", &m_nVirus_total);

		while (m_nVirus_total != 0 && m_nVirus_count != m_nVirus_total)
		{
			m_nVirus_count++;

			fscanf(vFile, "%s \n", szTemp);
			Virus* pVirus = new Virus(szTemp);
			m_vVirus.push_back(pVirus);
		}
	}
	fclose(vFile);
}

void Game::StartGame(int nround)
{	

	Input_print();
	LastLine_print();

	pItem = new Item();

	m_nRound_num = nround;

	TopPrint();
	
	while (true)
	{
		time_t timer;
		struct tm *t;

		timer = time(NULL);
		t = localtime(&timer);

		int time_second = t->tm_sec;
	

		if ((pScore->getScore()) == m_nRound_num * 500)
		{
			RoundUp();
		}
		if (Item_flag_3 == 0)
		{
			if (m_nTimer % (pRound->setDelay(m_nRound_num) + Item_speed_1_2) == 0)
			{
					for (int i = 0; i < m_nVirus_total; i++)
					{
						m_vVirus[i]->Delete();
					}
					for (int i = 0; i < m_nVirus_total; i++)
					{
						m_vVirus[i]->Print(pLife, Item_flag_5, pScore);
					}
				int ntemp = 0;
				ntemp = rand() % (m_nVirus_total - 1);
				m_vVirus[ntemp]->Init();
			}
			m_nTimer++;

			Item_speed_1_2 = pItem->ItemCheck_1_2(time_second);

			Item_flag_5 = pItem->ItemCheck_5(time_second);

			Sleep(10);

		}
		else 
		{
			Item_flag_3 = (pItem->ItemCheck_3(time_second));
		}

		pLife->Print();
		LastLine_print();

		InputData();
	}
}

Game::Game()
{
	srand((unsigned int)time(NULL));

	m_vVirus.reserve(1024);
	m_nVirus_total = 0;
	m_nVirus_count = 0;

	m_chInputData_index = 1;

	m_nRound_num = 1;


	m_nTimer = 1;

	pRound = new Round();

	pTotalScore = new Total_Score();
	pScore = new Score();

	pLife = new Life();


	m_nItem_number = 0;


	Item_flag_3 = 0;

	Item_flag_1_2 = 0;
	Item_speed_1_2 = 0;

	Item_flag_5 = 0;

	m_bGameClear = false;
}


Game::~Game()
{
}
