#pragma once
#include "Word.h"
class Game;
class Item_1_Fast :
	public Word
{
public:
	virtual void onCheck(Game* pGame);

	Item_1_Fast();
	~Item_1_Fast();
};

