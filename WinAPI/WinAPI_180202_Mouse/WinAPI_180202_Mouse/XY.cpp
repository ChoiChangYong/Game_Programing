#include "XY.h"


void XY::setXY_Start(int x, int y)
{
	m_iX_Start = x;
	m_iY_Start = y;
}

void XY::setXY_End(int x, int y)
{
	m_iX_End = x;
	m_iY_End = y;
}


int XY::getX_Start()
{
	return m_iX_Start;
}

int XY::getX_End()
{
	return m_iX_End;
}

int XY::getY_Start()
{
	return m_iY_Start;
}

int XY::getY_End()
{
	return m_iY_End;
}

XY::XY()
{
	m_iX_Start = 0;
	m_iY_Start = 0;
	m_iX_End = 0;
	m_iY_End = 0;
}


XY::~XY()
{
}

/*
void XY::setXY(int x_s, int y_s, int x_e, int y_e)
{
m_iX_Start = x_s;
m_iY_Start = y_s;
m_iX_End = x_e;
m_iY_End = y_e;
}
*/
