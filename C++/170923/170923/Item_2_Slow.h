#pragma once
#include "Word.h"
class Game; 
class Item_2_Slow :
	public Word
{
public:
	virtual void onCheck(Game* pGame);

	Item_2_Slow();
	~Item_2_Slow();
};

