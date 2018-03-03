#include "Score.h"
#include "Score_Total_User.h"
#include <string>
#include <vector>
#include <algorithm>
#include <Windows.h>
#include <conio.h>
using namespace std;



void Score_Total_User::init()
{
	m_pFile = fopen("Score.txt", "r");
	if (m_pFile != 0)
	{
		fscanf(m_pFile, "%d \n", &m_nTotal);

		if (m_nTotal > 0)
		{
			for (int m_nCount = 0; m_nCount < m_nTotal; m_nCount++)
			{
				Score* pscore = new Score();
				pscore->init(m_pFile);
				m_vScore.push_back(pscore);
			}
		}
	}
	fclose(m_pFile);
}

int Score_Total_User::Input()
{
	return 0;
}

void Score_Total_User::Draw()
{
	char c;

	Sort();

	system("cls");
	cout << "순위\t" << "이름\t" << "점수\t" << "단계" << "        일자" << "          시간" << endl;
	for (auto iter = m_vScore.begin(); iter != m_vScore.end(); iter++)
	{
		cout << m_nNum + 1 << "\t";
		(*iter)->Draw_name();
		m_nNum++;
		(*iter)->Draw();
	}
	m_nNum = 0;
	cout << endl;
	cout << "* 돌아갈려면 a키를 입력하시오 *";
	cout << endl;


	while (true)
	{
		cin >> c;
		if (c == 'a')
			break;
	}

}

void Score_Total_User::Update()
{
}

void Score_Total_User::Release()
{
}

void Score_Total_User::AddScore(Score* pScore)
{
	m_vScore.push_back(pScore);
}
void Score_Total_User::Save()
{
	m_pFile = fopen("Score.txt", "w");

	m_nTotal++;

	fprintf(m_pFile, "%d \n", m_nTotal);

	for (auto iter = m_vScore.begin(); iter != m_vScore.end(); iter++)
	{
		(*iter)->Save(m_pFile);
	}
	cout << "점수가 저장되었습니다." << endl;
	Sleep(1000);
	fclose(m_pFile);
}

bool CompareObj(Score* first, Score* second)
{
	return first->getScore() > second->getScore();
}
void Score_Total_User::Sort()
{
	sort(m_vScore.begin(), m_vScore.end(), CompareObj);
}
Score_Total_User::Score_Total_User()
{
	m_nTotal = 0;
	m_nNum = 0;
}


Score_Total_User::~Score_Total_User()
{
}
