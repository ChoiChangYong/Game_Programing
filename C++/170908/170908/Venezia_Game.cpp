#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <string>
#include <vector>
#include <ctime>

#include "Virus.h"
#include "Story.h"
#include "Game.h"
#include "Total_Score.h"
using namespace std;


int main()
{
	Story* pStory = new Story();
	Game* pGame = new Game();
	FILE* f;
	Total_Score* pScore = new Total_Score();

	int count = 1;
	int nRound = 1;

	//스토리 다운로드
	pStory->Load();
	//단어장 다운로드
	pGame->Load();

	int nFlag = 0;
	while (true)
	{
		system("cls");

		cout << "******************************* 메뉴 ********************************" << endl;
		cout << "1.  게임시작" << endl;
		cout << "2.  단계조정" << endl;
		cout << "3.  점수판" << endl;
		cout << "4.  종료" << endl;

		cin >> nFlag;

		switch (nFlag)
		{
		case 1:
			system("cls");

			pStory->Print();
			pGame->StartGame(nRound);
			break;
		case 2:
			cout << "시작하실 라운드를 입력해 주세요 : ";
			cin >> nRound;

			system("cls");

			pStory->Print();
			pGame->StartGame(nRound);
			break;
		case 3:
			pScore->Load();
			//pScore->Sort();
			pScore->OutputData();
			break;
		case 4:
			break;
		default:
			break;
		}
		if (nFlag == 4)
			break;
	}
	delete pScore;
	delete pStory;
	delete pGame;
	return 0;
}