#include "Pawn.h"
#include "Queen.h"

vector<POINT> Pawn::MoveRangeCheck(int map[][8], vector<POINT> moverange, int x, int y, int Param)
{
	m_vecResultMoveRange.clear();
	if (Param == BLACK)
	{
		for (auto iter = moverange.begin(); iter != moverange.end(); iter++)
		{
			if (x == (*iter).x && y == (*iter).y)
				m_vecResultMoveRange.push_back((*iter));
			else
			{
				if (map[(*iter).y / CARD_HEIGHT][(*iter).x / CARD_WIDTH] == WHITE || map[(*iter).y / CARD_HEIGHT][(*iter).x / CARD_WIDTH] == BLACK)
					break;
				else
				{
					m_vecResultMoveRange.push_back((*iter));
				}
			}
		}
		POINT XY;
		if (map[y / CARD_WIDTH + 1][x / CARD_HEIGHT - 1] == WHITE)
		{
			XY.x = x - CARD_WIDTH;
			XY.y = y + CARD_HEIGHT;
			m_vecResultMoveRange.push_back(XY);
		}
		if (map[y / CARD_WIDTH + 1][x / CARD_HEIGHT + 1] == WHITE)
		{
			XY.x = x + CARD_WIDTH;
			XY.y = y + CARD_HEIGHT;
			m_vecResultMoveRange.push_back(XY);
		}
	}
	else if (Param == WHITE)
	{
		for (auto iter = moverange.begin(); iter != moverange.end(); iter++)
		{
			if (x == (*iter).x && y == (*iter).y)
				m_vecResultMoveRange.push_back((*iter));
			else
			{
				if (map[(*iter).y / CARD_HEIGHT][(*iter).x / CARD_WIDTH] == WHITE || map[(*iter).y / CARD_HEIGHT][(*iter).x / CARD_WIDTH] == BLACK)
					break;
				else
				{
					m_vecResultMoveRange.push_back((*iter));
				}
			}
		}
		POINT XY;
		if (map[y / CARD_WIDTH - 1][x / CARD_HEIGHT - 1] == BLACK)
		{
			XY.x = x - CARD_WIDTH;
			XY.y = y - CARD_HEIGHT;
			m_vecResultMoveRange.push_back(XY);
		}
		if (map[y / CARD_WIDTH - 1][x / CARD_HEIGHT + 1] == BLACK)
		{
			XY.x = x + CARD_WIDTH;
			XY.y = y - CARD_HEIGHT;
			m_vecResultMoveRange.push_back(XY);
		}
	}
	return m_vecResultMoveRange;
}

vector<POINT> Pawn::getMoveRange(int map[][8], int Param, int x, int y)
{
	m_vecMoveable.clear();
	POINT point;
	int range = 2;
	if (Param == BLACK)
	{
		if (y == CARD_WIDTH)
		{
			range = 3;
		}
		for (int i = 0; i < range; i++)
		{
			point.x = m_iX;
			point.y = m_iY + i*CARD_WIDTH;
			m_vecMoveable.push_back(point);
		}
	}
	else if (Param == WHITE)
	{
		if (y == CARD_WIDTH * 6)
		{
			range = 3;
		}
		for (int i = 0; i < range; i++)
		{
			point.x = m_iX;
			point.y = m_iY - i*CARD_WIDTH;
			m_vecMoveable.push_back(point);
		}
	}
	return MoveRangeCheck(map, m_vecMoveable, x, y, Param);
}

Chessman* Pawn::Upgrade(Chessman* chessman_select, BitMap* bitmap, int color)
{
	Queen* pNew_Queen = new Queen();
	pNew_Queen->Init(bitmap, chessman_select->getX(), chessman_select->getY(), 0, BLACK);

	chessman_select = pNew_Queen;
	return chessman_select;
}


Pawn::Pawn()
{
}


Pawn::~Pawn()
{
}
