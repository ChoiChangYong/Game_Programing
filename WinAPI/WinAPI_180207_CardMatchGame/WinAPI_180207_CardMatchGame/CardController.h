#pragma once
#include <windows.h>
#define IMG_NUM 21
class Card;
class CardController
{
private:
	Card* pCard; 
	Card* pCard_black;

	Card* pTempCard_1;
	int iTempCard_1_Num;
	int iCardKind_1;

	Card* pTempCard_2;
	int iTempCard_2_Num;
	int iCardKind_2;

	POINT iCardLocation[IMG_NUM];

	int nTurnOverCount;
	BOOL bTurnOverFlag;
	BOOL bTurnOverSuccessFlag;
public:
	void setCard(HDC *hdc, HINSTANCE *g_hInst);
	void setLocation();
	void shuffleCards();
	void setLocationCards();
	void printCards(HDC *hdc);
	void TurnOverCards(HWND *hWnd, HDC *hdc, int x, int y);
	void OriginalState(HDC* hdc);
	void printBackground(HDC *hdc);
	void releaseCard();
	CardController();
	~CardController();
};

