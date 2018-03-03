#pragma once
#include <string>
using namespace std;
class Game;
class Word
{
private:
	int m_x;
	int m_y;
	string m_strWord;
	int m_nColor;
	bool m_bWord;
public:
	void gotoxy(int y, int x);
	void Init();

	void Delete();
	void Delete_all();

	void Move();

	bool Delete_LastLine();

	void Print();

	void Print_Star_Item_5();

	bool Compare(string strWord);

	void setDie();

	int getColor();

	virtual void onCheck(Game* pGame);

	Word(char* word);
	Word();
	~Word();
};

