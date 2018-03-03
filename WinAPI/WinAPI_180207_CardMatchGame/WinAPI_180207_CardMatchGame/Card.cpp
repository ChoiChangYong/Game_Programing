#include <windows.h>
#include "Card.h"
#include "resource.h"
#define IMG_WIDTH 130
#define IMG_HIGHT 235



void Card::setCard(HDC *hdc, HINSTANCE *g_hInst, int iImageNum, int iKind)
{
	m_hMemDC = CreateCompatibleDC(*hdc);
	m_hBitMaps = (HBITMAP)LoadBitmap(*g_hInst, MAKEINTRESOURCE(iImageNum));
	m_hOldBitMap = (HBITMAP)SelectObject(m_hMemDC, m_hBitMaps);
	m_iCardKind = iKind;
	bSuccessTurnOver = FALSE;
}

void Card::setLocationCard(POINT CardLocation)
{
	m_CardLocation = CardLocation;
}

void Card::printCard(HDC * hdc)
{
	BitBlt(*hdc, m_CardLocation.x, m_CardLocation.y, IMG_WIDTH, IMG_HIGHT, m_hMemDC, 0, 0, SRCCOPY);
}

BOOL Card::TurnOverCard(int x, int y)
{
	RECT rCard = { m_CardLocation.x, m_CardLocation.y, m_CardLocation.x+IMG_WIDTH, m_CardLocation.y+IMG_HIGHT };
	POINT pMouse = { x, y };
	BOOL bResult = FALSE;

	if (PtInRect(&rCard, pMouse))
		bResult = TRUE;
	else
		bResult = FALSE;

	return bResult;
}

int Card::getCardKind()
{
	return m_iCardKind;
}

void Card::setSuccess()
{
	bSuccessTurnOver = TRUE;
}

BOOL Card::getSuccess()
{
	return bSuccessTurnOver;
}

void Card::releaseCard()
{
	SelectObject(m_hMemDC, m_hOldBitMap);
	DeleteObject(m_hBitMaps);
	DeleteDC(m_hMemDC);
}

Card::Card()
{
	bSuccessTurnOver = FALSE;
}


Card::~Card()
{
}
