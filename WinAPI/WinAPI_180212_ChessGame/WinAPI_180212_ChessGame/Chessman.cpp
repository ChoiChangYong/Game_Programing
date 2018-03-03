#include "Chessman.h"
#include "BitMap.h"


void Chessman::Init(BitMap* pBchessman, int x, int y, int index, int color)
{
	m_pBchessman = pBchessman;
	m_iX = x;
	m_iY = y;
	m_iIndex = index;
	m_iColor = color;
}

bool Chessman::OnClick(int x, int y)
{
	POINT pt = { x , y };
	RECT rc = { m_iX / 2 , m_iY / 2 , m_iX / 2 + CARD_WIDTH / 2 , m_iY / 2 + CARD_HEIGHT / 2 };

	if (PtInRect(&rc, pt))
	{
		return true;
	}

	return false;
}

void Chessman::Draw(HDC hdc)
{
	m_pBchessman->Draw(hdc, m_iX, m_iY);
}

vector<POINT> Chessman::MoveRangeCheck(int map[][8], vector<POINT> moverange, int x, int y, int Param)
{
	return moverange;
}

vector<POINT> Chessman::getMoveRange(int map[][8], int Param, int x, int y)
{
	POINT point;
	point.x = m_iX;
	point.y = m_iY;
	m_vecMoveable.push_back(point);
	return m_vecMoveable;
}

Chessman* Chessman::Upgrade(Chessman* chessman_select, BitMap* bitmap, int color)
{
	return nullptr;
}

int Chessman::getX()
{
	return m_iX;
}

int Chessman::getY()
{
	return m_iY;
}

int Chessman::getColor()
{
	return m_iColor;
}

void Chessman::setXY(int x, int y)
{
	m_iX = x;
	m_iY = y;
}

Chessman::Chessman()
{
}


Chessman::~Chessman()
{
}
