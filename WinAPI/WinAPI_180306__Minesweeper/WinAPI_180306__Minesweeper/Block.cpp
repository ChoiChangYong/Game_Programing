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

void Block::setOpen()
{
	m_bOpen = TRUE;
}

bool Block::getOpen()
{
	return m_bOpen;
}

bool Block::getMine()
{
	return m_bMine;
}

bool Block::getFlag()
{
	return m_bFlag;
}

void Block::setFlag(BitMap * pBitmap, bool flag)
{
	m_pBblock = pBitmap;
	m_bFlag = flag;
}

void Block::NoMine(BitMap * pBitmap)
{
	m_pBblock = pBitmap;
}

void Block::GameOver(BitMap* pBitmap)
{
	if (this->getMine())
		m_pBblock = pBitmap;
}

Block::Block()
{
	m_pBblock = nullptr;
	m_iX = 0;
	m_iY = 0;
	m_bMine = FALSE;
	m_bFlag = FALSE;
	m_bOpen = FALSE;
}


Block::~Block()
{
}
