#include "Map.h"
#include "Virus.h"
#include <iostream>
#include <cstring>
#include <Windows.h>
#include <conio.h>
#include <vector>
using namespace std;

#define SIZE_H 15
#define SIZE_V 10
#define WALL 100
#define BLANK 0

void Map::gotoxy(int x, int y)
{
	COORD Pos = { x - 1, y - 1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

void Map::mPrint(vector<Virus*> vVirus)
{
	while (true)
	{
		cout << "**************************** 베네치아 타자게임 *****************************" << endl;
		cout << endl;
		cout << "**************************** 단계: 1 점수: 0 *****************************" << endl;
		cout << endl;

		for (int i = 0; i < 15; ++i)
		{
		}

		Sleep(1000);
		system("cls");
	}
}

Map::Map()
{
	memset(map, 0, sizeof(SIZE_H*SIZE_V));
}


Map::~Map()
{
}
