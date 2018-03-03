#include "GameManager.h"
#include "ResManager.h"
#include "Macro.h"
#include "Card.h"

GameManager* GameManager::m_pThis = NULL;

GameManager::GameManager()
{
	m_eGameState = GAME_STATE_WAIT;
	m_pSelectOne = NULL;
	m_pSelectTwo = NULL;
	m_dwCount = 0;
}


GameManager::~GameManager()
{
}

void GameManager::Init(HWND hWnd, HINSTANCE hInst, HDC hdc)
{
	SetTimer(hWnd, 1, 100, NULL);
	m_hWnd = hWnd;
	srand(GetTickCount());
	m_pResManager = new ResManager();
	m_pResManager->Init(hdc, hInst);

	int arr[20];
	for (int i = 0; i < 20; i++)
	{
		arr[i] = i % 10;
	}

	for (int i = 0; i < 100; i++)
	{
		int randA = arr[rand() % 20];
		int randB = arr[rand() % 20];

		int temp = arr[randA];
		arr[randA] = arr[randB];
		arr[randB] = temp;
	}

	for (int i = 0; i < 20; i++)
	{
		int index = arr[i];

		Card* pNew = new Card();
		pNew->Init(m_pResManager->GetBitMap(index), m_pResManager->GetBitMap(RES_TYPE_BACK),
			i % 10 * CARD_WIDTH + i % 10 * 10, i / 10 * CARD_HEIGHT + i / 10 * 10, index);
		m_vecCard.push_back(pNew);
	}
}

void GameManager::Update()
{
	if (m_eGameState != GAME_STATE_SHOW)
		return;

	m_dwCount++;
	if (m_dwCount >= 10)
	{
		m_pSelectOne->SetClose();
		m_pSelectTwo->SetClose();
		m_pSelectOne = NULL;
		m_pSelectTwo = NULL;
		m_dwCount = 0;
		m_eGameState = GAME_STATE_WAIT;
		InvalidateRect(m_hWnd, NULL, true);
	}
}

void GameManager::OnClick(int x, int y)
{
	if (m_eGameState == GAME_STATE_SHOW)
		return;

	for (auto iter = m_vecCard.begin(); iter != m_vecCard.end(); iter++)
	{
		if ((*iter)->OnClick(x, y))
		{
			if(m_eGameState == GAME_STATE_WAIT)
			{
				m_pSelectOne = *iter;
				m_eGameState = GAME_STATE_SELECT;
			}
			else if (m_eGameState == GAME_STATE_SELECT)
			{
				m_pSelectTwo = *iter;
				if (m_pSelectOne->GetIndex() == m_pSelectTwo->GetIndex())
				{
					m_pSelectOne = NULL;
					m_pSelectTwo = NULL;
					m_eGameState = GAME_STATE_WAIT;
				}
				else
				{
					m_dwCount = 0;
					m_eGameState = GAME_STATE_SHOW;
				}
			}

			InvalidateRect(m_hWnd, NULL, true);
		}
	}
}

void GameManager::Draw(HDC hdc)
{
	for (auto iter = m_vecCard.begin(); iter != m_vecCard.end(); iter++)
	{
		(*iter)->Draw(hdc);
	}
}

void GameManager::Release()
{
	KillTimer(m_hWnd, 1);
	for (auto iter = m_vecCard.begin(); iter != m_vecCard.end(); iter++)
	{
		SAFE_DELETE(*iter);
	}
	m_vecCard.clear();

	SAFE_DELETE(m_pResManager);
}
