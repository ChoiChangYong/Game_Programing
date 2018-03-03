#pragma once
#include "Word.h"
class Game;
class Item_6_AllDelete :
	public Word
{
public:
	void onCheck(Game * pGame);
	Item_6_AllDelete();
	~Item_6_AllDelete();
};

