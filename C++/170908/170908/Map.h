#pragma once
#define SIZE_H 15
#define SIZE_V 10
class Map
{
private:
	int map[SIZE_H][SIZE_V];

public:
	void gotoxy(int x, int y);
	void mPrint(vector<Virus*> vVirus);
	Map();
	~Map();
};

