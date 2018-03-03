#pragma once
#include "Word.h"
class Game;
class Item_4_Heal :
	public Word
{
public:
	virtual void onCheck(Game* pGame);
	Item_4_Heal();
	~Item_4_Heal();
};

