#pragma once
#include <Windows.h>

enum RES_TYPE
{
	RES_TYPE_B_PAWN,
	RES_TYPE_B_KNIGHT,
	RES_TYPE_B_BISHOP,
	RES_TYPE_B_ROOK,
	RES_TYPE_B_QUEEN,
	RES_TYPE_B_KING,
	RES_TYPE_W_PAWN,
	RES_TYPE_W_KNIGHT,
	RES_TYPE_W_BISHOP,
	RES_TYPE_W_ROOK,
	RES_TYPE_W_QUEEN,
	RES_TYPE_W_KING,
	RES_TYPE_BLOCK_0,
	RES_TYPE_BLOCK_1,
	RES_TYPE_BLOCK_RANGE,
	RES_TYPE_END
};

class BitMap;
class ResManager
{
private:
	BitMap*			m_pBitMap[RES_TYPE_END];
public:
	void Init(HDC hdc, HINSTANCE hInst);
	BitMap*	GetBitMap(int index);
	void Release();
	ResManager();
	~ResManager();
};

