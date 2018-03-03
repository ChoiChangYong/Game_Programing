#include "GameManager.h"
#include "ResManager.h"
#include "Macro.h"
#include "Block.h"
#include <time.h>
#include <algorithm>


GameManager* GameManager::m_pThis = NULL;

GameManager::GameManager()
{
	m_eGameMode = GAME_MODE_EASY;
	m_iWidth = (m_eGameMode + 1) * 8;
	m_iHeight = (m_eGameMode + 1) * 8;
	memset(m_iMine, BLOCK, m_iWidth * sizeof(int));
	for(int i = 0; i < m_iHeight; i++)
		memset(m_iMap[i], BLOCK, m_iWidth * sizeof(int));
}
GameManager::~GameManager()
{
}


void GameManager::setBackGround(Block* pNew_Block)
{
	pNew_Block->Init(m_pResManager->GetBitMap(RES_TYPE_BACKGROUND), 0, 0, FALSE, FALSE, FALSE);
	m_pBackGround = pNew_Block;
}

void GameManager::setBlock(Block* pNew_Block)
{
	int mine_count = 0;

	for (int i = 0; i < m_iHeight; i++)
	{
		for (int j = 0; j < m_iWidth; j++)
		{
			pNew_Block = new Block();

			if (m_iMine[mine_count] % m_iWidth == j && m_iMine[mine_count] / m_iWidth == i)
			{
				pNew_Block->Init(m_pResManager->GetBitMap(RES_TYPE_MINE),
					j % m_iWidth * CARD_WIDTH + 41, i % m_iHeight * CARD_HEIGHT + 43, TRUE, FALSE, FALSE);
				mine_count++;
				m_iMap[i][j] = MINE;
			}
			else
			{
				pNew_Block->Init(m_pResManager->GetBitMap(RES_TYPE_BLOCK),
					j % m_iWidth * CARD_WIDTH + 41, i % m_iHeight * CARD_HEIGHT + 43, FALSE, FALSE, FALSE);
			}
			m_vecBlock.push_back(pNew_Block);
		}
	}
}

void GameManager::setMine()
{
	bool bFound;

	srand((unsigned int)time(NULL));

	for (int i = 0; i < m_iWidth; i++)
	{
		while (1)
		{
			m_iMine[i] = rand() % (m_iWidth*m_iHeight);
			bFound = FALSE;
			for (int j = 0; j < i; ++j)
			{
				if (m_iMine[j] == m_iMine[i])
				{
					bFound = TRUE;
					break;
				}
			}
			if (!bFound)
				break;
		}
	}

	sort(m_iMine, m_iMine + m_iWidth);
}

void GameManager::Init(HWND hWnd, HINSTANCE hInst, HDC hdc)
{
	m_hWnd = hWnd;
	m_pResManager = new ResManager();
	m_pResManager->Init(hdc, hInst);

	Block* pNew_Block = new Block();

	/*
	배경 생성
	*/
	setBackGround(pNew_Block);
	/*
	지뢰 생성
	*/
	setMine();
	/*
	블록 생성
	*/
	setBlock(pNew_Block);
}

void GameManager::SetGameMode(GAME_MODE mode)
{
	m_eGameMode = mode;
	m_iWidth = (m_eGameMode + 1) * 8;
	if (m_eGameMode == GAME_MODE_HARD)
		m_eGameMode = GAME_MODE_NORMAL;
	m_iHeight = (m_eGameMode + 1) * 8;

	memset(m_iMine, BLOCK, m_iWidth * sizeof(int));
	memset(m_iMap, BLOCK, m_iWidth * m_iHeight * sizeof(int));
	m_vecBlock.clear();

	/*
	지뢰 생성
	*/
	setMine();
	/*
	블록 생성
	*/
	Block* pNew_Block = new Block();
	setBlock(pNew_Block);

	InvalidateRect(m_hWnd, NULL, true);
}

/*
상하좌우대각선 지뢰 체크
*/
void GameManager::Check(int x, int y)
{
	Block* pBlock = new Block();
	for (auto iter = m_vecBlock.begin(); iter != m_vecBlock.end(); iter++)
	{
		if (((*iter)->getX() - 41) / CARD_WIDTH == x && ((*iter)->getY() - 43) / CARD_HEIGHT == y)
			pBlock = (*iter);
	}
	int mine_count = 0;

	

	for (int i = 0; i < m_iHeight; i++)
	{
		for (int j = 0; j < m_iWidth; j++)
		{
			if (j == x - 1 && i == y - 1)
			{
				if (m_iMap[i][j] == MINE) // 해당 Block이 지뢰일 때
					mine_count++;
			}
			if (j == x - 1 && i == y)
			{
				if (m_iMap[i][j] == MINE) // 해당 Block이 지뢰일 때
					mine_count++;
			}
			if (j == x - 1 && i == y + 1)
			{
				if (m_iMap[i][j] == MINE) // 해당 Block이 지뢰일 때
					mine_count++;
			}
			if (j == x && i == y + 1)
			{
				if (m_iMap[i][j] == MINE) // 해당 Block이 지뢰일 때
					mine_count++;
			}
			if (j == x + 1 && i == y + 1)
			{
				if (m_iMap[i][j] == MINE) // 해당 Block이 지뢰일 때
					mine_count++;
			}
			if (j == x + 1 && i == y)
			{
				if (m_iMap[i][j] == MINE) // 해당 Block이 지뢰일 때
					mine_count++;
			}
			if (j == x + 1 && i == y - 1)
			{
				if (m_iMap[i][j] == MINE) // 해당 Block이 지뢰일 때
					mine_count++;
			}
			if (j == x && i == y - 1)
			{
				if (m_iMap[i][j] == MINE) // 해당 Block이 지뢰일 때
					mine_count++;
			}
		}
	}

	/*
		주변에 지뢰가 하나도 없을 경우, 해당 위치 출력 후 다시 주변 검사
	*/
	if (mine_count == 0)
	{
		setBlock(pBlock, mine_count);
		
		for (int i = 0; i < m_iHeight; i++)
		{
			for (int j = 0; j < m_iWidth; j++)
			{
				/*
				if (j == x - 1 && i == y - 1)
				{
					Check(j, i);
					continue;
				}
				
				if (j == x - 1 && i == y)
				{
					Check(j, i);
					continue;
				}
				
				if (j == x - 1 && i == y + 1)
				{
					Check(j, i);
					continue;
				}
				
				if (j == x && i == y + 1)
				{
					Check(j, i);
					continue;
				}
				if (j == x + 1 && i == y + 1)
				{
					Check(j, i);
					continue;
				}
				*/
				if (j == x + 1 && i == y)
				{
					Check(j, i);
					continue;
				}
				if (j == x + 1 && i == y - 1)
				{
					Check(j, i);
					continue;
				}
				if (j == x && i == y - 1)
				{
					Check(j, i);
					continue;
				}
			}
		}

	}
	/*
		주변에 지뢰가 하나라도 있을 경우, 해당 위치 출력 후 끝
	*/
	else
		setBlock(pBlock, mine_count);
}

/*
지뢰 개수 확인 후 Block 이미지 출력
*/
void GameManager::setBlock(Block * pBlock, int mine_count)
{
	if (mine_count == 0)
		pBlock->NoMine(m_pResManager->GetBitMap(RES_TYPE_BLOCK_0));
	else if (mine_count == 1)
		pBlock->NoMine(m_pResManager->GetBitMap(RES_TYPE_BLOCK_1));
	else if (mine_count == 2)
		pBlock->NoMine(m_pResManager->GetBitMap(RES_TYPE_BLOCK_2));
	else if (mine_count == 3)
		pBlock->NoMine(m_pResManager->GetBitMap(RES_TYPE_BLOCK_3));
	else if (mine_count == 4)
		pBlock->NoMine(m_pResManager->GetBitMap(RES_TYPE_BLOCK_4));
	else if (mine_count == 5)
		pBlock->NoMine(m_pResManager->GetBitMap(RES_TYPE_BLOCK_5));
	else if (mine_count == 6)
		pBlock->NoMine(m_pResManager->GetBitMap(RES_TYPE_BLOCK_6));
	else if (mine_count == 7)
		pBlock->NoMine(m_pResManager->GetBitMap(RES_TYPE_BLOCK_7));
	else if (mine_count == 8)
		pBlock->NoMine(m_pResManager->GetBitMap(RES_TYPE_BLOCK_8));
}

void GameManager::OnClick(int x, int y)
{
	for (auto iter = m_vecBlock.begin(); iter != m_vecBlock.end(); iter++)
	{
		if ((*iter)->OnClick(x, y))
		{
			if ((*iter)->GetMine())
			{
				//게임종료
				MessageBox(NULL, TEXT("GameOver!!"), TEXT("게임오버"), MB_OK);
				for (auto iter_ = m_vecBlock.begin(); iter_ != m_vecBlock.end(); iter_++)
				{
					(*iter_)->GameOver(m_pResManager->GetBitMap(RES_TYPE_MINE));
				}
				//exit(0); // 수정필요
			}
			else
			{
				int x = ((*iter)->getX() - 41) / CARD_WIDTH;
				int y = ((*iter)->getY() - 43) / CARD_HEIGHT;

				(*iter)->setOpen();
				m_iMap[y][x] = OPEN;
				Check(x, y);
			}
		}
	}
	InvalidateRect(m_hWnd, NULL, true);
}

void GameManager::Draw(HDC hdc)
{
	m_pBackGround->Draw(hdc);
	for (auto iter = m_vecBlock.begin(); iter != m_vecBlock.end(); iter++)
	{
		(*iter)->Draw(hdc);
	}
}

void GameManager::Release()
{
	for (auto iter = m_vecBlock.begin(); iter != m_vecBlock.end(); iter++)
	{
		SAFE_DELETE(*iter);
	}
	m_vecBlock.clear();

	SAFE_DELETE(m_pResManager);
}


/*
static TCHAR text1[128];
wsprintf(text1, TEXT("%d"), );
MessageBox(NULL, text1, text1, MB_OK);
*/

/*
if (m_iMap[i][j] == 2)
continue;
*/