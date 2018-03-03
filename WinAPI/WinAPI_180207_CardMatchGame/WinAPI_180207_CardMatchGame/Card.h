#pragma once
#include <windows.h>

class Card
{
private:
	HDC m_hMemDC;
	HBITMAP m_hBitMaps;
	HBITMAP m_hOldBitMap;
	POINT m_CardLocation;
	int m_iCardKind;
	BOOL bSuccessTurnOver;

public:
	void setCard(HDC *hdc, HINSTANCE *g_hInst, int iImageNum, int iKind);
	void setLocationCard(POINT CardLocation);
	void printCard(HDC *hdc);
	BOOL TurnOverCard(int x, int y);
	int getCardKind();
	void setSuccess();
	BOOL getSuccess();
	void releaseCard();
	Card();
	~Card();
};

