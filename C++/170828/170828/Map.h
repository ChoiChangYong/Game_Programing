#pragma once
#define SIZE_H 20
#define SIZE_V 20

class Map
{
private:
	int map[SIZE_H][SIZE_V];

public:
	void Player_del(int, int);
	void Player_draw(int, int);
	
	void Print_Map_First();
	void Print();

	Map();
	~Map();
};


