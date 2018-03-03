#include "Item_2_Slow.h"
#include "Game.h"
#include <iostream>
#include <ctime>
using namespace std;


void Item_2_Slow::onCheck(Game* pGame)
{
	pGame->Use_Item_2_Slow();
}

Item_2_Slow::Item_2_Slow()
{
}

Item_2_Slow::~Item_2_Slow()
{
}
