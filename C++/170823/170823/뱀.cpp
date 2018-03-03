#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <ctime>
using namespace std;

#define SIZE_H 20
#define SIZE_V 20
#define BLANK 0
#define WALL 1
#define PLAYER 2
#define STAR 3

#define SNAKE_SIZE_MAX 100

int map[SIZE_H][SIZE_V];

struct Point
{
	int y;
	int x;
};
Point star;
Point snake[SNAKE_SIZE_MAX];
enum DIRECTION
{
	DIRECTION_O,
	DIRECTION_T,
	DIRECTION_L,
	DIRECTION_R,
	DIRECTION_B,
	DIRECTION_END
};

Point ptDir[DIRECTION_END] = { { 0, 0 },{ -1, 0 },{ 0, -1 },{ 0, +1 },{ +1, 0 } };
Point pt = ptDir[DIRECTION_O];

/*
 * �� �׸���
 */
void Print(int y, int x)
{
	for (int i = 0; i < SIZE_H; i++)
	{
		for (int j = 0; j < SIZE_V; j++)
		{
			if (i == y && j == x)
			{
				cout << "��";
				continue;
			}
			if (map[i][j] == PLAYER) 
				cout << "��";
			if (map[i][j] == BLANK) 
				cout << "  ";
			if (map[i][j] == WALL) 
				cout << "��";
			if (map[i][j] == STAR) 
				cout << "��";
		}
		cout << endl;
	}
	cout << endl;
}

/*
 * �� �����
 */
void Snake_Blank(int s_n)
{
	for (int i = 0; i < s_n; i++)
	{
		map[snake[i].y][snake[i].x] = BLANK;
	}
}

/*
 * �� �׸���
 */
void Snake_Draw(int s_n)
{
	for (int i = 0; i < s_n; i++)
	{
		map[snake[i].y][snake[i].x] = PLAYER;
	}
}

/*
 * �� �迭 �ֽ�ȭ (���� ��ġ�� [0]�� �ְ� �������� �ڷ� ��ĭ�� �б�)
 */
void Snake_Move(int j)
{
	for (int i = j - 1; i >= 0; i--)
	{
		snake[i + 1].y = snake[i].y;
		snake[i + 1].x = snake[i].x;
	}

}

/*
 * �� ��� �ֽ�ȭ
 */
void Head_Update(int y, int x)
{
	snake[0].y = y;
	snake[0].x = x;
}

/*
 * �� ���� ����
 */
void Star_Create()
{
	int randN = 0;
	randN = (rand() % 11) + 1;
	if (randN == 1)
	{
		star.y = (rand() % (SIZE_H - 4)) + 2;
		star.x = (rand() % (SIZE_V - 4)) + 2;
		map[star.y][star.x] = STAR;
	}
}

/*
 * �� ��尡 ���� �Ծ��� �� �̺�Ʈ
 */
int Snake_Star(int y, int x, int s_n)
{
	if (map[y][x] == STAR)
	{
		map[y][x] = BLANK;
		if (s_n == 0)
			s_n = 2;
		else
			s_n++;
	}
	return s_n;
}

/*
 * ���ӿ��� (�� ��尡 �� ��򰡿� ��ġ�� ������ ��)
 */
int Snake_Star(int s_n)
{
	int flag = 0;

	for (int i = 1; i <= s_n; i++)
	{
		if (snake[0].x == snake[i].x && snake[0].y == snake[i].y)
			flag = 1;
	}
	return flag;
}

int main()
{
	srand((unsigned int)time(NULL));
	char c = 0;
	int y = SIZE_H / 2;
	int x = SIZE_V / 2;
	int snake_size = 0;
	int star_num = 0;
	int total = 1;
	memset(map, 0, sizeof(SIZE_H*SIZE_V));

	for (int i = 0; i < SIZE_H; i++)
	{
		for (int j = 0; j < SIZE_V; j++)
		{
			if ((j == 0) || (j == SIZE_V - 1) || (i == 0) || (i == SIZE_H - 1))
			{
				map[i][j] = WALL;
			}
		}
	}
	while (true)
	{
		if (kbhit())
		{
			c = getch();
			switch (c) {
			case 'w':
				pt = ptDir[DIRECTION_T];
				break;
			case 's':
				pt = ptDir[DIRECTION_B];
				break;
			case 'a':
				pt = ptDir[DIRECTION_L];
				break;
			case 'd':
				pt = ptDir[DIRECTION_R];
				break;
			default:
				break;
			}
		}
		if (y == 1 || y == SIZE_H - 2 || x == 1 || x == SIZE_V - 2)
			return 0;

		/*
		 * �� �����
		 */
		Snake_Blank(star_num);

		/*
		 * �� �迭 �ֽ�ȭ (���� ��ġ�� [0]�� �ְ� �������� �ڷ� ��ĭ�� �б�)
		 */
		Snake_Move(snake_size);

		/*
		 * ������ġ �̵�
		 */
		y = y + pt.y;
		x = x + pt.x;

		/*
		 * �� ��� �ֽ�ȭ
		 */
		Head_Update(y, x);

		/*
		 * �� �ִ� ũ�� ����
		 */
		if(snake_size != SNAKE_SIZE_MAX-1)
			snake_size++;

		/*
		 * �� ��尡 ���� �Ծ��� �� �̺�Ʈ
		 */
		star_num = Snake_Star(y, x, star_num);

		/*
		 * �� ���� ����
		 */
		Star_Create();

		system("cls");

		/*
		 * �� �׸���
		 */
		Snake_Draw(star_num);

		/*
		 * �� �׸���
		 */
		Print(y, x);

		/*
		 * ���ӿ��� (�� ��尡 �� ��򰡿� ��ġ�� ������ ��)
		 */
		if (Snake_Star(star_num) == 1)
			return 0;

		Sleep(100);
	}

	return 0;
}