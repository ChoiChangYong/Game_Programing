#pragma once
#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Virus;
class Round;
class Score;
class Life;
class Item;
class Total_Score;

class Game
{
private:
	int m_nTimer;
	int m_nTimer_Item;

	vector<Virus*> m_vVirus;
	int m_nVirus_total;
	int m_nVirus_count;

	int m_chInputData_index;
	char m_chInputData[30];
	string m_strCopyData;

	int m_nRound_num;
	Round* pRound;

	Total_Score* pTotalScore;
	Score* pScore;

	Life* pLife;

	int m_nItem_number;

	Item* pItem;

	int Item_flag_3;

	int Item_flag_1_2;
	int Item_speed_1_2;

	int Item_flag_5;

	bool m_bGameClear;
public:
	void Load();
	void StartGame(int nround);

	void Input_print();

	void LastLine_print();

	void TopPrint();

	void RoundUp();

	void InputData();

	Game();
	~Game();
};