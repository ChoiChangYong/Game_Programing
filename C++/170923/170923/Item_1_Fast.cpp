#include "Item_1_Fast.h"
#include "Game.h"
#include <iostream>
#include <ctime>
using namespace std;

void Item_1_Fast::onCheck(Game* pGame)
{
	pGame->Use_Item_1_Fast();
}


Item_1_Fast::Item_1_Fast()
{
}


Item_1_Fast::~Item_1_Fast()
{
}
