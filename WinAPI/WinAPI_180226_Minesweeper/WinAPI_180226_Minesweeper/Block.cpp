#include "Block.h"
#include "BitMap.h"
#include "GameManager.h"


void Block::Init(BitMap* pBblock, int x, int y, bool mine, bool flag, bool open)
{
	m_pBblock = pBblock;
	m_iX = x;
	m_iY = y;
	m_bMine = mine;
	m_bFlag = flag;
	m_bOpen = open;
}

bool Block::OnClick(int x, int y)
{
	POINT pt = { x , y };
	RECT rc = { m_iX, m_iY, m_iX + CARD_WIDTH, m_iY + CARD_HEIGHT };

	if (PtInRect(&rc, pt))
	{
		return true;
	}

	return false;
}

void Block::Draw(HDC hdc)
{
	m_pBblock->Draw(hdc, m_iX, m_iY);
}

int Block::getX()
{
	return m_iX;
}

int Block::getY()
{
	return m_iY;
}

void Block::setXY(int x, int y)
{
	m_iX = x;
	m_iY = y;
}

int Block::GetMine()
{
	return m_bMine;
}

void Block::setOpen()
{
	m_bOpen = TRUE;
}

void Block::setFlag(bool flag)
{
	m_bFlag = flag;
}

void Block::NoMine(BitMap * pBitmap)
{
	m_pBblock = pBitmap;
}

void Block::GameOver(BitMap* pBitmap)
{
	if (this->GetMine())
		m_pBblock = pBitmap;
}

Block::Block()
{
}


Block::~Block()
{
}
