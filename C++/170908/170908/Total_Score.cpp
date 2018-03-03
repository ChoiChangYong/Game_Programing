#include "Total_Score.h"
#include "Score.h"
#include <iostream>
#include <vector>
#include <stdlib.h>
using namespace std;



void Total_Score::Load()
{
	m_pF = fopen("score.txt", "r");
	if (m_pF != 0)
	{
		fscanf(m_pF, "%d \n", &m_nTotal);

		while (m_nTotal != 0 && m_nCount != m_nTotal)
		{
			Score* pscore = new Score();
			pscore->Load(m_pF);
			vScore.push_back(pscore);

			Score_sort[m_nCount] = pscore->getScore();

			m_nCount++;
		}
		fclose(m_pF);
	}
}

void Total_Score::OutputData()
{
	for (auto iter = vScore.begin(); iter != vScore.end(); iter++)
	{
		cout << m_nNum+1 << "   ";
		(*iter)->OutputData_name();
		cout << Score_sort[m_nNum] << "점   ";
		m_nNum++;
		(*iter)->OutputData();
	}
}
void Total_Score::Save(Score* p_score, char* p_chName)
{
	m_pF = fopen("score.txt", "w");

	m_nTotal++;
	fprintf(m_pF, "%d \n", m_nTotal);

	for (auto iter = vScore.begin(); iter != vScore.end(); iter++)
	{
		(*iter)->Save(m_pF, false, p_chName);
	}
	p_score->Save(m_pF, true, p_chName);
	cout << "점수가 저장되었습니다." << endl;

	fclose(m_pF);
}
int comparisonFunctionInt(const void *a, const void *b) {

	if (*(int*)b <  *(int*)a) return -1;
	if (*(int*)a == *(int*)b) return  0;

	return 1;
}
void Total_Score::Sort()
{
	qsort((void *)Score_sort, m_nCount, sizeof(Score_sort[0]), comparisonFunctionInt);
}
Total_Score::Total_Score()
{
	vScore.reserve(1024);
	m_nTotal = 0;
	m_nCount = 0;
	m_nNum = 0;
	memset(Score_sort, 0, sizeof(50));
}


Total_Score::~Total_Score()
{
}
