#pragma once
class XY
{
private:
	int m_iX_Start;
	int m_iY_Start;
	int m_iX_End;
	int m_iY_End;
public:
	void setXY_Start(int x, int y);
	void setXY_End(int x, int y);
	
	int getX_Start();
	int getX_End();
	int getY_Start();
	int getY_End();
	XY();
	~XY();
};

//void setXY(int x_s, int y_s, int x_e, int y_e);
