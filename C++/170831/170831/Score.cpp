#include <iostream>
#include "Student.h"
using namespace std;

int main()
{
	Student Input_S[256];
	Student Load_S[256];
	FILE* f;

	int flag = 0;
	int count = 0;
	int total = 0;

	cout << "저장된 파일을 불러옵니다." << endl;
	f = fopen("score.txt", "r");
	int i = 0;
	while ((Load_S[i].Load(f)) != EOF)
	{
		i++;
	}
	total = Load_S[i - 1].Getnum();

	fclose(f);
	
	while (1)
	{
		cout << "******************************* 메뉴 ********************************" << endl;
		cout << "1.  다시 로드" << endl;
		cout << "2.  입력" << endl;
		cout << "3.  출력" << endl;
		cout << "4.  파일로 저장" << endl;
		cout << "5.  종료" << endl;

		cin >> flag;

		switch (flag)
		{
		case 1:
			cout << "저장된 파일을 불러옵니다." << endl;
			f = fopen("score.txt", "r");
			i = 0;
			while ((Load_S[i].Load(f)) != EOF)
			{
				i++;
			}
			total = Load_S[i - 1].Getnum();

			fclose(f);
			break;
		case 2:
			while (1)
			{
				char YN;

				total++;
				Input_S[count].InputData(total);
				count++;

				cout << "입력을 계속 하시겠습니까? [y/n]" << endl;
				cin >> YN;
				if (YN == 'y')
					continue;
				if (YN == 'n')
					break;
			}
			break;
		case 3:
			cout << endl;
			cout << "********************* 학생 성적표를 출력합니다. *********************" << endl;
			cout << endl;
			for (int j = 0; j < i; j++)
			{
				Load_S[j].OutputData();
			}
			break;
		case 4:
			f = fopen("score.txt", "a");
			cout << "score.txt 파일이 저장되었습니다." << endl;

			for (int j = 0; j < count; j++)
			{
				Input_S[j].Save(f);
			}

			fclose(f);
			break;
		case 5:
			cout << endl;
			cout << "****************** 성적관리 프로그램을 종료합니다. ******************" << endl;
			cout << endl;

			break;
		default:
			break;
		}
		if (flag == 5)
			break;
	}
	return 0;
}