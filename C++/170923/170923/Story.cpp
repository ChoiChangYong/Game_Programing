#include "Story.h"
#include <iostream>
#include <Windows.h>
#include <conio.h>
using namespace std;



void Story::init()
{
	FILE* sFile;
	int i = 0;
	sFile = fopen("Story.txt", "r");
	if (sFile == 0)
		cout << "스토리 파일이 존재하지 않습니다." << endl;
	else
	{
		while (fgets(szStory[i], 50, sFile) != NULL)
		{
			i++;
			nTotal_line++;
		}
		fclose(sFile);
	}
}

int Story::Input()
{
	cout << "스토리를 보시겠습니까? Yes : 1, No : 2" << endl;
	cin >> nStory_flag;
	return nStory_flag;
}

void Story::Draw()
{
	system("cls");
	char chFlag;

	int nIndex = 0;
	int nStart = 0;
	int nEnd = 1;
	while (nEnd != nTotal_line)
	{
		cout << "**************************** 베네치아 타자게임 *****************************" << endl;
		cout << endl;
		cout << "* 게임을 시작하려면 a키를 누르시오 *" << endl;
		cout << endl;

		for (nIndex = nStart; nIndex < nEnd; nIndex++)
		{
			cout << "\t\t\t\t" << szStory[nIndex] << endl;

		}
		if (nEnd > 7)
			nStart++;
		nEnd++;

		Sleep(1000);
		system("cls");

		if (kbhit())
		{
			chFlag = getch();
			if (chFlag == 'a')
				break;
		}
	}
}

void Story::Update()
{
}

void Story::Release()
{
}

Story::Story()
{
	memset(szStory, 0, sizeof(30 * 50));
	nTotal_line = 0;
}


Story::~Story()
{
}
