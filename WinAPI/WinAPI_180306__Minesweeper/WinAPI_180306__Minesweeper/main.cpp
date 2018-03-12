#include <windows.h>
#include <crtdbg.h>
#include "resource1.h"
#include "GameManager.h"

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
HINSTANCE g_hInst;
LPCTSTR lpszClass = TEXT("Minesweeper");

INT_PTR CALLBACK SettingDlg(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam);
int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdParam, int nCmdShow)
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	_CrtDumpMemoryLeaks();
	//_CrtSetBreakAlloc(228);

	//char* p = new char;//메모리 릭

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
	WndClass.lpszMenuName = MAKEINTRESOURCE(IDR_MENU1);
	WndClass.style = CS_HREDRAW | CS_VREDRAW;
	RegisterClass(&WndClass);

	hWnd = CreateWindow(lpszClass, lpszClass, WS_OVERLAPPEDWINDOW, 
		CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, (HMENU)NULL, hInstance, NULL);
	
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
		nResolutionY / 2 - nWindowHeight / 2 - 50,
		870 + (FrameX << 1) + 7, 512 + (FrameY << 1) + CaptionY + 27, NULL);
	
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

	switch(iMessage)
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
	case WM_TIMER:
		hdc = GetDC(hWnd);
		GameManager::GetInstance()->TimerStart();
		ReleaseDC(hWnd, hdc);
		return 0;
	case WM_LBUTTONUP:
		GameManager::GetInstance()->OnClickL(LOWORD(lParam), HIWORD(lParam));
		return 0;
	case WM_RBUTTONUP:
		GameManager::GetInstance()->OnClickR(LOWORD(lParam), HIWORD(lParam));
		return 0;
	case WM_MBUTTONDOWN:
		GameManager::GetInstance()->OnClickM(LOWORD(lParam), HIWORD(lParam));
		return 0; 
	case WM_DESTROY:
		GameManager::GetInstance()->Release();
		PostQuitMessage(0);
		return 0;
	case WM_COMMAND:
	{
		int id = LOWORD(wParam);
		// Parse the menu selections:
		switch (id)
		{
		case ID_OPTION_SETTING:
			DialogBox(g_hInst, MAKEINTRESOURCE(IDD_DIALOG1), hWnd, SettingDlg);
			break;
		case ID_OPTION_RESET:
			GameManager::GetInstance()->Reset();
			break;
		}

	}
	return 0;
	}
return (DefWindowProc(hWnd, iMessage, wParam, lParam));
}

INT_PTR CALLBACK SettingDlg(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	HWND hRadio;
	switch (message)
	{
	case WM_INITDIALOG:
		hRadio = GetDlgItem(hDlg, IDC_RADIO1);
		SendMessage(hRadio, BM_SETCHECK, BST_CHECKED, 0);
		return (INT_PTR)TRUE;

	case WM_COMMAND:
		if (LOWORD(wParam) == IDOK)
		{
			if (IsDlgButtonChecked(hDlg, IDC_RADIO1) == BST_CHECKED)
				GameManager::GetInstance()->SetGameMode(GAME_MODE_EASY);
			else if (IsDlgButtonChecked(hDlg, IDC_RADIO2) == BST_CHECKED)
				GameManager::GetInstance()->SetGameMode(GAME_MODE_NORMAL);
			else if (IsDlgButtonChecked(hDlg, IDC_RADIO3) == BST_CHECKED)
				GameManager::GetInstance()->SetGameMode(GAME_MODE_HARD);

			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}

		if (LOWORD(wParam) == IDCANCEL)
		{
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}
		break;
	}

	return (INT_PTR)FALSE;
}