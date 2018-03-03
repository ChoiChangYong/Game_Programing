#pragma once
#include <Windows.h>

#define CARD_WIDTH 125
#define CARD_HEIGHT 125

class BitMap
{
private:
	HDC			m_hMemDC;
	HBITMAP		m_hBitMap;
	HBITMAP		m_hOldBitMap;

	SIZE		m_size;
public:
	void Init(HDC hdc, HINSTANCE hInst, char color_id, int num_id);
	void Draw(HDC hdc, int x, int y);
	void Release();

	BitMap();
	~BitMap();
};

