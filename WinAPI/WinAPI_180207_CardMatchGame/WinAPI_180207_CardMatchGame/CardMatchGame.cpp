#include <windows.h>
#include "resource.h"
#include <time.h>
#include "CardController.h"

using namespace std;

#define IMG_NUM 21
#define IMG_WIDTH 145
#define IMG_HIGHT 235


LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
HINSTANCE g_hInst;
LPCTSTR lpszClass = TEXT("CardMatchGame");

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdParam, int nCmdShow)
{
	HWND hWnd;
	MSG Message;
	WNDCLASS WndClass;
	g_hInst = hInstance;

	WndClass.cbClsExtra = 0;
	WndClass.cbWndExtra = 0;
	WndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	WndClass.hInstance = hInstance;
	WndClass.lpfnWndProc = WndProc;
	WndClass.lpszClassName = lpszClass;
	WndClass.lpszMenuName = NULL;
	WndClass.style = CS_HREDRAW | CS_VREDRAW;
	RegisterClass(&WndClass);

	hWnd = CreateWindow(lpszClass, lpszClass, WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, (HMENU)NULL, hInstance, NULL);
	ShowWindow(hWnd, nCmdShow);

	while (GetMessage(&Message, NULL, 0, 0))
	{
		TranslateMessage(&Message);
		DispatchMessage(&Message); //WinProc È£Ãâ
	}
	return (int)Message.wParam;
}

CardController *pCards = new CardController();

LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT ps;
	static int x;
	static int y;
	static BOOL bChange = TRUE;

	static TCHAR text1[128];
	static int iTimeCount = 0;

	switch(iMessage)
	{
	case WM_CREATE:
		hdc = GetDC(hWnd);

		pCards->setCard(&hdc, &g_hInst);
		pCards->setLocation();
		pCards->shuffleCards();

		ReleaseDC(hWnd, hdc);
		
		return 0;
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
	
		pCards->printBackground(&hdc);
		pCards->setLocationCards();
		pCards->printCards(&hdc);

		EndPaint(hWnd, &ps);
		return 0;
	case WM_LBUTTONDOWN:
		x = LOWORD(lParam);
		y = HIWORD(lParam);

		pCards->TurnOverCards(&hWnd, &hdc, x, y);
		InvalidateRect(hWnd, NULL, TRUE);
		return 0;
	case WM_TIMER:
		switch (wParam)
		{
		case 1:
			iTimeCount++;
			if (iTimeCount == 2)
			{
				KillTimer(hWnd, 1);
				iTimeCount = 0;
				pCards->OriginalState(&hdc);
			}
			break;
		case 2:
			KillTimer(hWnd, 2);
			iTimeCount = 0;
			pCards->OriginalState(&hdc);
			break;
		}
		InvalidateRect(hWnd, NULL, TRUE);
		return 0;
	case WM_DESTROY:
		KillTimer(hWnd, 1);
		PostQuitMessage(0);
		return 0;
	}
	return (DefWindowProc(hWnd, iMessage, wParam, lParam));
}

/*
case WM_MOUSEMOVE:
if (bNowDraw == TRUE)
{
hdc = GetDC(hWnd);
MoveToEx(hdc, x, y, NULL);

pXY = new XY();
pXY->setXY_Start(x, y);
XYvec.push_back(pXY);

x = LOWORD(lParam);
y = HIWORD(lParam);
LineTo(hdc, x, y);

pXY = new XY();
pXY->setXY_End(x, y);
XYvec.push_back(pXY);

ReleaseDC(hWnd, hdc);
}
InvalidateRect(hWnd, NULL, FALSE);
return 0;
case WM_LBUTTONUP:
x = LOWORD(lParam);
y = HIWORD(lParam);

bNowDraw = FALSE;
return 0;
*/

/*
g_hMemDC[0] = CreateCompatibleDC(hdc);
g_hBitMaps[0] = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP1));
g_hOldBitMap[0] = (HBITMAP)SelectObject(g_hMemDC[0], g_hBitMaps[0]);
*/

/*
BitBlt(hdc, 10, 10, 100, 100, g_hMemDC[iTimeCount], 0, 0, SRCCOPY);
*/

/*
SelectObject(g_hMemDC[i], g_hOldBitMap[i]);
DeleteObject(g_hBitMaps[i]);
DeleteDC(g_hMemDC[i]);
*/

/*
HDC g_hMemDC[11];
HBITMAP g_hBitMaps[11];
HBITMAP g_hOldBitMap[11];
int g_iRandomNum[10];

g_hMemDC[0] = CreateCompatibleDC(hdc);
g_hBitMaps[0] = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP1));
g_hOldBitMap[0] = (HBITMAP)SelectObject(g_hMemDC[0], g_hBitMaps[0]);
g_hMemDC[1] = CreateCompatibleDC(hdc);
g_hBitMaps[1] = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP2));
g_hOldBitMap[1] = (HBITMAP)SelectObject(g_hMemDC[1], g_hBitMaps[1]);
g_hMemDC[2] = CreateCompatibleDC(hdc);
g_hBitMaps[2] = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP3));
g_hOldBitMap[2] = (HBITMAP)SelectObject(g_hMemDC[2], g_hBitMaps[2]);
g_hMemDC[3] = CreateCompatibleDC(hdc);
g_hBitMaps[3] = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP4));
g_hOldBitMap[3] = (HBITMAP)SelectObject(g_hMemDC[3], g_hBitMaps[3]);
g_hMemDC[4] = CreateCompatibleDC(hdc);
g_hBitMaps[4] = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP5));
g_hOldBitMap[4] = (HBITMAP)SelectObject(g_hMemDC[4], g_hBitMaps[4]);
g_hMemDC[5] = CreateCompatibleDC(hdc);
g_hBitMaps[5] = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP6));
g_hOldBitMap[5] = (HBITMAP)SelectObject(g_hMemDC[5], g_hBitMaps[5]);
g_hMemDC[6] = CreateCompatibleDC(hdc);
g_hBitMaps[6] = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP7));
g_hOldBitMap[6] = (HBITMAP)SelectObject(g_hMemDC[6], g_hBitMaps[6]);
g_hMemDC[7] = CreateCompatibleDC(hdc);
g_hBitMaps[7] = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP8));
g_hOldBitMap[7] = (HBITMAP)SelectObject(g_hMemDC[7], g_hBitMaps[7]);
g_hMemDC[8] = CreateCompatibleDC(hdc);
g_hBitMaps[8] = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP9));
g_hOldBitMap[8] = (HBITMAP)SelectObject(g_hMemDC[8], g_hBitMaps[8]);
g_hMemDC[9] = CreateCompatibleDC(hdc);
g_hBitMaps[9] = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP10));
g_hOldBitMap[9] = (HBITMAP)SelectObject(g_hMemDC[9], g_hBitMaps[9]);
g_hMemDC[10] = CreateCompatibleDC(hdc);
g_hBitMaps[10] = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP11));
g_hOldBitMap[10] = (HBITMAP)SelectObject(g_hMemDC[10], g_hBitMaps[10]);

*/