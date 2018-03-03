#include <stdio.h>
#include <stdlib.h>
#include <ctime>
#include <iostream>
#include <Windows.h>
#include <conio.h>
using namespace std;

#define SIZE_H 20
#define SIZE_V 20
#define SIZE_MAXDDONG 100
#define BLANK 0
#define WALL 100
#define DDONG 1


int map[SIZE_H][SIZE_V];


struct DDONG_S {
	int x;
	int y;
	bool live;
};
DDONG_S d[SIZE_MAXDDONG];


/*
 * 맵 그리기
 */
void Print(int y, int x)
{
	for (int i = 0; i < SIZE_H; i++)
	{
		for (int j = 0; j < SIZE_V; j++)
		{
			if (i == y && j == x)
			{
				cout << "＊";
				continue;
			}
			if (map[i][j] == BLANK) cout << "  ";
			if (map[i][j] == WALL) cout << "벽";
			if (map[i][j] == DDONG) cout << "♨";
		}
		cout << endl;
	}
	cout << endl;
}

/*
 * 똥 떨어뜨리기
 */
void DDrop()
{
	for (int i = 0; i < SIZE_MAXDDONG; i++)
	{
		if (d[i].live == true)
		{
			map[d[i].y][d[i].x] = DDONG;
		}
	}
	for (int i = 0; i < SIZE_MAXDDONG; i++)
	{
		if (d[i].live == true)
		{
			map[d[i].y][d[i].x] = BLANK;
			d[i].y++;
		}
	}
	for (int i = 0; i < SIZE_MAXDDONG; i++)
	{
		if (d[i].live == true)
		{
			map[d[i].y][d[i].x] = DDONG;
			if (d[i].y == SIZE_H)
			{
				d[i].y = 0;
				d[i].x = 0;
				d[i].live = false;
			}
		}
	}

	for (int i = 0; i < SIZE_MAXDDONG; i++)
	{
		if (d[i].live == false)
		{
			d[i].x = (rand() % (SIZE_V - 2)) + 1;
			d[i].live = true;
			break;
		}
	}
}

/*
 * 게임오버조건
 */
int GameOver(int y, int x)
{
	for (int i = 0; i < SIZE_MAXDDONG; i++)
	{
		if (d[i].y == y && d[i].x == x)
		{
			cout << "*************** 게임오버 ***************" << endl;
			return 1;
		}
	}
	return 2;
}

int main() 
{

	char c;
	int y = SIZE_H-1;
	int x = SIZE_V / 2;
	srand((unsigned int)time(NULL));

	for (int i = 0; i < SIZE_MAXDDONG; i++)
	{
		d[i].y = 0;
		d[i].x = (rand() % (SIZE_V - 2)) + 1;
		d[i].live = false;
	}

	memset(map, 0, sizeof(SIZE_H*SIZE_V));

	for (int i = 0; i < SIZE_H; i++)
	{
		for (int j = 0; j < SIZE_V; j++)
		{
			if ((j == 0) || (j == SIZE_H - 1))
			{
				map[i][j] = WALL;
			}
		}
	}

	

	//키 입력
	while (true)
	{
		if (kbhit())
		{
			c = getch();
			switch (c) {
			case 'a':
				if (x == 1)
					break;

				x = x - 1;
				break;
			case 'd':
				if (x == SIZE_V - 2)
					break;

				x = x + 1;
				break;
			default:
				break;
			}
		}
		system("cls");
	
		DDrop();

		Print(y, x);

		Sleep(1000 / 30);


		if (GameOver(y, x) == 1) return 0;
	}
	return 0;
}
