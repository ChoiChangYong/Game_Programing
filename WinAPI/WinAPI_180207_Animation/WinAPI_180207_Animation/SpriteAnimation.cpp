#include <windows.h>
#include "resource.h"

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
HINSTANCE g_hInst;
LPCTSTR lpszClass = TEXT("SpriteAnimation");

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
		DispatchMessage(&Message); //WinProc »£√‚
	}
	return (int)Message.wParam;
}

HDC g_hMemDC[4];
HBITMAP g_hBitMaps[4];
HBITMAP g_hOldBitMap[4];

LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT ps;
	static int iTimeCount = 0;
	//static TCHAR text1[128];

	switch(iMessage)
	{
	case WM_CREATE:
		hdc = GetDC(hWnd);
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

		ReleaseDC(hWnd, hdc);
		SetTimer(hWnd, 1, 100, NULL);
		return 0;
	case WM_TIMER:

		//wsprintf(text1, TEXT("%d"), iTimeCount);
		if (iTimeCount == 3)
			iTimeCount = 0;
		else
			iTimeCount++;

		InvalidateRect(hWnd, NULL, TRUE);
		return 0;
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		//TextOut(hdc, 100, 150, text1, lstrlen(text1)); 
		BitBlt(hdc, 10, 10, 100, 100, g_hMemDC[iTimeCount], 0, 0, SRCCOPY);
		EndPaint(hWnd, &ps);
		return 0;
	case WM_DESTROY:
		for (int i = 0; i < 4; i++)
		{
			SelectObject(g_hMemDC[i], g_hOldBitMap[i]);
			DeleteObject(g_hBitMaps[i]);
			DeleteDC(g_hMemDC[i]);
		}
		KillTimer(hWnd, 1);
		PostQuitMessage(0);
		return 0;
	}
	return (DefWindowProc(hWnd, iMessage, wParam, lParam));
}
