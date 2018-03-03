#include "ResManager.h"
#include "BitMap.h"
#include "Macro.h"

ResManager::ResManager()
{
}


ResManager::~ResManager()
{
}

void ResManager::Init(HDC hdc, HINSTANCE hInst)
{
	int count = 0;
	for (int i = 0; i <= RES_TYPE_B_KING; i++)
	{
		BitMap* pNew = new BitMap();
		pNew->Init(hdc, hInst, 'b', count);
		m_pBitMap[i] = pNew;
		count++;
	}
	count = 0;
	for (int i = RES_TYPE_W_PAWN; i <= RES_TYPE_W_KING; i++)
	{
		BitMap* pNew = new BitMap();
		pNew->Init(hdc, hInst, 'w', count);
		m_pBitMap[i] = pNew;
		count++;
	}
	count = 0;
	for (int i = RES_TYPE_BLOCK_0; i <= RES_TYPE_BLOCK_1; i++)
	{
		BitMap* pNew = new BitMap();
		pNew->Init(hdc, hInst, 'l', count);
		m_pBitMap[i] = pNew;
		count++;
	}
	count = 0;
	for (int i = RES_TYPE_BLOCK_RANGE; i < RES_TYPE_END; i++)
	{
		BitMap* pNew = new BitMap();
		pNew->Init(hdc, hInst, 'r', count);
		m_pBitMap[i] = pNew;
		count++;
	}
	count = 0;
}

BitMap*	ResManager::GetBitMap(int index)
{
	return m_pBitMap[index];
}

void ResManager::Release()
{
	for (int i = 0; i < RES_TYPE_END; i++)
	{
		SAFE_DELETE(m_pBitMap[i]);
	}
}
