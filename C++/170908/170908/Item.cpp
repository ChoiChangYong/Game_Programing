#include "Item.h"
#include "Life.h"
#include "Virus.h"
#include <Windows.h>
#include <iostream>
#include <time.h>

using namespace std;
void gotoxy_Item(int y, int x)
{
	COORD Pos = { y - 1, x - 1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

void Item::ItemUsed_Print()
{
	gotoxy_Item(3, 27);
	cout << "아이템 발동!!";
	gotoxy_Item(3, 28);
	cout << m_nItem_number << ". " << m_szItem[m_nItem_number - 1];

	gotoxy_Item(1, 26);
	cout << "┌";
	gotoxy_Item(3, 26);
	cout << "───────────";
	gotoxy_Item(1, 29);
	cout << "└";
	gotoxy_Item(1, 27);
	cout << "│";
	gotoxy_Item(1, 28);
	cout << "│";
	gotoxy_Item(23, 26);
	cout << "┐";
	gotoxy_Item(3, 29);
	cout << "───────────";
	gotoxy_Item(23, 29);
	cout << "┘";
	gotoxy_Item(23, 27);
	cout << "│";
	gotoxy_Item(23, 28);
	cout << "│";
}
void Item::ItemUsedDelete()
{
	gotoxy_Item(3, 27);
	cout << "             ";
	gotoxy_Item(3, 28);
	cout << "                    ";
}

int Item::ItemUsed(int Item_number)
{
	m_nItem_number = Item_number;
	if (Item_number == 1)
	{
		temp_item_1_2_speed = (-30);
		timer = time(NULL);
		t = localtime(&timer);

		ntime = t->tm_sec;
		temp_flag_item_1_2 = 1;

		temp_flag = temp_item_1_2_speed;
	}
	if (Item_number == 2)
	{
		temp_item_1_2_speed = 30;
		timer = time(NULL);
		t = localtime(&timer);

		ntime = t->tm_sec;
		temp_flag_item_1_2 = 1;

		temp_flag = temp_item_1_2_speed;
	}
	if (Item_number == 3)
	{
		timer = time(NULL);
		t = localtime(&timer);

		ntime = t->tm_sec;
		temp_flag_item_3 = 1;

		temp_flag = temp_flag_item_3;
	}
	if (Item_number == 5)
	{
		timer = time(NULL);
		t = localtime(&timer);

		ntime = t->tm_sec;

		temp_flag_item_5 = 1;

		temp_flag = temp_flag_item_5;
	}
	ItemUsedDelete();
	ItemUsed_Print();
	return temp_flag;
}
void Item::ItemUsed(int Item_number, Life* pLife)
{
	m_nItem_number = Item_number;
	if (Item_number == 4)
	{
		pLife->Plus();
	}
	ItemUsed_Print();
}
void Item::ItemUsed(int Item_number, vector<Virus*> Virus, int Virus_total)
{
	m_nItem_number = Item_number;
	if (Item_number == 6)
	{
		for (int i = 0; i < Virus_total; i++)
		{
			Virus[i]->Delete_all();
		}
		//system("cls");
		//TopPrint();
		//Input_print();
		ItemUsed_Print();
		Sleep(1000);
		ItemUsedDelete();
	}
}
int Item::ItemCheck_1_2(int time_)
{
	if (temp_flag_item_1_2 == 1) 
	{
		if (ntime + 8 >= 60)
		{
			ntime = ntime - 60;
		}
		if (time_ == (ntime + 8)) {
			temp_item_1_2_speed = 0;
			temp_flag_item_1_2 = 0;
			ItemUsedDelete();
		}
	}
	return temp_item_1_2_speed;
}
int Item::ItemCheck_3(int time_)
{
	if (temp_flag_item_3 == 1)
	{
		if (ntime + 5 >= 60)
		{
			ntime = ntime - 60;
		}
		if (time_ == (ntime + 5))
		{
			temp_flag_item_3 = 0;
			ItemUsedDelete();
		}
	}
	return temp_flag_item_3;
}

int Item::ItemCheck_5(int time_)
{
	if (temp_flag_item_5 == 1)
	{
		if (ntime + 5 >= 60)
		{
			ntime = ntime - 60;
		}
		if (time_ == (ntime + 5)) {
			temp_flag_item_5 = 0;
			ItemUsedDelete();
		}
	}
	return temp_flag_item_5;
}


Item::Item()
{

	m_nItem_number = rand() % 4 + 1;

	temp_flag_item_1_2 = 0;
	temp_flag_item_3 = false;
	temp_flag_item_5 = 0;

	temp_item_1_2_speed = 0;

	m_szItem[0] = "빨리 떨어지기";
	m_szItem[1] = "느리게 떨어지기";
	m_szItem[2] = "멈추기";
	m_szItem[3] = "체력 회복";
	m_szItem[4] = "*로 글자 가리기";
	m_szItem[5] = "전체 지우기";

	temp_flag = 0;
}


Item::~Item()
{
}
