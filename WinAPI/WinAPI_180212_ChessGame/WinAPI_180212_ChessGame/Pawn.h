#pragma once
#include "Chessman.h"
class Pawn :
	public Chessman
{
public:
	virtual vector<POINT> MoveRangeCheck(int map[][8], vector<POINT> moverange, int x, int y, int Param);
	virtual vector<POINT> getMoveRange(int map[][8], int Param, int x, int y);
	virtual Chessman* Upgrade(Chessman* chessman_select, BitMap* bitmap, int color);
	Pawn();
	~Pawn();
};

