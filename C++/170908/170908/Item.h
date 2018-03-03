#pragma once
#include "Game.h"
class Life;
class Virus;
class Item :
	public Game
{
private:
	time_t timer;
	struct tm *t;

	int m_nItem_number;
	char* m_szItem[6];

	int temp_item_1_2_speed;

	int ntime;

	int temp_flag_item_1_2;
	int temp_flag_item_3;
	int temp_flag_item_5;




	int temp_flag;
public:
	void ItemUsed_Print();
	int ItemUsed(int Item_number);
	void ItemUsed(int Item_number, Life* pLife);
	void ItemUsed(int Item_number, vector<Virus*> Virus, int Virus_total);

	int ItemCheck_1_2(int time_);
	int ItemCheck_3(int time_);
	int ItemCheck_5(int time_);

	void ItemUsedDelete();

	Item();
	~Item();
};

