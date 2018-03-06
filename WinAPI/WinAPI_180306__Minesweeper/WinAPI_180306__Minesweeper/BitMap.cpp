#include "BitMap.h"
#include "ResManager.h"


BitMap::BitMap()
{
}

BitMap::~BitMap()
{
}

void BitMap::Init(HDC hdc, HINSTANCE hInst, int id)
{
	static TCHAR image_name[128];

	if (id == RES_TYPE_BACKGROUND)
		wsprintf(image_name, TEXT("res\\back.bmp"));
	if (id == RES_TYPE_MINE)
		wsprintf(image_name, TEXT("res\\mine.bmp"));
	if (id == RES_TYPE_FLAG)
		wsprintf(image_name, TEXT("res\\flag.bmp"));
	if (id == RES_TYPE_BLOCK)
		wsprintf(image_name, TEXT("res\\block.bmp"));
	if (id == RES_TYPE_BLOCK_0)
		wsprintf(image_name, TEXT("res\\block_0.bmp"));
	if (id == RES_TYPE_BLOCK_1)
		wsprintf(image_name, TEXT("res\\block_1.bmp"));
	if (id == RES_TYPE_BLOCK_2)
		wsprintf(image_name, TEXT("res\\block_2.bmp"));
	if (id == RES_TYPE_BLOCK_3)
		wsprintf(image_name, TEXT("res\\block_3.bmp"));
	if (id == RES_TYPE_BLOCK_4)
		wsprintf(image_name, TEXT("res\\block_4.bmp"));
	if (id == RES_TYPE_BLOCK_5)
		wsprintf(image_name, TEXT("res\\block_5.bmp"));
	if (id == RES_TYPE_BLOCK_6)
		wsprintf(image_name, TEXT("res\\block_6.bmp"));
	if (id == RES_TYPE_BLOCK_7)
		wsprintf(image_name, TEXT("res\\block_7.bmp"));
	if (id == RES_TYPE_BLOCK_8)
		wsprintf(image_name, TEXT("res\\block_8.bmp"));

	m_hMemDC = CreateCompatibleDC(hdc);

	m_hBitMap = (HBITMAP)LoadImage(NULL, image_name, IMAGE_BITMAP, 0, 0
		, LR_CREATEDIBSECTION | LR_DEFAULTSIZE | LR_LOADFROMFILE);
	m_hOldBitMap = (HBITMAP)SelectObject(m_hMemDC, m_hBitMap);

	BITMAP bmp_info;
	GetObject(m_hBitMap, sizeof(bmp_info), &bmp_info);
	m_size.cx = (int)bmp_info.bmWidth;
	m_size.cy = (int)bmp_info.bmHeight;
}

void BitMap::Draw(HDC hdc, int x, int y)
{
	TransparentBlt(hdc, x, y, m_size.cx, m_size.cy, m_hMemDC, 0, 0, m_size.cx, m_size.cy, RGB(255, 0, 255));
}

void BitMap::Release()
{
	SelectObject(m_hMemDC, m_hOldBitMap);
	DeleteObject(m_hBitMap);
	DeleteDC(m_hMemDC);
}
