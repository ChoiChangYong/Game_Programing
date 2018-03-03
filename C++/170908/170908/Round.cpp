#include "Round.h"



int Round::setDelay(int round)
{
	return m_nRound[round-1][0];
}

Round::Round()
{
	m_nRound[0][0] = 200;
	m_nRound[1][0] = 150;
	m_nRound[2][0] = 100;
	m_nRound[3][0] = 80;
	m_nRound[4][0] = 55;
	m_nRound[0][1] = 0;
	m_nRound[1][1] = 0;
	m_nRound[2][1] = 0;
	m_nRound[3][1] = 0;
	m_nRound[4][1] = 0;
}


Round::~Round()
{
}
