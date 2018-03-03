#include "Item_5_Blind.h"
#include "Game.h"
#include <iostream>
using namespace std;


void Item_5_Blind::onCheck(Game* pGame)
{
	pGame->Use_Item_5_Blind();
}

Item_5_Blind::Item_5_Blind()
{
}


Item_5_Blind::~Item_5_Blind()
{
}
