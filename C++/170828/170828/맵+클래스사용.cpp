#include <iostream>
#include <conio.h>

#include "Map.h"
#include "Player.h"
using namespace std;

#define SIZE_H 20
#define SIZE_V 20
#define EMPTY 0
#define MAP 1
#define PLAYER 2
Map M;
Player P((SIZE_H / 2), (SIZE_V / 2));

int main() {
	char c;
	
	M.Print_Map_First();

	while (1) {
		c = getch();

		M.Player_del(P.GetY(), P.GetX());

		switch (c) {
		case 'w':
			if (P.GetY() == 1)
				break;

			P.SetUp();
			break;
		case 's':
			if (P.GetY() == SIZE_H - 2) 
				break;

			P.SetDown();
			break;
		case 'a':
			if (P.GetX() == 1) 
				break;

			P.SetLeft();
			break;
		case 'd':
			if (P.GetX() == SIZE_V - 2) 
				break;

			P.SetRight();
			break;
		default:
			break;
		}

		M.Player_draw(P.GetY(), P.GetX());

		system("cls");

		M.Print();
	}
	return 0;
}
