#include <windows.h>
#include "GameManager.h"

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
HINSTANCE g_hInst;
LPCTSTR lpszClass = TEXT("ChessGame");

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdParam, int nCmdShow)
{
	HWND hWnd;
	MSG Message;
	WNDCLASS WndClass;

	int FrameX, FrameY;
	int CaptionY;
	FrameX = GetSystemMetrics(SM_CXFRAME);
	FrameY = GetSystemMetrics(SM_CYFRAME);
	CaptionY = GetSystemMetrics(SM_CYCAPTION);

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

	hWnd = CreateWindow(lpszClass, lpszClass, WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT,
		125 / 2 * 8 + (FrameX << 1) + 125 % 2 * 8 + 7, 125 / 2 * 8 + (FrameY << 1) + CaptionY + 4 + 125 % 2 * 8 + 4,
		NULL, (HMENU)NULL, hInstance, NULL);

	int nResolutionX;
	int nResolutionY;
	nResolutionY = GetSystemMetrics(SM_CYSCREEN);
	nResolutionX = GetSystemMetrics(SM_CXSCREEN);
	RECT stWindowRect;
	GetWindowRect(hWnd, &stWindowRect);
	int nWindowWidth = stWindowRect.right - stWindowRect.left;
	int nWindowHeight = stWindowRect.bottom - stWindowRect.top;
	::SetWindowPos(hWnd, NULL,
		nResolutionX / 2 - nWindowWidth / 2,
		nResolutionY / 2 - nWindowHeight / 2,
		125 / 2 * 8 + (FrameX << 1) + 125 % 2 * 8 + 7, 125 / 2 * 8 + (FrameY << 1) + CaptionY + 4 + 125 % 2 * 8 + 4, NULL);

	ShowWindow(hWnd, nCmdShow);

	while (GetMessage(&Message, NULL, 0, 0))
	{
		TranslateMessage(&Message);
		DispatchMessage(&Message); //WinProc È£Ãâ
	}
	return (int)Message.wParam;
}
HDC			m_hMemDC;
HBITMAP		m_hBitMap;
HBITMAP		m_hOldBitMap;

LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT ps;
	static TCHAR text1[128];

	switch (iMessage)
	{
	case WM_CREATE:
		hdc = GetDC(hWnd);
		GameManager::GetInstance()->Init(hWnd, g_hInst, hdc);
		ReleaseDC(hWnd, hdc);
		return 0;
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		GameManager::GetInstance()->Draw(hdc);
		EndPaint(hWnd, &ps);
		return 0;
	case WM_LBUTTONUP:
		GameManager::GetInstance()->OnClick(LOWORD(lParam), HIWORD(lParam));
		return 0;
	case WM_DESTROY:
		GameManager::GetInstance()->Release();
		PostQuitMessage(0);
		return 0;
	}
	return (DefWindowProc(hWnd, iMessage, wParam, lParam));
}

/*
static TCHAR text1[128];
wsprintf(text1, TEXT("%d"), pCard[i].TurnOverCard(x, y));
MessageBox(*hWnd, text1, text1, MB_OK);
*/

/*
MyBitMap = (HBITMAP)LoadImage(NULL, "a.bmp", IMAGE_BITMAP, 0, 0
, LR_CREATEDIBSECTION | LR_DEFAULTSIZE | LR_LOADFROMFILE);
OldBitMap = (HBITMAP)SelectObject(MemDC, MyBitMap);
TransparentBlt(hdc, 0, 0, 240, 192, MemDC, 0, 0, 240, 192, RGB(255, 0, 255));
*/