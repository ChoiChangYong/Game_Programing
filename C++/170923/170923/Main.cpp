#include "Scene.h"
#include "Menu.h"
#include "Story.h"
#include "Game.h"
#include "Score_Total_User.h"
#include "Score.h"

#include <iostream>
#include <Windows.h>
using namespace std;

int main()
{
	int nFlag = 0;
	system("mode con:cols=76 lines=30");
	system("title 베네치아 타자게임");

	Scene* pScene;
	while (true)
	{
		system("cls");
		pScene = new Menu();
		pScene->Draw();
		nFlag = pScene->Input();
		switch (nFlag)
		{
		case 1:
			pScene = new Story();
			if (pScene->Input() == 1)
			{
				pScene->init();
				pScene->Draw();
			}
			pScene = new Game();
			pScene->init();
			pScene->Input();
			system("cls");
			pScene->Draw();
			while (true)
			{
				pScene->Update();
				if (pScene->bGameOver_flag == true)
				{
					system("cls");
					break;
				}
			}
			pScene = new Score_Total_User();
			pScene->init();
			pScene->Draw();
			break;
		case 2:
			pScene = new Score_Total_User();
			pScene->init();
			pScene->Draw();
			break;
		case 3:
			system("cls");
			cout << endl;
			cout << "● 베네치아 타자게임을 종료합니다 ●" << endl;
			cout << endl;
			break;
		default:
			break;
		}
		if (nFlag == 3)
			break;
	}

	delete pScene;
	return 0;
}