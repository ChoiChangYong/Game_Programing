#pragma once
#include <Windows.h>

enum RES_TYPE
{
	RES_TYPE_BACKGROUND,
	RES_TYPE_MINE,
	RES_TYPE_FLAG,
	RES_TYPE_BLOCK,
	RES_TYPE_BLOCK_0,
	RES_TYPE_BLOCK_1,
	RES_TYPE_BLOCK_2,
	RES_TYPE_BLOCK_3,
	RES_TYPE_BLOCK_4,
	RES_TYPE_BLOCK_5,
	RES_TYPE_BLOCK_6,
	RES_TYPE_BLOCK_7,
	RES_TYPE_BLOCK_8,
	RES_TYPE_END
};

class BitMap;
class ResManager
{
private:
	BitMap*		m_pBitMap[RES_TYPE_END];
public:
	void Init(HDC hdc, HINSTANCE hInst);
	BitMap*	GetBitMap(int index);
	void Release();
	ResManager();
	~ResManager();
};

