#pragma once
#include <Windows.h>
#include <vector>
using namespace std;

class BitMap;
class Block
{
protected:
	BitMap*		m_pBblock;
	int			m_iX;
	int			m_iY;
	bool		m_bMine;
	bool		m_bFlag;
	bool		m_bOpen;

public:
	void Init(BitMap* pBblock, int x, int y, bool mine, bool flag, bool open);
	bool OnClick(int x, int y);
	void Draw(HDC hdc);

	int getX();
	int getY();
	void setXY(int x, int y);


	void setOpen();
	bool getOpen();

	bool getMine();
	bool getFlag();
	void setFlag(BitMap * pBitmap, bool flag);

	void NoMine(BitMap* pBitmap);

	void GameOver(BitMap* pBitmap);
	Block();
	~Block();
};

