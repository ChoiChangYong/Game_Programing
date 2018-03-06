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
	��� ����
	*/
	setBackGround(pNew_Block);
	/*
	���� ����
	*/
	setMine();
	/*
	���� ����
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
	for (int i = 0; i < m_iHeight; i++)
		memset(m_iMap[i], BLOCK, m_iWidth * sizeof(int));
	m_vecBlock.clear();

	/*
	���� ����
	*/
	setMine();
	/*
	���� ����
	*/
	Block* pNew_Block = new Block();
	setBlock(pNew_Block);

	InvalidateRect(m_hWnd, NULL, true);
}

/*
�����¿�밢�� ���� üũ
*/
void GameManager::Check(int x, int y, bool flag)
{
	Point pt;
	pBlock = new Block();
	for (auto iter = m_vecBlock.begin(); iter != m_vecBlock.end(); iter++)
	{
		if (((*iter)->getX() - 41) / CARD_WIDTH == x && ((*iter)->getY() - 43) / CARD_HEIGHT == y)
			pBlock = (*iter);
	}
	int mine_count = 0;
	/*
	�����¿�밢�� üũ
	*/
	if (m_iMap[y - 1][x - 1] == MINE) // �ش� Block�� ������ ��
		mine_count++;
	if (m_iMap[y][x - 1] == MINE) // �ش� Block�� ������ ��
		mine_count++;
	if (m_iMap[y + 1][x - 1] == MINE) // �ش� Block�� ������ ��
		mine_count++;
	if (m_iMap[y + 1][x] == MINE) // �ش� Block�� ������ ��
		mine_count++;
	if (m_iMap[y + 1][x + 1] == MINE) // �ش� Block�� ������ ��
		mine_count++;
	if (m_iMap[y][x + 1] == MINE) // �ش� Block�� ������ ��
		mine_count++;
	if (m_iMap[y - 1][x + 1] == MINE) // �ش� Block�� ������ ��
		mine_count++;
	if (m_iMap[y - 1][x] == MINE) // �ش� Block�� ������ ��
		mine_count++;

	/*
		�ֺ��� ���ڰ� �ϳ��� ���� ���, �ش� ��ġ ��� �� �ٽ� �ֺ� �˻�
	*/
	if (mine_count == 0 && flag == FALSE)
	{
		setBlock(pBlock, mine_count, x, y);
		for (int i = 0; i < DIRECTION_END; i++)
		{
			pt = ptDir[i];
			int ix = x;
			int iy = y;

			ix += pt.x;
			iy += pt.y;
			if (ix<0 || iy<0 || ix>m_iWidth || iy>m_iHeight)
			{
				continue;
			}
			else if (m_iMap[iy][ix] == OPEN)
			{
				continue;
			}
			else
			{
				Check(ix, iy);
			}
		}
	}
	/*
		�ֺ��� ���ڰ� �ϳ��� ���� ���, �ش� ��ġ ��� �� ��
	*/
	else
	{
		setBlock(pBlock, mine_count, x, y);
	}
}

void GameManager::M_Button_Check(int x, int y)
{
	Point pt;
	pBlock = new Block();
	for (auto iter = m_vecBlock.begin(); iter != m_vecBlock.end(); iter++)
	{
		if (((*iter)->getX() - 41) / CARD_WIDTH == x && ((*iter)->getY() - 43) / CARD_HEIGHT == y)
			pBlock = (*iter);
	}
	int mine_count = 0;
	int flag_count = 0;
	/*
	�����¿�밢�� ���� üũ
	*/
	if (m_iMap[y - 1][x - 1] == MINE) // �ش� Block�� ������ ��
		mine_count += getMine_Surroundings(x - 1, y - 1);
	if (m_iMap[y][x - 1] == MINE)
		mine_count += getMine_Surroundings(x - 1, y);
	if (m_iMap[y + 1][x - 1] == MINE)
		mine_count += getMine_Surroundings(x - 1, y + 1);
	if (m_iMap[y + 1][x] == MINE)
		mine_count += getMine_Surroundings(x, y + 1);
	if (m_iMap[y + 1][x + 1] == MINE)
		mine_count += getMine_Surroundings(x + 1, y + 1);
	if (m_iMap[y][x + 1] == MINE)
		mine_count += getMine_Surroundings(x + 1, y);
	if (m_iMap[y - 1][x + 1] == MINE)
		mine_count += getMine_Surroundings(x + 1, y - 1);
	if (m_iMap[y - 1][x] == MINE)
		mine_count += getMine_Surroundings(x, y - 1);

	/*
	�����¿�밢�� ����� �������� üũ
	*/
	if (m_iMap[y - 1][x - 1] == FLAG) // �ش� Block�� ����� ��
		mine_count += getMine_Surroundings(x - 1, y - 1);
	if (m_iMap[y][x - 1] == FLAG)
		flag_count += getMine_Surroundings(x - 1, y);
	if (m_iMap[y + 1][x - 1] == FLAG)
		flag_count += getMine_Surroundings(x - 1, y + 1);
	if (m_iMap[y + 1][x] == FLAG)
		flag_count += getMine_Surroundings(x, y + 1);
	if (m_iMap[y + 1][x + 1] == FLAG)
		flag_count += getMine_Surroundings(x + 1, y + 1);
	if (m_iMap[y][x + 1] == FLAG)
		flag_count += getMine_Surroundings(x + 1, y);
	if (m_iMap[y - 1][x + 1] == FLAG)
		flag_count += getMine_Surroundings(x + 1, y - 1);
	if (m_iMap[y - 1][x] == FLAG)
		flag_count += getMine_Surroundings(x, y - 1);

	if (mine_count == flag_count)
		Open_Surroundings(x, y);
}

bool GameManager::getMine_Surroundings(int x, int y)
{
	bool mine = FALSE;
	for (auto iter = m_vecBlock.begin(); iter != m_vecBlock.end(); iter++)
	{
		if (((*iter)->getX() - 41) / CARD_WIDTH == x && ((*iter)->getY() - 43) / CARD_HEIGHT == y)
			mine =  (*iter)->GetMine();
	}
	return mine;
}

void GameManager::Open_Surroundings(int x, int y)
{
	if (m_iMap[y - 1][x - 1] != FLAG) // �ش� Block�� ����� ��
		Check(x-1, y-1, TRUE);
	if (m_iMap[y][x - 1] != FLAG)
		Check(x-1, y, TRUE);
	if (m_iMap[y + 1][x - 1] != FLAG)
		Check(x-1, y+1, TRUE);
	if (m_iMap[y + 1][x] != FLAG)
		Check(x, y+1, TRUE);
	if (m_iMap[y + 1][x + 1] != FLAG)
		Check(x+1, y+1, TRUE);
	if (m_iMap[y][x + 1] != FLAG)
		Check(x+1, y, TRUE);
	if (m_iMap[y - 1][x + 1] != FLAG)
		Check(x+1, y-1, TRUE);
	if (m_iMap[y - 1][x] != FLAG)
		Check(x, y-1, TRUE);
}
/*
���� ���� Ȯ�� �� Block �̹��� ���
*/
void GameManager::setBlock(Block * pBlock, int mine_count, int x, int y)
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

	m_iMap[y][x] = OPEN;
}

void GameManager::OnClickL(int x, int y)
{
	for (auto iter = m_vecBlock.begin(); iter != m_vecBlock.end(); iter++)
	{
		if ((*iter)->OnClick(x, y))
		{
			if ((*iter)->GetMine())
			{
				//��������
				MessageBox(NULL, TEXT("GameOver!!"), TEXT("���ӿ���"), MB_OK);
				for (auto iter_ = m_vecBlock.begin(); iter_ != m_vecBlock.end(); iter_++)
				{
					(*iter_)->GameOver(m_pResManager->GetBitMap(RES_TYPE_MINE));
				}
				//exit(0); // �����ʿ�
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

void GameManager::OnClickR(int x, int y)
{
	for (auto iter = m_vecBlock.begin(); iter != m_vecBlock.end(); iter++)
	{
		if ((*iter)->OnClick(x, y))
		{
			int x = ((*iter)->getX() - 41) / CARD_WIDTH;
			int y = ((*iter)->getY() - 43) / CARD_HEIGHT;
			if (m_iMap[y][x] != OPEN)
			{
				if ((*iter)->getFlag())
				{
					(*iter)->setFlag(m_pResManager->GetBitMap(RES_TYPE_BLOCK), FALSE);
					m_iMap[y][x] = BLOCK;
				}
				else
				{
					(*iter)->setFlag(m_pResManager->GetBitMap(RES_TYPE_FLAG), TRUE);
					m_iMap[y][x] = FLAG;
				}
			}
		}
	}
	InvalidateRect(m_hWnd, NULL, true);
}

void GameManager::OnClickM(int x, int y)
{
	for (auto iter = m_vecBlock.begin(); iter != m_vecBlock.end(); iter++)
	{
		if ((*iter)->OnClick(x, y))
		{
			int x = ((*iter)->getX() - 41) / CARD_WIDTH;
			int y = ((*iter)->getY() - 43) / CARD_HEIGHT;
			M_Button_Check(x, y);
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


/*
���� �����!!!!

���ε� ���� ��¥ ���� �ƴϴ�.

���ο��� mine ���� ����
�ʿ� ���̴� block, open, flag �� ǥ��
mine�� �ɹ����� m_bMine���� �Ǻ��Ͽ� ī�����ϰ�

�����¿�밢�� m_bFlag�� m_bMine�� ���� ī�����Ͽ�
M��ư Ŭ���� ������ ������ flag �����ϰ� ���� open���� ����

Draw�� �� ���ε� ������ �׷��ֱ�
*/