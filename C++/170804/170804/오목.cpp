#include <iostream>
#include <conio.h>
using namespace std;

#define SIZE_H 20
#define SIZE_V 20
#define PLAYER_B 10
#define PLAYER_W 11
int map[SIZE_H][SIZE_V];


/*
* ¸Ê ±×¸®±â
*/
void Print(int x, int y)
{
	for (int i = 0; i < SIZE_H; i++)
	{
		for (int j = 0; j < SIZE_V; j++)
		{
			if (i == x && j == y)
			{
				cout << "£ª";
				continue;
			}
			if (map[i][j] == 1) cout << "¦£";
			if (map[i][j] == 2) cout << "¦¨";
			if (map[i][j] == 3) cout << "¦¤";
			if (map[i][j] == 4) cout << "¦§";
			if (map[i][j] == 5) cout << "¦«";
			if (map[i][j] == 6) cout << "¦©";
			if (map[i][j] == 7) cout << "¦¦";
			if (map[i][j] == 8) cout << "¦ª";
			if (map[i][j] == 9) cout << "¦¥";
			if (map[i][j] == PLAYER_B) cout << "¡Ü";
			if (map[i][j] == PLAYER_W) cout << "¡Û";
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

int main()
{
	// ÃÊ±âÈ­

	char c;
	int flag = 0;
	int x = SIZE_H / 2;
	int y = SIZE_V / 2;

	memset(map, 0, sizeof(SIZE_H*SIZE_V));

	for (int i = 0; i < SIZE_H; i++)
	{
		for (int j = 0; j < SIZE_V; j++)
		{
			//¸Ç Ã¹ÁÙ
			if (i == 0 && j == 0) map[i][j] = 1;
			if (i == 0 && j != 0 && j != SIZE_V - 1) map[i][j] = 2;
			if (i == 0 && j == SIZE_V - 1) map[i][j] = 3;

			//Áß°£ÁÙ
			if (i != 0 && i != SIZE_H - 1 && j == 0) map[i][j] = 4;
			if (i != 0 && i != SIZE_H - 1 && j != 0 && j != SIZE_V - 1) map[i][j] = 5;
			if (i != 0 && i != SIZE_H - 1 && j == SIZE_V - 1) map[i][j] = 6;

			//¸Ç ¸¶Áö¸·ÁÙ
			if (i == SIZE_H - 1 && j == 0) map[i][j] = 7;
			if (i == SIZE_H - 1 && j != 0 && j != SIZE_V - 1) map[i][j] = 8;
			if (i == SIZE_H - 1 && j == SIZE_V - 1) map[i][j] = 9;
		}
	}

	//Å° ÀÔ·Â
	while (true)
	{
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
			if (flag == 0)
			{
				map[x][y] = PLAYER_B;
				flag = 1;
			}
			else if (flag == 1)
			{
				map[x][y] = PLAYER_W;
				flag = 0;
			}
			break;
		default:
			break;
		}

		system("cls");

		//¸Ê±×¸®±â
		Print(x, y);

		if ((CheckCount(map[x][y], DIRECTION_L, x, y) + CheckCount(map[x][y], DIRECTION_R, x, y) == 4) && map[x][y] == PLAYER_B)
		{
			cout << "Èæ °¡·Î ½Â¸®!" << endl;
			return 0;
		}
		if ((CheckCount(map[x][y], DIRECTION_L, x, y) + CheckCount(map[x][y], DIRECTION_R, x, y) == 4) && map[x][y] == PLAYER_W)
		{
			cout << "¹é °¡·Î ½Â¸®!" << endl;
			return 0;
		}
		if ((CheckCount(map[x][y], DIRECTION_T, x, y) + CheckCount(map[x][y], DIRECTION_B, x, y) == 4) && map[x][y] == PLAYER_B)
		{
			cout << "Èæ ¼¼·Î ½Â¸®!" << endl;
			return 0;
		}
		if ((CheckCount(map[x][y], DIRECTION_T, x, y) + CheckCount(map[x][y], DIRECTION_B, x, y) == 4) && map[x][y] == PLAYER_W)
		{
			cout << "¹é ¼¼·Î ½Â¸®!" << endl;
			return 0;
		}
		if ((CheckCount(map[x][y], DIRECTION_LT, x, y) + CheckCount(map[x][y], DIRECTION_RB, x, y) == 4) && map[x][y] == PLAYER_B)
		{
			cout << "Èæ ¿ÞÂÊÀ§ ´ë°¢ ½Â¸®!" << endl;
			return 0;
		}
		if ((CheckCount(map[x][y], DIRECTION_LT, x, y) + CheckCount(map[x][y], DIRECTION_RB, x, y) == 4) && map[x][y] == PLAYER_W)
		{
			cout << "¹é ¿ÞÂÊÀ§ ´ë°¢ ½Â¸®!" << endl;
			return 0;
		}
		if ((CheckCount(map[x][y], DIRECTION_RT, x, y) + CheckCount(map[x][y], DIRECTION_LB, x, y) == 4) && map[x][y] == PLAYER_B)
		{
			cout << "Èæ ¿À¸¥ÂÊÀ§ ´ë°¢ ½Â¸®!" << endl;
			return 0;
		}
		if ((CheckCount(map[x][y], DIRECTION_RT, x, y) + CheckCount(map[x][y], DIRECTION_LB, x, y) == 4) && map[x][y] == PLAYER_W)
		{
			cout << "¹é ¿À¸¥ÂÊÀ§ ´ë°¢ ½Â¸®!" << endl;
			return 0;
		}


	}
	return 0;
}
/*
¦£ = 1
¦¨ = 2
¦¤ = 3
¦§ = 4
¦« = 5
¦© = 6
¦¦ = 7
¦ª = 8
¦¥ = 9


¦¡ ¦¢ ¦£ ¦¤ ¦¥ ¦¦ ¦§ ¦¨ ¦© ¦ª ¦«

*/



/*


//
// °¡·Î ½Â¸® ÆÇº°
//
int Check_V(int f, int x, int y)
{
int index_v = 0;

for (int i = 0; i < SIZE_V; i++)
{
if (map[x][i] == PLAYER_B || map[x][i] == PLAYER_W) if (map[x][i] == f) index_v++;
if (index_v == 5)
{
if (map[x][i + 1] != f)
{
return f;
}
}
if (map[x][i] != f) index_v = 0;
}
return 0;
}

//
// ¼¼·Î ½Â¸® ÆÇº°
//

int Check_H(int f, int x, int y)
{
int index_h = 0;

for (int i = 0; i < SIZE_H; i++)
{
if (map[i][y] == PLAYER_B || map[i][y] == PLAYER_W) if (map[i][y] == f) index_h++;
if (index_h == 5)
{
if (map[i + 1][y] != f)
{
return f;
}
}
if (map[i][y] != f) index_h = 0;
}
return 0;
}

//
// ¿ÞÂÊÀ§, ¿À¸¥ÂÊ ¾Æ·¡ ´ë°¢¼± ½Â¸® ÆÇº°
//
int Check_VH1(int f, int x, int y)
{
int index_vh1 = 0;

for (int i = 0; i < SIZE_H; i++)
{
x--;
y--;
if (x == 0 || y == 0) break;
}

for (int i = 0; i < SIZE_H; i++)
{
if (x == SIZE_H - 1 || y == SIZE_V - 1) break;

if (map[x][y] == PLAYER_B || map[x][y] == PLAYER_W) if (map[x][y] == f) index_vh1++;
if (index_vh1 == 5)
{
if (map[x + 1][y + 1] != f)
{
return f;
}
}
if (map[x][y] != f) index_vh1 = 0;
x++;
y++;
}

return 0;
}

//
// ¿À¸¥ÂÊ À§, ¿ÞÂÊ ¾Æ·¡ ´ë°¢¼± ½Â¸® ÆÇº°
//

int Check_VH2(int f, int x, int y)
{
int index_vh2 = 0;

for (int i = 0; i < SIZE_H; i++)
{
x--;
y++;
if (x == 0 || y == SIZE_V - 1) break;
}

for (int i = 0; i < SIZE_H; i++)
{
if (x == SIZE_H - 1 || y == 0) break;

if (map[x][y] == PLAYER_B || map[x][y] == PLAYER_W) if (map[i][y] == f) index_vh2++;
if (index_vh2 == 5)
{
if (map[x + 1][y - 1] != f)
{
return f;
}
}
if (map[x][y] != f) index_vh2 = 0;
x++;
y--;
}

return 0;
}

*/


/*
//½Â¸®¿©ºÎ Ãâ·Â
if (Check_V(map[x][y], x, y) == PLAYER_B)
{
cout << "Èæ °¡·Î ½Â¸®!" << endl;
return 0;
}
if (Check_V(map[x][y], x, y) == PLAYER_W)
{
cout << "¹é °¡·Î ½Â¸®!" << endl;
return 0;
}



if (Check_H(map[x][y], x, y) == PLAYER_B)
{
cout << "Èæ ¼¼·Î ½Â¸®!" << endl;
return 0;
}
if (Check_H(map[x][y], x, y) == PLAYER_W)
{
cout << "¹é ¼¼·Î ½Â¸®!" << endl;
return 0;
}



if (Check_VH1(map[x][y], x, y) == PLAYER_B)
{
cout << "Èæ ¿ÞÂÊ À§, ¿À¸¥ÂÊ ¾Æ·¡ ´ë°¢¼± ½Â¸®!" << endl;
return 0;
}
if (Check_VH1(map[x][y], x, y) == PLAYER_W)
{
cout << "¹é ¿ÞÂÊ À§, ¿À¸¥ÂÊ ¾Æ·¡ ´ë°¢¼± ½Â¸®!" << endl;
return 0;
}



if (Check_VH2(map[x][y], x, y) == PLAYER_B)
{
cout << "Èæ ¿À¸¥ÂÊ À§, ¿ÞÂÊ ¾Æ·¡ ´ë°¢¼± ½Â¸®!" << endl;
return 0;
}
if (Check_VH2(map[x][y], x, y) == PLAYER_W)
{
cout << "¹é ¿À¸¥ÂÊ À§, ¿ÞÂÊ ¾Æ·¡ ´ë°¢¼± ½Â¸®!" << endl;
return 0;
}
*/
