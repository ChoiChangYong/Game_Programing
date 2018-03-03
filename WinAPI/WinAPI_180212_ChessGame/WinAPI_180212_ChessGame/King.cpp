#include "King.h"

vector<POINT> King::MoveRangeCheck(int map[][8], vector<POINT> moverange, int x, int y, int Param)
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
				if (map[(*iter).y / CARD_HEIGHT][(*iter).x / CARD_WIDTH] == BLACK)
					continue;
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
					continue;
				else
					m_vecResultMoveRange.push_back((*iter));
			}
		}
	}
	return m_vecResultMoveRange;
}

vector<POINT> King::getMoveRange(int map[][8], int Param, int x, int y)
{
	m_vecMoveable.clear();
	POINT point;

	point.x = m_iX;
	point.y = m_iY;
	m_vecMoveable.push_back(point);

	point.x = m_iX + 1 * CARD_WIDTH;
	point.y = m_iY;
	m_vecMoveable.push_back(point);

	point.x = m_iX;
	point.y = m_iY + 1 * CARD_HEIGHT;
	m_vecMoveable.push_back(point);

	point.x = m_iX + 1 * CARD_WIDTH;
	point.y = m_iY + 1 * CARD_HEIGHT;
	m_vecMoveable.push_back(point);

	point.x = m_iX - 1 * CARD_WIDTH;
	point.y = m_iY;
	m_vecMoveable.push_back(point);

	point.x = m_iX;
	point.y = m_iY - 1 * CARD_HEIGHT;
	m_vecMoveable.push_back(point);

	point.x = m_iX - 1 * CARD_WIDTH;
	point.y = m_iY - 1 * CARD_HEIGHT;
	m_vecMoveable.push_back(point);

	point.x = m_iX + 1 * CARD_WIDTH;
	point.y = m_iY - 1 * CARD_HEIGHT;
	m_vecMoveable.push_back(point);

	point.x = m_iX - 1 * CARD_WIDTH;
	point.y = m_iY + 1 * CARD_HEIGHT;
	m_vecMoveable.push_back(point);

	return MoveRangeCheck(map, m_vecMoveable, x, y, Param);
}


King::King()
{
}


King::~King()
{
}
