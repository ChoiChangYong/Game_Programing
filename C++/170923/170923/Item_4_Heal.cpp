#include "Item_4_Heal.h"
#include "Game.h"
#include <iostream>
using namespace std;

void Item_4_Heal::onCheck(Game* pGame)
{
	pGame->Use_Item_4_Heal();
}

Item_4_Heal::Item_4_Heal()
{
}


Item_4_Heal::~Item_4_Heal()
{
}
