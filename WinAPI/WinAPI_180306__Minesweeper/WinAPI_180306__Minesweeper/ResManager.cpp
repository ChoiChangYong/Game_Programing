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
	for (int i = 0; i < RES_TYPE_END; i++)
	{
		BitMap* pNew = new BitMap();
		pNew->Init(hdc, hInst, i);
		m_pBitMap[i] = pNew;
	}
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
