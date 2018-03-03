#include <iostream>
#include <conio.h>
#include <windows.h>
#include <time.h>
using namespace std;

#define SIZE_H 20
#define SIZE_V 20
#define PLAYER_B 10
#define PLAYER_W 11
int map[SIZE_H][SIZE_V];
FILE* f;


/*
* 맵 그리기
*/
void Print(int x, int y)
{
	for (int i = 0; i < SIZE_H; i++)
	{
		for (int j = 0; j < SIZE_V; j++)
		{
			if (i == x && j == y)
			{
				cout << "＊";
				continue;
			}
			if (map[i][j] == 1) cout << "┌";
			if (map[i][j] == 2) cout << "┬";
			if (map[i][j] == 3) cout << "┐";
			if (map[i][j] == 4) cout << "├";
			if (map[i][j] == 5) cout << "┼";
			if (map[i][j] == 6) cout << "┤";
			if (map[i][j] == 7) cout << "└";
			if (map[i][j] == 8) cout << "┴";
			if (map[i][j] == 9) cout << "┘";
			if (map[i][j] == PLAYER_B) cout << "○";
			if (map[i][j] == PLAYER_W) cout << "●";
		}
		cout << endl;
	}
}

struct Point
{
	int x;
	int y;
};
enum DIRECTION
{
	DIRECTION_LT,
	DIRECTION_T,
	DIRECTION_RT,
	DIRECTION_L,
	DIRECTION_R,
	DIRECTION_LB,
	DIRECTION_B,
	DIRECTION_RB,
	DIRECTION_END
};

Point ptDir[DIRECTION_END] = { { -1, -1 },{ -1, 0 },{ -1, +1 },{ 0, -1 },{ 0, +1 },{ +1, -1 },{ +1, 0 },{ +1, +1 } };
int CheckCount(int type, DIRECTION dir, int x, int y) {
	Point pt = ptDir[dir];
	int i = pt.x;
	int j = pt.y;
	int index = 0;
	int num = 0;
	if (type == PLAYER_B || type == PLAYER_W)
	{
		while (true)
		{
			if (x + i == 0 || y + j == 0 || x + i == SIZE_H - 1 || y + j == SIZE_V - 1) break;
			if (map[x + i][y + j] == type) index++;
			if (map[x + i][y + j] != type) return index;
			i = i + pt.x;
			j = j + pt.y;
		}
		return index;
	}
}

struct Replay {
	int replay_flag;
	int x;
	int y;
	float time;
};
Replay R_print[256];
Replay R_scan[256];

void replay_print(int re_ct)
{
	for (int i = 0; i < re_ct; i++)
	{
		fprintf(f, "%d %d %d %f\n", R_print[i].replay_flag, R_print[i].x, R_print[i].y, R_print[i].time);
	}
}
void replay_update(int flag, int re_ct, int x, int y, int time)
{
	if (flag == 0)
		R_print[re_ct].replay_flag = PLAYER_B;
	else
		R_print[re_ct].replay_flag = PLAYER_W;

	R_print[re_ct].x = x;
	R_print[re_ct].y = y;
	R_print[re_ct].time = time;
}

int main()
{
	int replay_count = 0;
	int i = 0;

	clock_t begin=0, end=0;
	int time = 0;

	char c = 0;
	int flag = 0;
	int x = SIZE_H / 2;
	int y = SIZE_V / 2;

	memset(map, 0, sizeof(SIZE_H*SIZE_V));

	for (int i = 0; i < SIZE_H; i++)
	{
		for (int j = 0; j < SIZE_V; j++)
		{
			//맨 첫줄
			if (i == 0 && j == 0) map[i][j] = 1;
			if (i == 0 && j != 0 && j != SIZE_V - 1) map[i][j] = 2;
			if (i == 0 && j == SIZE_V - 1) map[i][j] = 3;

			//중간줄
			if (i != 0 && i != SIZE_H - 1 && j == 0) map[i][j] = 4;
			if (i != 0 && i != SIZE_H - 1 && j != 0 && j != SIZE_V - 1) map[i][j] = 5;
			if (i != 0 && i != SIZE_H - 1 && j == SIZE_V - 1) map[i][j] = 6;

			//맨 마지막줄
			if (i == SIZE_H - 1 && j == 0) map[i][j] = 7;
			if (i == SIZE_H - 1 && j != 0 && j != SIZE_V - 1) map[i][j] = 8;
			if (i == SIZE_H - 1 && j == SIZE_V - 1) map[i][j] = 9;
		}
	}

	int n = 0;

	cout << "******************************* 메뉴 ********************************" << endl;
	cout << "1.  플레이" << endl;
	cout << "2.  리플레이" << endl;

	cin >> n;

	switch (n)
	{
		case 1:
			f = fopen("replay.txt", "w");

			//키 입력
			while (true)
			{
				if(c=='e')
					begin = clock();
				c = getch();

				switch (c) {
				case 'w':
					if (x == 1)break;
					x = x - 1;
					break;
				case 's':
					if (x == SIZE_H - 2) break;
					x = x + 1;
					break;
				case 'a':
					if (y == 1) break;
					y = y - 1;
					break;
				case 'd':
					if (y == SIZE_V - 2) break;
					y = y + 1;
					break;
				case 'e':
					end = clock();
					time = ((end - begin) / CLOCKS_PER_SEC);
					cout << "수행시간 : " << time << endl;
					if (flag == 0)
					{
						replay_update(flag, replay_count, x, y, time);
						replay_count++;

						map[x][y] = PLAYER_B;
						flag = 1;
					}
					else if (flag == 1)
					{
						replay_update(flag, replay_count, x, y, time);
						replay_count++;

						map[x][y] = PLAYER_W;
						flag = 0;
					}
					break;
				default:
					break;
				}

				system("cls");

				//맵그리기
				Print(x, y);

				if ((CheckCount(map[x][y], DIRECTION_L, x, y) + CheckCount(map[x][y], DIRECTION_R, x, y) == 4) && map[x][y] == PLAYER_B)
				{
					replay_print(replay_count);
					cout << "흑 가로 승리!" << endl;
					return 0;
				}
				if ((CheckCount(map[x][y], DIRECTION_L, x, y) + CheckCount(map[x][y], DIRECTION_R, x, y) == 4) && map[x][y] == PLAYER_W)
				{
					replay_print(replay_count);
					cout << "백 가로 승리!" << endl;
					return 0;
				}
				if ((CheckCount(map[x][y], DIRECTION_T, x, y) + CheckCount(map[x][y], DIRECTION_B, x, y) == 4) && map[x][y] == PLAYER_B)
				{
					replay_print(replay_count);
					cout << "흑 세로 승리!" << endl;
					return 0;
				}
				if ((CheckCount(map[x][y], DIRECTION_T, x, y) + CheckCount(map[x][y], DIRECTION_B, x, y) == 4) && map[x][y] == PLAYER_W)
				{
					replay_print(replay_count);
					cout << "백 세로 승리!" << endl;
					return 0;
				}
				if ((CheckCount(map[x][y], DIRECTION_LT, x, y) + CheckCount(map[x][y], DIRECTION_RB, x, y) == 4) && map[x][y] == PLAYER_B)
				{
					replay_print(replay_count);
					cout << "흑 왼쪽위 대각 승리!" << endl;
					return 0;
				}
				if ((CheckCount(map[x][y], DIRECTION_LT, x, y) + CheckCount(map[x][y], DIRECTION_RB, x, y) == 4) && map[x][y] == PLAYER_W)
				{
					replay_print(replay_count);
					cout << "백 왼쪽위 대각 승리!" << endl;
					return 0;
				}
				if ((CheckCount(map[x][y], DIRECTION_RT, x, y) + CheckCount(map[x][y], DIRECTION_LB, x, y) == 4) && map[x][y] == PLAYER_B)
				{
					replay_print(replay_count);
					cout << "흑 오른쪽위 대각 승리!" << endl;
					return 0;
				}
				if ((CheckCount(map[x][y], DIRECTION_RT, x, y) + CheckCount(map[x][y], DIRECTION_LB, x, y) == 4) && map[x][y] == PLAYER_W)
				{
					replay_print(replay_count);
					cout << "백 오른쪽위 대각 승리!" << endl;
					return 0;
				}

			}
			fclose(f);
			break;
		case 2:
			cout << "리플레이 합니다." << endl;
			f = fopen("replay.txt", "r");
			while ((fscanf(f, "%d %d %d %f\n", &R_scan[i].replay_flag, &R_scan[i].x, &R_scan[i].y, &R_scan[i].time)) != EOF)
			{
				i++;
			}

			for(int j=0; j<=i; j++)
			{
				system("cls");

				//맵그리기
				Print(999, 999);

				map[R_scan[j].x][R_scan[j].y] = R_scan[j].replay_flag;

				if (R_scan[j].time == 0)
					R_scan[j].time = 0.3;

				Sleep(R_scan[j].time*1000);
			}

			fclose(f);
			break;
		default:
			break;

	}
	return 0;
}
/*
┌ = 1
┬ = 2
┐ = 3
├ = 4
┼ = 5
┤ = 6
└ = 7
┴ = 8
┘ = 9
*/

/*
while ((fscanf(f, "%d %d %d\n", &R_scan[i].replay_flag, &R_scan[i].x, &R_scan[i].y)) != EOF)
{
cout << "R_scan[" << i << "] = " << R_scan[i].replay_flag << "," << R_scan[i].x << "," << R_scan[i].y << endl;
i++;
}
*/
