#include "Item_6_AllDelete.h"
#include "Game.h"
#include <iostream>
using namespace std;


void Item_6_AllDelete::onCheck(Game* pGame)
{
	pGame->Use_Item_6_AllDelete();
}

Item_6_AllDelete::Item_6_AllDelete()
{
}


Item_6_AllDelete::~Item_6_AllDelete()
{
}
