#pragma once
#include "Chessman.h"
class Bishop :
	public Chessman
{
public:
	virtual vector<POINT> MoveRangeCheck(int map[][8], vector<POINT> moverange, int x, int y, int Param);
	virtual vector<POINT> getMoveRange(int map[][8], int Param, int x, int y);
	Bishop();
	~Bishop();
};

