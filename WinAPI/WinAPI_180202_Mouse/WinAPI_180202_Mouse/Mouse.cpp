#include <windows.h>
#include <vector>
#include "XY.h"
using namespace std;

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
HINSTANCE g_hInst;
LPCTSTR lpszClass = TEXT("Mouse");

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

LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	static int x, y;
	static BOOL bNowDraw = FALSE;
	PAINTSTRUCT ps;
	int count = 0;
	
	static vector<XY*> XYvec;
	XYvec.reserve(1024);
	XY* pXY;

	switch(iMessage)
	{
		case WM_LBUTTONDOWN:
			x = LOWORD(lParam);
			y = HIWORD(lParam);

			bNowDraw = TRUE;
			return 0;
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
		case WM_PAINT:
			hdc = BeginPaint(hWnd, &ps);
			
			for (vector<int>::size_type i = 0; i < XYvec.size(); i++)
			{
				if(count%2==0)
					MoveToEx(hdc, XYvec[i]->getX_Start(), XYvec[i]->getY_Start(), NULL);
				else
					LineTo(hdc, XYvec[i]->getX_End(), XYvec[i]->getY_End());
				count++;
			}
			
			EndPaint(hWnd, &ps);
			return 0;
		case WM_DESTROY:
			PostQuitMessage(0);
			return 0;
	}
	return (DefWindowProc(hWnd, iMessage, wParam, lParam));
}


/*
static vector<int> v_iStartX, v_iStartY;
static vector<int> v_iEndX, v_iEndY;
v_iStartX.reserve(1024);
v_iStartY.reserve(1024);
v_iEndX.reserve(1024);
v_iEndY.reserve(1024);
*/

//v_iStartX.push_back(x);
//v_iStartY.push_back(y);

//v_iEndX.push_back(x);
//v_iEndY.push_back(y);

/*
for (vector<int>::size_type i = 0; i < v_iStartX.size(); i++)
{
MoveToEx(hdc, v_iStartX[i], v_iStartY[i], NULL);
LineTo(hdc, v_iEndX[i], v_iEndY[i]);
}
*/
