#include "CardController.h"
#include "resource.h"
#include <time.h>
#include "Card.h"
using namespace std;

#define IMG_NUM 20
#define IMG_WIDTH 130
#define IMG_HIGHT 235



void CardController::setCard(HDC *hdc, HINSTANCE *g_hInst)
{
	pCard = new Card[IMG_NUM];
	pCard_black = new Card[IMG_NUM];
	pTempCard_1 = new Card();
	pTempCard_2 = new Card();

	for (int i = 0; i < IMG_NUM; i++)
	{
		pCard_black[i].setCard(hdc, g_hInst, IDB_BITMAP11, 0);
	}

	pCard[0].setCard(hdc, g_hInst, IDB_BITMAP1, 1);
	pCard[1].setCard(hdc, g_hInst, IDB_BITMAP2, 2);
	pCard[2].setCard(hdc, g_hInst, IDB_BITMAP3, 3);
	pCard[3].setCard(hdc, g_hInst, IDB_BITMAP4, 4);
	pCard[4].setCard(hdc, g_hInst, IDB_BITMAP5, 5);
	pCard[5].setCard(hdc, g_hInst, IDB_BITMAP6, 6);
	pCard[6].setCard(hdc, g_hInst, IDB_BITMAP7, 7);
	pCard[7].setCard(hdc, g_hInst, IDB_BITMAP8, 8);
	pCard[8].setCard(hdc, g_hInst, IDB_BITMAP9, 9);
	pCard[9].setCard(hdc, g_hInst, IDB_BITMAP10, 10);

	pCard[10].setCard(hdc, g_hInst, IDB_BITMAP1, 1);
	pCard[11].setCard(hdc, g_hInst, IDB_BITMAP2, 2);
	pCard[12].setCard(hdc, g_hInst, IDB_BITMAP3, 3);
	pCard[13].setCard(hdc, g_hInst, IDB_BITMAP4, 4);
	pCard[14].setCard(hdc, g_hInst, IDB_BITMAP5, 5);
	pCard[15].setCard(hdc, g_hInst, IDB_BITMAP6, 6);
	pCard[16].setCard(hdc, g_hInst, IDB_BITMAP7, 7);
	pCard[17].setCard(hdc, g_hInst, IDB_BITMAP8, 8);
	pCard[18].setCard(hdc, g_hInst, IDB_BITMAP9, 9);
	pCard[19].setCard(hdc, g_hInst, IDB_BITMAP10, 10);
}

void CardController::setLocationCards()
{
	for (int i = 0; i < IMG_NUM; i++)
	{
		pCard[i].setLocationCard(iCardLocation[i]);
		pCard_black[i].setLocationCard(iCardLocation[i]);
	}
}

void CardController::printCards(HDC *hdc)
{
	for (int i = 0; i < IMG_NUM; i++)
	{
		pCard[i].printCard(hdc);
	}
	for (int i = 0; i < IMG_NUM; i++)
	{
		pCard_black[i].printCard(hdc);
	}
}


void CardController::TurnOverCards(HWND *hWnd, HDC *hdc, int x, int y)
{
	if (bTurnOverFlag)
	{
		for (int i = 0; i < IMG_NUM; i++)
		{
			if (pCard_black[i].TurnOverCard(x, y) && !(pCard_black[i].getSuccess()) )
			{
				if (nTurnOverCount == 0)
				{
					iTempCard_1_Num = i;
					iCardKind_1 = pCard[i].getCardKind();

					*pTempCard_1 = pCard_black[i];
					pCard_black[i] = pCard[i];
					pCard[i] = *pTempCard_1;

					nTurnOverCount++;
				}
				else if (nTurnOverCount == 1)
				{
					iTempCard_2_Num = i;
					iCardKind_2 = pCard[i].getCardKind();

					*pTempCard_2 = pCard_black[i];
					pCard_black[i] = pCard[i];
					pCard[i] = *pTempCard_2;

					nTurnOverCount++;

					if (iCardKind_1 == iCardKind_2)
					{
						bTurnOverSuccessFlag = TRUE;
						pCard_black[iTempCard_1_Num].setSuccess();
						pCard_black[iTempCard_2_Num].setSuccess();
					}
				}


				if (nTurnOverCount == 2)
				{
					if (!bTurnOverSuccessFlag)
					{
						SetTimer(*hWnd, 2, 1000, NULL);
						SendMessage(*hWnd, WM_TIMER, 1, 0);
					}
					else
					{ 
						SetTimer(*hWnd, 2, 10, NULL);
					}
					bTurnOverFlag = FALSE;
				}
			}
		}
	}
}

void CardController::OriginalState(HDC* hdc)
{
	bTurnOverFlag = TRUE;
	nTurnOverCount = 0;
	if (!bTurnOverSuccessFlag)
	{
		*pTempCard_1 = pCard_black[iTempCard_1_Num];
		pCard_black[iTempCard_1_Num] = pCard[iTempCard_1_Num];
		pCard[iTempCard_1_Num] = *pTempCard_1;

		*pTempCard_2 = pCard_black[iTempCard_2_Num];
		pCard_black[iTempCard_2_Num] = pCard[iTempCard_2_Num];
		pCard[iTempCard_2_Num] = *pTempCard_2;
	}
	else
		bTurnOverSuccessFlag = FALSE;
}

void CardController::printBackground(HDC * hdc)
{
	Rectangle(*hdc, 0, 0, IMG_WIDTH * 10 + 45, IMG_HIGHT * 2 + 10);
}

void CardController::shuffleCards()
{
	int nDust, nSour;
	POINT nTemp;

	srand(unsigned int(time(NULL)));

	for (int i = 0; i < IMG_NUM*3; i++)
	{
		nDust = rand() % (IMG_NUM);
		nSour = rand() % (IMG_NUM);

		nTemp = iCardLocation[nDust];
		iCardLocation[nDust] = iCardLocation[nSour];
		iCardLocation[nSour] = nTemp;
	}
}

void CardController::setLocation()
{
	iCardLocation[0].x = 0;
	iCardLocation[0].y = 0;
	iCardLocation[1].x = IMG_WIDTH * 1 + 1;
	iCardLocation[1].y = 0;
	iCardLocation[2].x = IMG_WIDTH * 2 + 2;
	iCardLocation[2].y = 0;
	iCardLocation[3].x = IMG_WIDTH * 3 + 3;
	iCardLocation[3].y = 0;
	iCardLocation[4].x = IMG_WIDTH * 4 + 4;
	iCardLocation[4].y = 0;
	iCardLocation[5].x = IMG_WIDTH * 5 + 5;
	iCardLocation[5].y = 0;
	iCardLocation[6].x = IMG_WIDTH * 6 + 6;
	iCardLocation[6].y = 0;
	iCardLocation[7].x = IMG_WIDTH * 7 + 7;
	iCardLocation[7].y = 0;
	iCardLocation[8].x = IMG_WIDTH * 8 + 8;
	iCardLocation[8].y = 0;
	iCardLocation[9].x = IMG_WIDTH * 9 + 9;
	iCardLocation[9].y = 0;

	iCardLocation[10].x = 0;
	iCardLocation[10].y = IMG_HIGHT + 10;
	iCardLocation[11].x = IMG_WIDTH * 1 + 1;
	iCardLocation[11].y = IMG_HIGHT + 10;
	iCardLocation[12].x = IMG_WIDTH * 2 + 2;
	iCardLocation[12].y = IMG_HIGHT + 10;
	iCardLocation[13].x = IMG_WIDTH * 3 + 3;
	iCardLocation[13].y = IMG_HIGHT + 10;
	iCardLocation[14].x = IMG_WIDTH * 4 + 4;
	iCardLocation[14].y = IMG_HIGHT + 10;
	iCardLocation[15].x = IMG_WIDTH * 5 + 5;
	iCardLocation[15].y = IMG_HIGHT + 10;
	iCardLocation[16].x = IMG_WIDTH * 6 + 6;
	iCardLocation[16].y = IMG_HIGHT + 10;
	iCardLocation[17].x = IMG_WIDTH * 7 + 7;
	iCardLocation[17].y = IMG_HIGHT + 10;
	iCardLocation[18].x = IMG_WIDTH * 8 + 8;
	iCardLocation[18].y = IMG_HIGHT + 10;
	iCardLocation[19].x = IMG_WIDTH * 9 + 9;
	iCardLocation[19].y = IMG_HIGHT + 10;
}

void CardController::releaseCard()
{
	for (int i = 0; i < IMG_NUM; i++)
	{
		pCard[i].releaseCard();
	}
}

CardController::CardController()
{
	nTurnOverCount = 0;
	bTurnOverFlag = TRUE;
	iTempCard_1_Num = 0;
	iTempCard_2_Num = 0;
	iCardKind_1 = 1;
	iCardKind_2 = 2;
	bTurnOverSuccessFlag = FALSE;
}


CardController::~CardController()
{
}


/*	m_hMemDC[0] = CreateCompatibleDC(*hdc);
	m_hBitMaps[0] = (HBITMAP)LoadBitmap(*g_hInst, MAKEINTRESOURCE(IDB_BITMAP1));
	m_hOldBitMap[0] = (HBITMAP)SelectObject(m_hMemDC[0], m_hBitMaps[0]);
	m_hMemDC[1] = CreateCompatibleDC(*hdc);
	m_hBitMaps[1] = (HBITMAP)LoadBitmap(*g_hInst, MAKEINTRESOURCE(IDB_BITMAP2));
	m_hOldBitMap[1] = (HBITMAP)SelectObject(m_hMemDC[1], m_hBitMaps[1]);
	m_hMemDC[2] = CreateCompatibleDC(*hdc);
	m_hBitMaps[2] = (HBITMAP)LoadBitmap(*g_hInst, MAKEINTRESOURCE(IDB_BITMAP3));
	m_hOldBitMap[2] = (HBITMAP)SelectObject(m_hMemDC[2], m_hBitMaps[2]);
	m_hMemDC[3] = CreateCompatibleDC(*hdc);
	m_hBitMaps[3] = (HBITMAP)LoadBitmap(*g_hInst, MAKEINTRESOURCE(IDB_BITMAP4));
	m_hOldBitMap[3] = (HBITMAP)SelectObject(m_hMemDC[3], m_hBitMaps[3]);
	m_hMemDC[4] = CreateCompatibleDC(*hdc);
	m_hBitMaps[4] = (HBITMAP)LoadBitmap(*g_hInst, MAKEINTRESOURCE(IDB_BITMAP5));
	m_hOldBitMap[4] = (HBITMAP)SelectObject(m_hMemDC[4], m_hBitMaps[4]);
	m_hMemDC[5] = CreateCompatibleDC(*hdc);
	m_hBitMaps[5] = (HBITMAP)LoadBitmap(*g_hInst, MAKEINTRESOURCE(IDB_BITMAP6));
	m_hOldBitMap[5] = (HBITMAP)SelectObject(m_hMemDC[5], m_hBitMaps[5]);
	m_hMemDC[6] = CreateCompatibleDC(*hdc);
	m_hBitMaps[6] = (HBITMAP)LoadBitmap(*g_hInst, MAKEINTRESOURCE(IDB_BITMAP7));
	m_hOldBitMap[6] = (HBITMAP)SelectObject(m_hMemDC[6], m_hBitMaps[6]);
	m_hMemDC[7] = CreateCompatibleDC(*hdc);
	m_hBitMaps[7] = (HBITMAP)LoadBitmap(*g_hInst, MAKEINTRESOURCE(IDB_BITMAP8));
	m_hOldBitMap[7] = (HBITMAP)SelectObject(m_hMemDC[7], m_hBitMaps[7]);
	m_hMemDC[8] = CreateCompatibleDC(*hdc);
	m_hBitMaps[8] = (HBITMAP)LoadBitmap(*g_hInst, MAKEINTRESOURCE(IDB_BITMAP9));
	m_hOldBitMap[8] = (HBITMAP)SelectObject(m_hMemDC[8], m_hBitMaps[8]);
	m_hMemDC[9] = CreateCompatibleDC(*hdc);
	m_hBitMaps[9] = (HBITMAP)LoadBitmap(*g_hInst, MAKEINTRESOURCE(IDB_BITMAP10));
	m_hOldBitMap[9] = (HBITMAP)SelectObject(m_hMemDC[9], m_hBitMaps[9]);
	m_hMemDC[10] = CreateCompatibleDC(*hdc);
	m_hBitMaps[10] = (HBITMAP)LoadBitmap(*g_hInst, MAKEINTRESOURCE(IDB_BITMAP1));
	m_hOldBitMap[10] = (HBITMAP)SelectObject(m_hMemDC[10], m_hBitMaps[10]);
	m_hMemDC[11] = CreateCompatibleDC(*hdc);
	m_hBitMaps[11] = (HBITMAP)LoadBitmap(*g_hInst, MAKEINTRESOURCE(IDB_BITMAP2));
	m_hOldBitMap[11] = (HBITMAP)SelectObject(m_hMemDC[11], m_hBitMaps[11]);
	m_hMemDC[12] = CreateCompatibleDC(*hdc);
	m_hBitMaps[12] = (HBITMAP)LoadBitmap(*g_hInst, MAKEINTRESOURCE(IDB_BITMAP3));
	m_hOldBitMap[12] = (HBITMAP)SelectObject(m_hMemDC[12], m_hBitMaps[12]);
	m_hMemDC[13] = CreateCompatibleDC(*hdc);
	m_hBitMaps[13] = (HBITMAP)LoadBitmap(*g_hInst, MAKEINTRESOURCE(IDB_BITMAP4));
	m_hOldBitMap[13] = (HBITMAP)SelectObject(m_hMemDC[13], m_hBitMaps[13]);
	m_hMemDC[14] = CreateCompatibleDC(*hdc);
	m_hBitMaps[14] = (HBITMAP)LoadBitmap(*g_hInst, MAKEINTRESOURCE(IDB_BITMAP5));
	m_hOldBitMap[14] = (HBITMAP)SelectObject(m_hMemDC[14], m_hBitMaps[14]);
	m_hMemDC[15] = CreateCompatibleDC(*hdc);
	m_hBitMaps[15] = (HBITMAP)LoadBitmap(*g_hInst, MAKEINTRESOURCE(IDB_BITMAP6));
	m_hOldBitMap[15] = (HBITMAP)SelectObject(m_hMemDC[15], m_hBitMaps[15]);
	m_hMemDC[16] = CreateCompatibleDC(*hdc);
	m_hBitMaps[16] = (HBITMAP)LoadBitmap(*g_hInst, MAKEINTRESOURCE(IDB_BITMAP7));
	m_hOldBitMap[16] = (HBITMAP)SelectObject(m_hMemDC[16], m_hBitMaps[16]);
	m_hMemDC[17] = CreateCompatibleDC(*hdc);
	m_hBitMaps[17] = (HBITMAP)LoadBitmap(*g_hInst, MAKEINTRESOURCE(IDB_BITMAP8));
	m_hOldBitMap[17] = (HBITMAP)SelectObject(m_hMemDC[17], m_hBitMaps[17]);
	m_hMemDC[18] = CreateCompatibleDC(*hdc);
	m_hBitMaps[18] = (HBITMAP)LoadBitmap(*g_hInst, MAKEINTRESOURCE(IDB_BITMAP9));
	m_hOldBitMap[18] = (HBITMAP)SelectObject(m_hMemDC[18], m_hBitMaps[18]);
	m_hMemDC[19] = CreateCompatibleDC(*hdc);
	m_hBitMaps[19] = (HBITMAP)LoadBitmap(*g_hInst, MAKEINTRESOURCE(IDB_BITMAP10));
	m_hOldBitMap[19] = (HBITMAP)SelectObject(m_hMemDC[19], m_hBitMaps[19]);
	m_hMemDC[20] = CreateCompatibleDC(*hdc);
	m_hBitMaps[20] = (HBITMAP)LoadBitmap(*g_hInst, MAKEINTRESOURCE(IDB_BITMAP11));
	m_hOldBitMap[20] = (HBITMAP)SelectObject(m_hMemDC[20], m_hBitMaps[20]);
*/

/*	BitBlt(*hdc, 0, 0, IMG_WIDTH, IMG_HIGHT, m_hMemDC[0], 0, 0, SRCCOPY);
	BitBlt(*hdc, IMG_WIDTH + 1, 0, IMG_WIDTH, IMG_HIGHT, m_hMemDC[1], 0, 0, SRCCOPY);
	BitBlt(*hdc, IMG_WIDTH * 2 + 2, 0, IMG_WIDTH, IMG_HIGHT, m_hMemDC[2], 0, 0, SRCCOPY);
	BitBlt(*hdc, IMG_WIDTH * 3 + 3, 0, IMG_WIDTH, IMG_HIGHT, m_hMemDC[3], 0, 0, SRCCOPY);
	BitBlt(*hdc, IMG_WIDTH * 4 + 4, 0, IMG_WIDTH, IMG_HIGHT, m_hMemDC[4], 0, 0, SRCCOPY);
	BitBlt(*hdc, IMG_WIDTH * 5 + 5, 0, IMG_WIDTH, IMG_HIGHT, m_hMemDC[5], 0, 0, SRCCOPY);
	BitBlt(*hdc, IMG_WIDTH * 6 + 6, 0, IMG_WIDTH, IMG_HIGHT, m_hMemDC[6], 0, 0, SRCCOPY);
	BitBlt(*hdc, IMG_WIDTH * 7 + 7, 0, IMG_WIDTH, IMG_HIGHT, m_hMemDC[7], 0, 0, SRCCOPY);
	BitBlt(*hdc, IMG_WIDTH * 8 + 8, 0, IMG_WIDTH, IMG_HIGHT, m_hMemDC[8], 0, 0, SRCCOPY);
	BitBlt(*hdc, IMG_WIDTH * 9 + 9, 0, IMG_WIDTH, IMG_HIGHT, m_hMemDC[9], 0, 0, SRCCOPY);

	BitBlt(*hdc, 0, IMG_HIGHT + 10, IMG_WIDTH, IMG_HIGHT, m_hMemDC[10], 0, 0, SRCCOPY);
	BitBlt(*hdc, IMG_WIDTH + 1, IMG_HIGHT + 10, IMG_WIDTH, IMG_HIGHT, m_hMemDC[11], 0, 0, SRCCOPY);
	BitBlt(*hdc, IMG_WIDTH * 2 + 2, IMG_HIGHT + 10, IMG_WIDTH, IMG_HIGHT, m_hMemDC[12], 0, 0, SRCCOPY);
	BitBlt(*hdc, IMG_WIDTH * 3 + 3, IMG_HIGHT + 10, IMG_WIDTH, IMG_HIGHT, m_hMemDC[13], 0, 0, SRCCOPY);
	BitBlt(*hdc, IMG_WIDTH * 4 + 4, IMG_HIGHT + 10, IMG_WIDTH, IMG_HIGHT, m_hMemDC[14], 0, 0, SRCCOPY);
	BitBlt(*hdc, IMG_WIDTH * 5 + 5, IMG_HIGHT + 10, IMG_WIDTH, IMG_HIGHT, m_hMemDC[15], 0, 0, SRCCOPY);
	BitBlt(*hdc, IMG_WIDTH * 6 + 6, IMG_HIGHT + 10, IMG_WIDTH, IMG_HIGHT, m_hMemDC[16], 0, 0, SRCCOPY);
	BitBlt(*hdc, IMG_WIDTH * 7 + 7, IMG_HIGHT + 10, IMG_WIDTH, IMG_HIGHT, m_hMemDC[17], 0, 0, SRCCOPY);
	BitBlt(*hdc, IMG_WIDTH * 8 + 8, IMG_HIGHT + 10, IMG_WIDTH, IMG_HIGHT, m_hMemDC[18], 0, 0, SRCCOPY);
	BitBlt(*hdc, IMG_WIDTH * 9 + 9, IMG_HIGHT + 10, IMG_WIDTH, IMG_HIGHT, m_hMemDC[19], 0, 0, SRCCOPY);
*/

/*
static TCHAR text1[128];
wsprintf(text1, TEXT("%d"), pCard[i].TurnOverCard(x, y));
MessageBox(*hWnd, text1, text1, MB_OK);
*/