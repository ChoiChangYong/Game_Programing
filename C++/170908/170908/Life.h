#pragma once
class Total_Score;
class Score;
class Life
{
private:
	int m_nLife;
	Total_Score* pScore;
public:
	int getLife();
	void Plus();
	void Minus(Score* p_score);
	void Print();
	Life();
	~Life();
};

