#pragma once
#include "Word.h"
class Game;
class Item_5_Blind :
	public Word
{
public:
	void onCheck(Game * pGame);
	Item_5_Blind();
	~Item_5_Blind();
};

