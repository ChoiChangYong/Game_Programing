#include<iostream>
#include<windows.h>
#include<conio.h>
#include<stdio.h>
#pragma warning (disable : 4996)


using namespace std;

class Block
{
public:
	int x, y;
	int delay;
};

class Player
{
public:
	int x, y;
};

void gotoxy(int x, int y)
{
	COORD Pos = { x - 1, y - 1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

bool blockEvade()
{
	Player	unit;
	Block	block[15];
	int now_speed = 150;

	unit.x = 10;
	unit.y = 20;

	for (int i = 0; i < 15; ++i)
	{
		block[i].x = rand() % 19 + 1;
		block[i].y = 3;
		block[i].delay = rand() % 20;
	}

	while (true)
	{
		Sleep(now_speed);
		system("cls");

		gotoxy(unit.x, unit.y);
		cout << "б┌";

		for (int i = 0; i < 15; ++i)
		{
			if (block[i].delay > 0)
			{
				--block[i].delay;
			}
			else
			{
				++block[i].y;

				if (block[i].y >= 21)
				{
					block[i].x = rand() % 19 + 1;
					block[i].y = 3;
				}

				gotoxy(block[i].x, block[i].y);
				cout << "бс";

				gotoxy(26, 2);
				cout << "unit x: " << unit.x;
				gotoxy(26, 3);
				cout << "unit y: " << unit.y;
				gotoxy(26, 4);
				cout << "block y: " << block[i].y;

				if (block[i].x == unit.x && block[i].y == unit.y)
					return false;

			}
		}

		while (_kbhit())
		{
			char input;
			input = _getch();

			switch (input)
			{
			case 75:
				if (unit.x > 0)
					--unit.x;
				break;
			case 77:
				if (unit.x <= 20)
					++unit.x;
				break;


			}
		}


	}
}

void main()
{

	while (true)
	{
		if (blockEvade() == false)
		{
			gotoxy(5, 5);
			cout << "game over" << endl;
			break;
		}
	}
	gotoxy(1, 21);
	system("pause");
}