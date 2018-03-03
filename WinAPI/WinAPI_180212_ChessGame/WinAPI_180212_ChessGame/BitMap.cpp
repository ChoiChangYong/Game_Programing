#include "BitMap.h"



BitMap::BitMap()
{
}


BitMap::~BitMap()
{
}

void BitMap::Init(HDC hdc, HINSTANCE hInst, char color_id, int num_id)
{
	static TCHAR text1[128];

	if (color_id == 'b')
		wsprintf(text1, TEXT("res\\block_%c_%d.bmp"), color_id, num_id);
	if (color_id == 'w')
		wsprintf(text1, TEXT("res\\block_%c_%d.bmp"), color_id, num_id);
	if (color_id == 'l')
		wsprintf(text1, TEXT("res\\block_%c_%d.bmp"), color_id, num_id);
	if (color_id == 'r')
		wsprintf(text1, TEXT("res\\block_%c_%d.bmp"), color_id, num_id);

	m_hMemDC = CreateCompatibleDC(hdc);
	m_hBitMap = (HBITMAP)LoadImage(NULL, text1, IMAGE_BITMAP, 0, 0
		, LR_CREATEDIBSECTION | LR_DEFAULTSIZE | LR_LOADFROMFILE);
	m_hOldBitMap = (HBITMAP)SelectObject(m_hMemDC, m_hBitMap);

	BITMAP bmp_info;
	GetObject(m_hBitMap, sizeof(bmp_info), &bmp_info);
	m_size.cx = (int)bmp_info.bmWidth;
	m_size.cy = (int)bmp_info.bmHeight;
}

void BitMap::Draw(HDC hdc, int x, int y)
{
	//BitBlt(hdc, x, y, m_size.cx, m_size.cy, m_hMemDC, 0, 0, SRCCOPY);
	TransparentBlt(hdc, x/2, y/2, m_size.cx/2, m_size.cy/2, m_hMemDC, 0, 0, m_size.cx, m_size.cy, RGB(255, 0, 255));
}

void BitMap::Release()
{
	SelectObject(m_hMemDC, m_hOldBitMap);
	DeleteObject(m_hBitMap);
	DeleteDC(m_hMemDC);
}
