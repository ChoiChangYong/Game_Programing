#pragma once
#include <Windows.h>
#include <vector>
using namespace std;
#define CARD_WIDTH 126
#define CARD_HEIGHT 126
#define BLACK 1
#define WHITE 2

class BitMap;
class Chessman
{
protected:
	BitMap*		m_pBchessman;
	int			m_iX;
	int			m_iY;
	int			m_iIndex;
	int			m_iColor;
	vector<POINT> m_vecMoveable;
	vector<POINT> m_vecResultMoveRange;
public:
	void Init(BitMap* pBchessman, int x, int y, int index, int colorz);
	bool OnClick(int x, int y);
	void Draw(HDC hdc);
	virtual vector<POINT> MoveRangeCheck(int map[][8], vector<POINT> moverange, int x, int y, int Param);
	virtual vector<POINT> getMoveRange(int map[][8], int Param, int x, int y);
	virtual Chessman* Upgrade(Chessman* chessman_select, BitMap* bitmap, int color);
	int getX();
	int getY();
	int getColor();
	void setXY(int x, int y);
	inline int GetIndex()
	{
		return m_iIndex;
	}
	Chessman();
	~Chessman();
};

