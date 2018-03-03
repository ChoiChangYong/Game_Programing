#pragma once
#include "Scene.h"

#include <string>
#include <vector>
#include <time.h>
#include <ctime>
using namespace std;

class Word;
class Game :
	public Scene
{
private:
	int m_nRound;
	int m_nScore;
	vector<Word*> m_vWord;
	int m_nWord_total;
	int m_nWord_count;

	int m_nTimer;

	int m_chInputData_index;
	char m_chInputData[30];
	string m_strCopyData;

	int m_nLife;

	int m_szRound[5][2];

	time_t timer;
	struct tm *t;

	Word* p_szItem[7];

	int nRandom;
	int m_nGame_Time_Check;
	int m_nItem_Time_Check;

	int m_nItem_1_Fast;
	int m_nItem_2_Slow;
	bool m_nItem_3_Stop;
	bool m_nItem_5_Blind;
public:
	virtual void init();
	virtual int Input();
	virtual void Draw();
	virtual void Update();
	virtual void Release();

	void Print_user_input();
	void Print_ItemUsed();
	void Print_LastLine();
	void Print_Top();
	void Print_Round();
	void Print_Score();
	void Print_Life();
	void Print_Life_Minus();

	bool GameOver();
	bool GameClear();

	void Save();

	void ScoreUp();

	void Item_Time_Check(int m_nGame_Time_Check);

	void Use_Item_1_Fast();

	void Use_Item_2_Slow();

	void Use_Item_3_Stop();

	void Use_Item_4_Heal();

	void Use_Item_5_Blind();

	void Use_Item_6_AllDelete();

	void ItemUse(string Item_name, string Item_effect);

	void ItemDelete();

	void Input_Word();

	void RoundUp();

	Game();
	~Game();
};

