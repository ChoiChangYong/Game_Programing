#include "GameManager.h"
#include "ResManager.h"
#include "Macro.h"
#include "Chessman.h"
#include "Block.h"
#include "Move_Range.h"

#include "Pawn.h"
#include "Rook.h"
#include "Bishop.h"
#include "Knight.h"
#include "King.h"
#include "Queen.h"



GameManager* GameManager::m_pThis = NULL;

GameManager::GameManager()
{
	m_eGameState = GAME_STATE_WAIT;
	m_bTurn = BLACK;
	memset(m_aiMap, 0, 8*8*sizeof(int));
}
GameManager::~GameManager()
{
}


void GameManager::Init(HWND hWnd, HINSTANCE hInst, HDC hdc)
{
	m_hWnd = hWnd;
	m_pResManager = new ResManager();
	m_pResManager->Init(hdc, hInst);

	int nCount = 0;
	for (int i = 0; i < 8 * 8; i++)
	{
		Pawn* pNew_Pawn = new Pawn();
		Rook* pNew_Rook = new Rook();
		Knight* pNew_Knight = new Knight();
		Bishop* pNew_Bishop = new Bishop();
		Queen* pNew_Queen = new Queen();
		King* pNew_King = new King();


		Block* pNew_Block = new Block();
		Move_Range* pNew_Range = new Move_Range();

		/*
		Black
		*/
		if (i / 8 == 0)
		{
			if (i % 8 == 0 || i % 8 == 7)
			{
				pNew_Rook->Init(m_pResManager->GetBitMap(RES_TYPE_B_ROOK),
					i % 8 * CARD_WIDTH, i / 8 * CARD_HEIGHT, nCount, BLACK);
				m_vecChessman.push_back(pNew_Rook);
			}
			else if (i % 8 == 1 || i % 8 == 6)
			{
				pNew_Knight->Init(m_pResManager->GetBitMap(RES_TYPE_B_KNIGHT),
					i % 8 * CARD_WIDTH, i / 8 * CARD_HEIGHT, nCount, BLACK);
				m_vecChessman.push_back(pNew_Knight);
			}
			else if (i % 8 == 2 || i % 8 == 5)
			{
				pNew_Bishop->Init(m_pResManager->GetBitMap(RES_TYPE_B_BISHOP),
					i % 8 * CARD_WIDTH, i / 8 * CARD_HEIGHT, nCount, BLACK);
				m_vecChessman.push_back(pNew_Bishop);
			}
			else if (i % 8 == 3)
			{
				pNew_Queen->Init(m_pResManager->GetBitMap(RES_TYPE_B_QUEEN),
					i % 8 * CARD_WIDTH, i / 8 * CARD_HEIGHT, nCount, BLACK);
				m_vecChessman.push_back(pNew_Queen);
			}
			else if (i % 8 == 4)
			{
				pNew_King->Init(m_pResManager->GetBitMap(RES_TYPE_B_KING),
					i % 8 * CARD_WIDTH, i / 8 * CARD_HEIGHT, nCount, BLACK);
				m_vecChessman.push_back(pNew_King);
			}
			m_aiMap[i / 8][i % 8] = 1;
			nCount++;
		}
		if (i / 8 == 1)
		{
			pNew_Pawn->Init(m_pResManager->GetBitMap(RES_TYPE_B_PAWN),
				i % 8 * CARD_WIDTH, i / 8 * CARD_HEIGHT, nCount, BLACK);
			m_vecChessman.push_back(pNew_Pawn);
			m_aiMap[i / 8][i % 8] = 1;
			nCount++;
		}
		/*
		White
		*/
		nCount = 0;
		if (i / 8 == 7)
		{
			if (i % 8 == 0 || i % 8 == 7)
			{
				pNew_Rook->Init(m_pResManager->GetBitMap(RES_TYPE_W_ROOK),
					i % 8 * CARD_WIDTH, i / 8 * CARD_HEIGHT, nCount, WHITE);
				m_vecChessman.push_back(pNew_Rook);
			}
			else if (i % 8 == 1 || i % 8 == 6)
			{
				pNew_Knight->Init(m_pResManager->GetBitMap(RES_TYPE_W_KNIGHT),
					i % 8 * CARD_WIDTH, i / 8 * CARD_HEIGHT, nCount, WHITE);
				m_vecChessman.push_back(pNew_Knight);
			}
			else if (i % 8 == 2 || i % 8 == 5)
			{
				pNew_Bishop->Init(m_pResManager->GetBitMap(RES_TYPE_W_BISHOP),
					i % 8 * CARD_WIDTH, i / 8 * CARD_HEIGHT, nCount, WHITE);
				m_vecChessman.push_back(pNew_Bishop);
			}
			else if (i % 8 == 3)
			{
				pNew_Queen->Init(m_pResManager->GetBitMap(RES_TYPE_W_QUEEN),
					i % 8 * CARD_WIDTH, i / 8 * CARD_HEIGHT, nCount, WHITE);
				m_vecChessman.push_back(pNew_Queen);
			}
			else if (i % 8 == 4)
			{
				pNew_King->Init(m_pResManager->GetBitMap(RES_TYPE_W_KING),
					i % 8 * CARD_WIDTH, i / 8 * CARD_HEIGHT, nCount, WHITE);
				m_vecChessman.push_back(pNew_King);
			}
			m_aiMap[i / 8][i % 8] = 2;
			nCount++;
		}
		if (i / 8 == 6)
		{
			pNew_Pawn->Init(m_pResManager->GetBitMap(RES_TYPE_W_PAWN),
				i % 8 * CARD_WIDTH, i / 8 * CARD_HEIGHT, nCount, WHITE);
			m_vecChessman.push_back(pNew_Pawn);
			m_aiMap[i / 8][i % 8] = 2;
			nCount++;
		}

		/*
		Block(칸)
		*/
		if ((i / 8) % 2 == 0)
		{
			if ((i % 8) % 2 == 0)
			{
				pNew_Block->Init(m_pResManager->GetBitMap(RES_TYPE_BLOCK_0),
					i % 8 * CARD_WIDTH, i / 8 * CARD_HEIGHT, i, 0);
			}
			else
			{
				pNew_Block->Init(m_pResManager->GetBitMap(RES_TYPE_BLOCK_1),
					i % 8 * CARD_WIDTH, i / 8 * CARD_HEIGHT, i, 0);

			}
			m_vecBlock.push_back(pNew_Block);
		}
		else
		{
			if ((i % 8) % 2 == 0)
			{
				pNew_Block->Init(m_pResManager->GetBitMap(RES_TYPE_BLOCK_1),
					i % 8 * CARD_WIDTH, i / 8 * CARD_HEIGHT, i, 0);
			}
			else
			{
				pNew_Block->Init(m_pResManager->GetBitMap(RES_TYPE_BLOCK_0),
					i % 8 * CARD_WIDTH, i / 8 * CARD_HEIGHT, i, 0);

			}
			m_vecBlock.push_back(pNew_Block);
		}

		/*
		Move_Range 초기값
		*/
		if (m_aiMap[i / 8][i % 8] == 1)
		{
			pNew_Range->Init(m_pResManager->GetBitMap(RES_TYPE_BLOCK_RANGE),
				i % 8 * CARD_WIDTH, i / 8 * CARD_HEIGHT, i, 0);
			m_vecMove_Range.push_back(pNew_Range);
		}

	}
}

void GameManager::Catch(int Color)
{
	for (auto iter = m_vecChessman.begin(); iter != m_vecChessman.end(); iter++)
	{
		if ((*iter)->getColor() == Color)
		{
			if ((*iter)->getX() == m_pChessman_Select->getX() && (*iter)->getY() == m_pChessman_Select->getY())
			{
				m_vecChessman.erase(iter);
				break;
			}
		}
	}
}

void GameManager::Update()
{
	if (m_bTurn == BLACK)
	{
		if (m_eGameState == GAME_STATE_WAIT)
		{
			m_vecMove_Range.clear();
			for (int i = 0; i < 8 * 8; i++)
			{
				if (m_aiMap[i / 8][i % 8] == BLACK)
				{
					Move_Range* pNew_Range = new Move_Range();
					pNew_Range->Init(m_pResManager->GetBitMap(RES_TYPE_BLOCK_RANGE),
						i % 8 * CARD_WIDTH, i / 8 * CARD_HEIGHT, i, 0);
					m_vecMove_Range.push_back(pNew_Range);
				}
			}
		}
		else if (m_eGameState == GAME_STATE_SELECT)
		{
			m_vecMoveable.clear();
			m_vecMove_Range.clear();
			m_vecMoveable = m_pChessman_Select->getMoveRange(m_aiMap, BLACK, m_pChessman_Select->getX(), m_pChessman_Select->getY());

			for (auto iter = m_vecMoveable.begin(); iter != m_vecMoveable.end(); iter++)
			{
				Move_Range* pNew_Range = new Move_Range();
				pNew_Range->Init(m_pResManager->GetBitMap(RES_TYPE_BLOCK_RANGE),
					(*iter).x, (*iter).y, 0, 0);
				m_vecMove_Range.push_back(pNew_Range);
			}
		}
	}
	if (m_bTurn == WHITE)
	{
		if (m_eGameState == GAME_STATE_WAIT)
		{
			m_vecMove_Range.clear();
			for (int i = 0; i < 8 * 8; i++)
			{
				if (m_aiMap[i / 8][i % 8] == WHITE)
				{
					Move_Range* pNew_Range = new Move_Range();
					pNew_Range->Init(m_pResManager->GetBitMap(RES_TYPE_BLOCK_RANGE),
						i % 8 * CARD_WIDTH, i / 8 * CARD_HEIGHT, i, 0);
					m_vecMove_Range.push_back(pNew_Range);
				}
			}
		}
		else if (m_eGameState == GAME_STATE_SELECT)
		{
			m_vecMoveable.clear();
			m_vecMove_Range.clear();
			m_vecMoveable = m_pChessman_Select->getMoveRange(m_aiMap, WHITE, m_pChessman_Select->getX(), m_pChessman_Select->getY());

			for (auto iter = m_vecMoveable.begin(); iter != m_vecMoveable.end(); iter++)
			{
				Move_Range* pNew_Range = new Move_Range();
				pNew_Range->Init(m_pResManager->GetBitMap(RES_TYPE_BLOCK_RANGE),
					(*iter).x, (*iter).y, 0, 0);
				m_vecMove_Range.push_back(pNew_Range);
			}
		}
	}
}

void GameManager::OnClick(int x, int y)
{
	if (m_bTurn == BLACK)
	{
		if (m_eGameState == GAME_STATE_WAIT)
		{
			for (auto iter = m_vecChessman.begin(); iter != m_vecChessman.end(); iter++)
			{
				if ((*iter)->getColor() == BLACK)
				{
					if ((*iter)->OnClick(x, y))
					{
						m_eGameState = GAME_STATE_SELECT;
						m_pChessman_Select = (*iter);
						break;
					}
				}
			}
		}
		else if (m_eGameState == GAME_STATE_SELECT)
		{
			for (auto iter = m_vecMove_Range.begin(); iter != m_vecMove_Range.end(); iter++)
			{
				if ((*iter)->OnClick(x, y))
				{
					m_eGameState = GAME_STATE_WAIT;
					if (m_pChessman_Select->getX() == (*iter)->getX() && m_pChessman_Select->getY() == (*iter)->getY())
						break;
					else
					{
						m_aiMap[m_pChessman_Select->getY() / CARD_HEIGHT][m_pChessman_Select->getX() / CARD_WIDTH] = 0;
						m_pChessman_Select->setXY((*iter)->getX(), (*iter)->getY());
						m_aiMap[m_pChessman_Select->getY() / CARD_HEIGHT][m_pChessman_Select->getX() / CARD_WIDTH] = BLACK;
						Catch(WHITE);
						/*
						Pawn 업그레이드 (Pawn -> Queen)
						*/
						if (m_pChessman_Select->getY() == 126*7)
						{
							Pawn* pTemp = dynamic_cast<Pawn*>(m_pChessman_Select);
							if (pTemp != NULL)
							{
								for (auto iter = m_vecChessman.begin(); iter != m_vecChessman.end(); iter++)
								{
									if ((*iter)->getX() == m_pChessman_Select->getX() && (*iter)->getY() == m_pChessman_Select->getY())
									{
										m_vecChessman.erase(iter);
										break;
									}
								}
								Queen* pNew_Queen = new Queen();
								pNew_Queen->Init(m_pResManager->GetBitMap(RES_TYPE_B_QUEEN), m_pChessman_Select->getX(), m_pChessman_Select->getY(), 1, BLACK);
								m_vecChessman.push_back(pNew_Queen);
							}
						}
						m_bTurn = WHITE;
					}
				}
			}
		}
	}
	else if (m_bTurn == WHITE)
	{
		if (m_eGameState == GAME_STATE_WAIT)
		{
			for (auto iter = m_vecChessman.begin(); iter != m_vecChessman.end(); iter++)
			{
				if ((*iter)->getColor() == WHITE)
				{
					if ((*iter)->OnClick(x, y))
					{
						m_eGameState = GAME_STATE_SELECT;
						m_pChessman_Select = (*iter);
						break;
					}
				}
			}
		}
		else if (m_eGameState == GAME_STATE_SELECT)
		{
			for (auto iter = m_vecMove_Range.begin(); iter != m_vecMove_Range.end(); iter++)
			{
				if ((*iter)->OnClick(x, y))
				{
					m_eGameState = GAME_STATE_WAIT;
					if (m_pChessman_Select->getX() == (*iter)->getX() && m_pChessman_Select->getY() == (*iter)->getY())
						break;
					else
					{
						m_aiMap[m_pChessman_Select->getY() / CARD_HEIGHT][m_pChessman_Select->getX() / CARD_WIDTH] = 0;
						m_pChessman_Select->setXY((*iter)->getX(), (*iter)->getY());
						m_aiMap[m_pChessman_Select->getY() / CARD_HEIGHT][m_pChessman_Select->getX() / CARD_WIDTH] = WHITE;
						Catch(BLACK);

						/*
						Pawn 업그레이드 (Pawn -> Queen)
						*/
						if (m_pChessman_Select->getY() == 0)
						{
							Pawn* pTemp = dynamic_cast<Pawn*>(m_pChessman_Select);
							if (pTemp != NULL)
							{
								for (auto iter = m_vecChessman.begin(); iter != m_vecChessman.end(); iter++)
								{
									if ((*iter)->getX() == m_pChessman_Select->getX() && (*iter)->getY() == m_pChessman_Select->getY())
									{
										m_vecChessman.erase(iter);
										break;
									}
								}
								Queen* pNew_Queen = new Queen();
								pNew_Queen->Init(m_pResManager->GetBitMap(RES_TYPE_W_QUEEN), m_pChessman_Select->getX(), m_pChessman_Select->getY(), 1, WHITE);
								m_vecChessman.push_back(pNew_Queen);
							}
						}
						m_bTurn = BLACK;
					}
				}
			}
		}
	}

	Update();
	InvalidateRect(m_hWnd, NULL, true);
}

void GameManager::Draw(HDC hdc)
{
	for (auto iter = m_vecBlock.begin(); iter != m_vecBlock.end(); iter++)
	{
		(*iter)->Draw(hdc);
	}
	for (auto iter = m_vecMove_Range.begin(); iter != m_vecMove_Range.end(); iter++)
	{
		(*iter)->Draw(hdc);
	}
	for (auto iter = m_vecChessman.begin(); iter != m_vecChessman.end(); iter++)
	{
		(*iter)->Draw(hdc);
	}
}

void GameManager::Release()
{
	for (auto iter = m_vecChessman.begin(); iter != m_vecChessman.end(); iter++)
	{
		SAFE_DELETE(*iter);
	}
	m_vecChessman.clear();
	for (auto iter = m_vecBlock.begin(); iter != m_vecBlock.end(); iter++)
	{
		SAFE_DELETE(*iter);
	}
	m_vecBlock.clear();
	for (auto iter = m_vecMove_Range.begin(); iter != m_vecMove_Range.end(); iter++)
	{
		SAFE_DELETE(*iter);
	}
	m_vecMove_Range.clear();

	SAFE_DELETE(m_pResManager);
}

/* 선택된 자신 Range
m_vecMove_Range.clear();
Move_Range* pNew_Range = new Move_Range();
pNew_Range->Init(m_pResManager->GetBitMap(RES_TYPE_BLOCK_RANGE),
(*iter)->getX(), (*iter)->getY(), 0);
m_vecMove_Range.push_back(pNew_Range);
*/