#include "Item_3_Stop.h"
#include "Game.h"
#include <iostream>
#include <ctime>
using namespace std;


void Item_3_Stop::onCheck(Game* pGame)
{
	pGame->Use_Item_3_Stop();
}

Item_3_Stop::Item_3_Stop()
{
}


Item_3_Stop::~Item_3_Stop()
{
}
