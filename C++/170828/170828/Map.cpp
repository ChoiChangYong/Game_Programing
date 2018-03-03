#include "Map.h"
#include "Player.h"
#include <iostream>
using namespace std;
#define SIZE_H 20
#define SIZE_V 20

Map::Map()
{
	for (int i = 0; i < SIZE_H; i++) {
		for (int j = 0; j < SIZE_V; j++) {
			map[i][j] = 0;
		}
	}
}

void Map::Player_del(int y, int x)
{
	map[y][x] = 0;
}

void Map::Player_draw(int y, int x)
{
	map[y][x] = 2;
}

void Map::Print_Map_First()
{
	for (int i = 0; i < SIZE_H; i++) {
		for (int j = 0; j < SIZE_V; j++) {
			if (i == 0) 
				map[i][j] = 1;
			if (i == SIZE_H - 1) 
				map[i][j] = 1;
			if (j == 0) 
				map[i][j] = 1;
			if (j == SIZE_V - 1) 
				map[i][j] = 1;

			if (i == SIZE_H / 2 && j == SIZE_V / 2) 
				map[i][j] = 2;
		}
	}
}

void Map::Print()
{
	for (int i = 0; i < SIZE_H; i++) {
		for (int j = 0; j < SIZE_V; j++) {
			if (map[i][j] == 0) 
				cout << " ";
			if (map[i][j] == 1) 
				cout << "*";
			if (map[i][j] == 2) 
				cout << "*";
		}
		cout << endl;
	}
}

Map::~Map()
{
}
