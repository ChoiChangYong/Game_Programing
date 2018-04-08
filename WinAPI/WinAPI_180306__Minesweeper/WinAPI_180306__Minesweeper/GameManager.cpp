#include "GameManager.h"
#include "ResManager.h"
#include "BitMap.h"
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
	memset(m_iMine, 0, m_iWidth * sizeof(int));
	memset(m_iMap, 0, m_iWidth * m_iHeight * sizeof(int));
	m_nFlag_Count = 0;
	m_nTimeCount = 0;
	m_nMine_Count = 0;
}
GameManager::~GameManager()
{
}

void GameManager::setBlock()
{
	int mine_count = 0;

	for (int i = 0; i < m_iHeight; i++)
	{
		for (int j = 0; j < m_iWidth; j++)
		{
			m_iMap[i][j] = new Block();

			if (m_iMine[mine_count] % m_iWidth == j && m_iMine[mine_count] / m_iWidth == i)
			{
				m_iMap[i][j]->Init(m_pResManager->GetBitMap(RES_TYPE_BLOCK),
					j % m_iWidth * CARD_WIDTH + 41, i % m_iHeight * CARD_HEIGHT + 43, TRUE, FALSE, FALSE);
				mine_count++;
			}
			else
			{
				m_iMap[i][j]->Init(m_pResManager->GetBitMap(RES_TYPE_BLOCK),
					j % m_iWidth * CARD_WIDTH + 41, i % m_iHeight * CARD_HEIGHT + 43, FALSE, FALSE, FALSE);
			}
		}
	}
}

void GameManager::setMine()
{
	bool bFound;

	srand(unsigned(time(NULL)));
	//srand(0);

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
	m_nMine_Count = m_iWidth;
}

void GameManager::Init(HWND hWnd, HINSTANCE hInst, HDC hdc)
{
	m_pResManager = new ResManager();
	m_pResManager->Init(hdc, hInst);
	m_hWnd = hWnd;
	

	//��� ����

	m_pBackGround = new BitMap();
	m_pBackGround->Init(hdc, hInst, RES_TYPE_BACKGROUND);

	//���� ����

	setMine();

	//��� ����
	setBlock();

	SetTimer(m_hWnd, 1, 1000, NULL);
}

void GameManager::SetGameMode(GAME_MODE mode)
{
	for (int i = 0; i < m_iHeight; i++)
	{
		for (int j = 0; j < m_iWidth; j++)
		{
			SAFE_DELETE(m_iMap[i][j]);
		}
	}
	m_eGameMode = mode;
	m_iWidth = (m_eGameMode + 1) * 8;
	if (m_eGameMode == GAME_MODE_HARD)
		m_iHeight = (m_eGameMode) * 8;
	else
		m_iHeight = (m_eGameMode + 1) * 8;

	memset(m_iMine, 0, m_iWidth * sizeof(int));
	memset(m_iMap, 0, m_iWidth * m_iHeight * sizeof(int));

	/*
	���� ����
	*/
	setMine();
	/*
	��� ����
	*/
	setBlock();

	KillTimer(m_hWnd, 1);
	m_nTimeCount = 0;
	SetTimer(m_hWnd, 1, 1000, NULL);

	InvalidateRect(m_hWnd, NULL, true);
}

/*
�ֺ� 8���� ���� üũ & ����
*/
void GameManager::Check(int x, int y)
{
	int mine_count = 0;
	/*
	�����¿�밢�� ���� üũ
	*/
	mine_count = get_Surround_MineCount(x, y);
	/*
		�ֺ��� ���ڰ� �ϳ��� ���� ���, �ش� ��ġ ��� �� �ٽ� �ֺ� �˻�
	*/
	if (mine_count == 0)
	{
		setBlock(mine_count, x, y);
		Open_Surroundings(x, y);
	}
	/*
		�ֺ��� ���ڰ� �ϳ��� ���� ���, �ش� ��ġ ��� �� ��
	*/
	else
	{
		setBlock(mine_count, x, y);
	}
}

bool GameManager::Check_Range(int x, int y)
{
	bool flag;
	if (x<0 || y<0 || x >= m_iWidth || y >= m_iHeight)
		flag = FALSE;
	else
		flag = TRUE;
	return flag;
}

void GameManager::M_Button_Check(int x, int y)
{
	int mine_count = 0;
	int flag_count = 0;
	/*
	�����¿�밢�� ���� üũ
	*/
	mine_count = get_Surround_MineCount(x, y);
	/*
	�����¿�밢�� ��� üũ
	*/
	flag_count = get_Surround_FlagCount(x, y);

	if ((mine_count == flag_count) && (flag_count != 0))
		Open_Surroundings(x, y);
}

/*
�ش� ��� �ֺ� 8������ üũ & ����
*/
void GameManager::Open_Surroundings(int x, int y)
{
	Point pt;

	for (int i = 0; i < DIRECTION_END; i++)
	{
		pt = ptDir[i];
		int ix = x;
		int iy = y;

		ix += pt.x;
		iy += pt.y;
		if (!Check_Range(ix, iy))
		{
			continue;
		}
		else if (m_iMap[iy][ix]->getOpen()==TRUE)
		{
			continue;
		}
		else
		{
			if (!m_iMap[iy][ix]->getFlag()) // �ش� Block�� ����� �ƴ� �� �ֺ� üũ & Block ����
				Check(ix, iy);
		}
	}
}

/*
�ش� Block �ֺ� 8���⿡ ���ڰ� � �ִ��� �������ִ� �Լ�
*/
int GameManager::get_Surround_MineCount(int x, int y)
{
	int mine_count = 0;
	Point pt;

	for (int i = 0; i < DIRECTION_END; i++)
	{
		pt = ptDir[i];
		int ix = x;
		int iy = y;

		ix += pt.x;
		iy += pt.y;

		if (Check_Range(ix, iy))
			if (m_iMap[iy][ix]->getMine())
				mine_count++;
	}
	return mine_count;
}

/*
�ش� Block �ֺ� 8���⿡ ����� � �ִ��� �������ִ� �Լ�
*/
int GameManager::get_Surround_FlagCount(int x, int y)
{
	int flag_count = 0;
	Point pt;

		for (int i = 0; i < DIRECTION_END; i++)
		{
			pt = ptDir[i];
			int ix = x;
			int iy = y;

			ix += pt.x;
			iy += pt.y;

			if (Check_Range(ix, iy))
				if (m_iMap[iy][ix]->getFlag())
					flag_count++;
		}

	return flag_count;
}

/*
���� ���� Ȯ�� �� ������ �´� Block �̹��� ���
*/
void GameManager::setBlock(int mine_count, int x, int y)
{
	if (m_iMap[y][x]->getMine())
	{
		GameOver();
	}
	else
	{
		if (mine_count == 0)
			m_iMap[y][x]->NoMine(m_pResManager->GetBitMap(RES_TYPE_BLOCK_0));
		else if (mine_count == 1)
			m_iMap[y][x]->NoMine(m_pResManager->GetBitMap(RES_TYPE_BLOCK_1));
		else if (mine_count == 2)
			m_iMap[y][x]->NoMine(m_pResManager->GetBitMap(RES_TYPE_BLOCK_2));
		else if (mine_count == 3)
			m_iMap[y][x]->NoMine(m_pResManager->GetBitMap(RES_TYPE_BLOCK_3));
		else if (mine_count == 4)
			m_iMap[y][x]->NoMine(m_pResManager->GetBitMap(RES_TYPE_BLOCK_4));
		else if (mine_count == 5)
			m_iMap[y][x]->NoMine(m_pResManager->GetBitMap(RES_TYPE_BLOCK_5));
		else if (mine_count == 6)
			m_iMap[y][x]->NoMine(m_pResManager->GetBitMap(RES_TYPE_BLOCK_6));
		else if (mine_count == 7)
			m_iMap[y][x]->NoMine(m_pResManager->GetBitMap(RES_TYPE_BLOCK_7));
		else if (mine_count == 8)
			m_iMap[y][x]->NoMine(m_pResManager->GetBitMap(RES_TYPE_BLOCK_8));

		m_iMap[y][x]->setOpen();
	}
}

void GameManager::TimerStart()
{
	m_nTimeCount++;
	InvalidateRect(m_hWnd, NULL, true);
}

/*
���콺 ���� Ŭ�� �̺�Ʈ
*/
void GameManager::OnClickL(int x, int y)
{
	for (int i = 0; i < m_iHeight; i++)
	{
		for (int j = 0; j < m_iWidth; j++)
		{
			if (m_iMap[i][j]->OnClick(x, y))
			{
				if (m_iMap[i][j]->getMine())
				{
					//��������
					GameOver();
					//exit(0); // �����ʿ�
				}
				else
				{
					m_iMap[i][j]->setOpen();
					Check(j, i);
				}
			}
		}
	}
	Victory();
	InvalidateRect(m_hWnd, NULL, true);
}

/*
���콺 ������ Ŭ�� �̺�Ʈ
*/
void GameManager::OnClickR(int x, int y)
{
	for (int i = 0; i < m_iHeight; i++)
	{
		for (int j = 0; j < m_iWidth; j++)
		{
			if (m_iMap[i][j]->OnClick(x, y))
			{
				if (m_iMap[i][j]->getOpen() == FALSE)
				{
					if (m_iMap[i][j]->getFlag())
					{
						m_iMap[i][j]->setFlag(m_pResManager->GetBitMap(RES_TYPE_BLOCK), FALSE);
						m_nFlag_Count--;
						m_nMine_Count++;
					}
					else
					{
						m_iMap[i][j]->setFlag(m_pResManager->GetBitMap(RES_TYPE_FLAG), TRUE);
						m_nFlag_Count++;
						m_nMine_Count--;
					}
				}
			}
		}
	}
	InvalidateRect(m_hWnd, NULL, true);
}

/*
���콺 ��� Ŭ�� �̺�Ʈ
*/
void GameManager::OnClickM(int x, int y)
{
	for (int i = 0; i < m_iHeight; i++)
	{
		for (int j = 0; j < m_iWidth; j++)
		{
			if (m_iMap[i][j]->OnClick(x, y))
			{
				M_Button_Check(j, i);
			}
		}
	}
	Victory();
	InvalidateRect(m_hWnd, NULL, true);
}

void GameManager::Victory()
{
	bool bVictory = TRUE;
	for (int i = 0; i < m_iHeight; i++)
	{
		for (int j = 0; j < m_iWidth; j++)
		{
			if (m_iMap[i][j]->getFlag() == FALSE)
				if (m_iMap[i][j]->getMine() == TRUE)
					bVictory = FALSE;
		}
	}

	if (bVictory)
	{
		for (int i = 0; i < m_iHeight; i++)
		{
			for (int j = 0; j < m_iWidth; j++)
			{
				m_iMap[i][j]->GameOver(m_pResManager->GetBitMap(RES_TYPE_MINE));
			}
		}
		KillTimer(m_hWnd, 1);
		InvalidateRect(m_hWnd, NULL, true);
		MessageBox(m_hWnd, TEXT("Victory!!"), TEXT("���ӽ¸�!!"), MB_OK);

		SetGameMode(m_eGameMode);
	}
}
void GameManager::GameOver()
{
	for (int i = 0; i < m_iHeight; i++)
	{
		for (int j = 0; j < m_iWidth; j++)
		{
			m_iMap[i][j]->GameOver(m_pResManager->GetBitMap(RES_TYPE_MINE));
		}
	}
	KillTimer(m_hWnd, 1);
	InvalidateRect(m_hWnd, NULL, true);
	MessageBox(m_hWnd, TEXT("GameOver!!"), TEXT("���ӿ���"), MB_OK);

	SetGameMode(m_eGameMode);
}
void GameManager::Reset()
{
	for (int i = 0; i < m_iHeight; i++)
	{
		for (int j = 0; j < m_iWidth; j++)
		{
			SAFE_DELETE(m_iMap[i][j]);
		}
	}

	m_iWidth = (m_eGameMode + 1) * 8;
	if (m_eGameMode == GAME_MODE_HARD)
		m_iHeight = (m_eGameMode) * 8;
	else
		m_iHeight = (m_eGameMode + 1) * 8;

	memset(m_iMine, 0, m_iWidth * sizeof(int));
	memset(m_iMap, 0, m_iWidth * m_iHeight * sizeof(int));

	/*
	���� ����
	*/
	setMine();
	/*
	��� ����
	*/
	setBlock();

	SetGameMode(m_eGameMode);
	InvalidateRect(m_hWnd, NULL, true);
}
void GameManager::Draw(HDC hdc)
{
	m_pBackGround->Draw(hdc, 0, 0);
	for (int i = 0; i < m_iHeight; i++)
	{
		for (int j = 0; j < m_iWidth; j++)
		{
			m_iMap[i][j]->Draw(hdc);
		}
	}
	wsprintf(sTime, TEXT("%d:%d:%d"), (m_nTimeCount / 60 / 60) % 60, (m_nTimeCount / 60) % 60, m_nTimeCount % 60);
	TextOut(hdc, 170, 480, sTime, lstrlen(sTime));

	wsprintf(sTime, TEXT("%d"), m_nMine_Count);
	TextOut(hdc, 675, 480, sTime, lstrlen(sTime));
}

void GameManager::Release()
{
	for (int i = 0; i < m_iHeight; i++)
	{
		for (int j = 0; j < m_iWidth; j++)
		{
			SAFE_DELETE(m_iMap[i][j]);
		}
	}

	m_pBackGround->Release();
	SAFE_DELETE(m_pBackGround);

	m_pResManager->Release();
	SAFE_DELETE(m_pResManager);

	SAFE_DELETE(m_pThis);
}


/*
static TCHAR text1[128];
wsprintf(text1, TEXT("%d"), );
MessageBox(NULL, text1, text1, MB_OK);
*/
