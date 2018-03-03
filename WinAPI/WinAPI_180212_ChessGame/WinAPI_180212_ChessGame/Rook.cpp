#include "Rook.h"

vector<POINT> Rook::MoveRangeCheck(int map[][8], vector<POINT> moverange, int x, int y, int Param)
{
	if (Param == BLACK)
	{
		for (auto iter = moverange.begin(); iter != moverange.end(); iter++)
		{
			if (x == (*iter).x && y == (*iter).y)
				m_vecResultMoveRange.push_back((*iter));
			else
			{
				if (map[(*iter).y / CARD_HEIGHT][(*iter).x / CARD_WIDTH] == BLACK)
					break;
				if (map[(*iter).y / CARD_HEIGHT][(*iter).x / CARD_WIDTH] == WHITE)
				{
					m_vecResultMoveRange.push_back((*iter));
					break;
				}
				else
					m_vecResultMoveRange.push_back((*iter));
			}
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
				if (map[(*iter).y / CARD_HEIGHT][(*iter).x / CARD_WIDTH] == WHITE)
					break;
				if (map[(*iter).y / CARD_HEIGHT][(*iter).x / CARD_WIDTH] == BLACK)
				{
					m_vecResultMoveRange.push_back((*iter));
					break;
				}
				else
					m_vecResultMoveRange.push_back((*iter));
			}
		}
	}
	return m_vecResultMoveRange;
}

vector<POINT> Rook::getMoveRange(int map[][8], int Param, int x, int y)
{
	m_vecMoveable.clear();
	m_vecResultMoveRange.clear();
	POINT point;

	/*
	원점
	*/
	point.x = m_iX;
	point.y = m_iY;
	m_vecMoveable.push_back(point);
	MoveRangeCheck(map, m_vecMoveable, x, y, Param);

	/*
	가로세로
	*/
	for (int i = 1; i < 8; i++)
	{
		point.x = m_iX;
		point.y = m_iY + i*CARD_HEIGHT;
		m_vecMoveable.push_back(point);
	}
	MoveRangeCheck(map, m_vecMoveable, x, y, Param);
	m_vecMoveable.clear();
	for (int i = 1; i < 8; i++)
	{
		point.x = m_iX;
		point.y = m_iY - i*CARD_HEIGHT;
		m_vecMoveable.push_back(point);
	}
	MoveRangeCheck(map, m_vecMoveable, x, y, Param);
	m_vecMoveable.clear();
	for (int i = 1; i < 8; i++)
	{
		point.x = m_iX + i*CARD_WIDTH;
		point.y = m_iY;
		m_vecMoveable.push_back(point);
	}
	MoveRangeCheck(map, m_vecMoveable, x, y, Param);
	m_vecMoveable.clear();
	for (int i = 1; i < 8; i++)
	{
		point.x = m_iX - i*CARD_WIDTH;
		point.y = m_iY;
		m_vecMoveable.push_back(point);
	}
	MoveRangeCheck(map, m_vecMoveable, x, y, Param);

	return m_vecResultMoveRange;
}


Rook::Rook()
{
}


Rook::~Rook()
{
}
