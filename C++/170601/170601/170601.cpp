#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <conio.h>
using namespace std;

#define SIZE_H 20
#define SIZE_V 20
#define EMPTY 0
#define MAP 1
#define PLAYER 2

int main() {
	int map[SIZE_H][SIZE_V];
	char c;
	int x = SIZE_H / 2;
	int y = SIZE_V / 2;

	//초기화
	for (int i = 0; i < SIZE_H; i++) {
		for (int j = 0; j < SIZE_V; j++) {
			map[i][j] = 0;
		}
	}

	//맵 그리기
	for (int i = 0; i < SIZE_H; i++) {
		for (int j = 0; j < SIZE_V; j++) {
			if (i == 0) map[i][j] = 1;
			if (i == SIZE_H - 1) map[i][j] = 1;
			if (j == 0) map[i][j] = 1;
			if (j == SIZE_V - 1) map[i][j] = 1;

			if (i == SIZE_H / 2 && j == SIZE_V / 2) map[i][j] = 2;
		}
	}


	while (1) {
		c = getch();
		map[x][y] = 0;

		switch (c) {
		case 'w':
			if (x == 1) break;
			x = x - 1;
			break;
		case 's':
			if (x == SIZE_H-2) break;
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
		default:
			break;

		}
		map[x][y] = 2;
		system("cls");
		for (int i = 0; i < SIZE_H; i++) {
			for (int j = 0; j < SIZE_V; j++) {
				if (map[i][j] == 0) cout << " ";
				if (map[i][j] == 1) cout << "*";
				if (map[i][j] == 2) cout << "*";
			}
			cout << endl;
		}
	}
	
	
	return 0;
}
