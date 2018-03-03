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

	//���丮 �ٿ�ε�
	pStory->Load();
	//�ܾ��� �ٿ�ε�
	pGame->Load();

	int nFlag = 0;
	while (true)
	{
		system("cls");

		cout << "******************************* �޴� ********************************" << endl;
		cout << "1.  ���ӽ���" << endl;
		cout << "2.  �ܰ�����" << endl;
		cout << "3.  ������" << endl;
		cout << "4.  ����" << endl;

		cin >> nFlag;

		switch (nFlag)
		{
		case 1:
			system("cls");

			pStory->Print();
			pGame->StartGame(nRound);
			break;
		case 2:
			cout << "�����Ͻ� ���带 �Է��� �ּ��� : ";
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