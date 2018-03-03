#pragma once
#include "Word.h"
class Game;
class Item_3_Stop :
	public Word
{
public:
	virtual void onCheck(Game* pGame);

	Item_3_Stop();
	~Item_3_Stop();
};

