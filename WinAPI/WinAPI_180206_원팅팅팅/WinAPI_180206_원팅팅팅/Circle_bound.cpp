#include <windows.h>
#include <math.h>
#include <iostream>
using namespace std;
#define R_X1 50
#define R_Y1 50
#define R_X2 500
#define R_Y2 350
#define PLAYER_SPEED 10
#define E_SCALE 40
#define PLAYER_SCALE 20

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
HINSTANCE g_hInst;
LPCTSTR lpszClass = TEXT("TestOut");

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
		DispatchMessage(&Message); //WinProc 호출
	}
	return (int)Message.wParam;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT ps;
	SYSTEMTIME st;
	static TCHAR sTime[128];

	static int x = 200, y = 200;
	static int i_x = 3, i_y = 3;

	static int iPlayer_x = 130, iPlayer_y = 130;

	static float CollisionCheck = 0;

	//static TCHAR text1[128], text2[128], text3[128], text4[128], text5[128], text6[128], text7[128];

	switch(iMessage)
	{
	case WM_CREATE:
		SetTimer(hWnd, 1, 10, NULL);
		SendMessage(hWnd, WM_TIMER, 1, 0);
		return 0;
	case WM_TIMER:
		GetLocalTime(&st);
		
		x += i_x;
		y += i_y;
		if (x >= R_X2-E_SCALE)
			i_x = -i_x;
		if (y >= R_Y2-E_SCALE)
			i_y = -i_y;
		if (x <= R_X1+E_SCALE)
			i_x = -i_x;
		if (y <= R_Y1+E_SCALE)
			i_y = -i_y;

		CollisionCheck = powf((float)(x - iPlayer_x), (float)2) + powf((float)(y - iPlayer_y), (float)2);

		//wsprintf(text1, TEXT("%d"), (int)CollisionCheck);
		//wsprintf(text2, TEXT("%d"), (int)( powf((float)(E_SCALE + PLAYER_SCALE), (float)2)) );
		
		if ((int)CollisionCheck < (int)( powf((float)(E_SCALE + PLAYER_SCALE), (float)2) ))
		{
			InvalidateRect(hWnd, NULL, TRUE);
			KillTimer(hWnd, 1);
			if (MessageBox(hWnd, TEXT("Game Over!!"), TEXT("패배"), MB_OK) == IDOK)
				exit(0);
		}
		
		InvalidateRect(hWnd, NULL, TRUE);
		return 0;
	case WM_KEYDOWN:
		switch (wParam)
		{
		case VK_LEFT:
			iPlayer_x -= PLAYER_SPEED;
			break;
		case VK_RIGHT:
			iPlayer_x += PLAYER_SPEED;
			break;
		case VK_UP:
			iPlayer_y -= PLAYER_SPEED;
			break;
		case VK_DOWN:
			iPlayer_y += PLAYER_SPEED;
			break;
		}
		InvalidateRect(hWnd, NULL, TRUE);
		return 0;
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		
		Rectangle(hdc, R_X1, R_Y1, R_X2, R_Y2);
		Ellipse(hdc, x-E_SCALE, y-E_SCALE, x+E_SCALE, y+E_SCALE);
		Ellipse(hdc, iPlayer_x -PLAYER_SCALE, iPlayer_y -PLAYER_SCALE, iPlayer_x +PLAYER_SCALE, iPlayer_y +PLAYER_SCALE);
		
		//TextOut(hdc, 100, 100, text1, lstrlen(text1));
		//TextOut(hdc, 100, 120, text2, lstrlen(text2));

		EndPaint(hWnd, &ps);
		return 0;
	case WM_DESTROY:
		KillTimer(hWnd, 1);
		PostQuitMessage(0);
		return 0;
	}
	return (DefWindowProc(hWnd, iMessage, wParam, lParam));
}