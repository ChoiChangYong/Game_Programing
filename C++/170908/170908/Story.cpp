#include "Story.h"
#include <iostream>
#include <Windows.h>
#include <conio.h>
using namespace std;



void Story::Load()
{
	FILE* sFile;
	int i = 0;
	sFile = fopen("Story.txt", "r");
	if (sFile == 0)
		cout << "���丮 ������ �������� �ʽ��ϴ�." << endl;
	else
	{
		while (fgets(szStory[i], 50, sFile) != NULL)
		{
			i++;
			nTotal_line++;
		}
	}
	fclose(sFile);
}

void Story::Print()
{
	char c;

	int i = 0;
	int nStart = 0;
	int nEnd = 1;
	while (nEnd != nTotal_line)
	{
		cout << "**************************** ����ġ�� Ÿ�ڰ��� *****************************" << endl;
		cout << endl;
		cout << "* ������ �����Ϸ��� aŰ�� �����ÿ� *" << endl;
		cout << endl;

		for (i = nStart; i < nEnd; i++)
		{
			cout << "\t\t\t\t" << szStory[i] << endl;

		}
		if (nEnd > 7)
			nStart++;
		nEnd++;

		Sleep(1000);
		system("cls");

		if (kbhit())
		{
			c = getch();
			if (c == 'a')
				break;
		}
	}
}

Story::Story()
{
	memset(szStory, 0, sizeof(30 * 50));
}

Story::~Story()
{
}
