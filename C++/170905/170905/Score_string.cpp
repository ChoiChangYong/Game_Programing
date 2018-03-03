#include <iostream>
#include "Student.h"
#include <string>

using namespace std;

int main()
{
	Student Load_S[256];
	FILE* f;

	int flag = 0;
	int total = 0;
	int count = 0;
	char name_sub[10] = "";

	f = fopen("score.txt", "r");
	if(f==0)
		cout << "파일이 존재하지 않습니다." << endl;
	else
	{
		cout << "저장된 파일을 불러옵니다." << endl;

		fscanf(f, "%d \n", &total);

		while (total != 0 && count != total)
		{
			Load_S[count].Load(f, name_sub);
			count++;
		}
		if (total == 0)
			cout << "파일에 내용이 없습니다." << endl;

		fclose(f);
	}
	while (1)
	{
		cout << endl;
		cout << "******************************* 메뉴 ********************************" << endl;
		cout << "1.  입력" << endl;
		cout << "2.  출력" << endl;
		cout << "3.  종료" << endl;
		cout << "4.  파일로 저장" << endl;

		cin >> flag;

		switch (flag)
		{
		case 1:
			while (1)
			{
				char YN;

				Load_S[count].InputData(count + 1);
				count++;

				cout << "입력을 계속 하시겠습니까? [y/n]" << endl;
				cin >> YN;
				if (YN == 'y')
					continue;
				if (YN == 'n')
					break;
			}
			total = count;
			break;
		case 2:
			cout << "********************* 학생 성적표를 출력합니다. *********************" << endl;
			cout << endl;
			for (int i = 0; i < total; i++)
			{
				Load_S[i].OutputData();
			}
			break;
		case 3:
			cout << endl;
			cout << "****************** 성적관리 프로그램을 종료합니다. ******************" << endl;
			cout << endl;
			break;
		case 4:
			f = fopen("score.txt", "w");

			fprintf(f, "%d \n", total);
			for (int i = 0; i < total; i++)
			{
				Load_S[i].Save(f);
			}
			cout << "score.txt 파일이 저장되었습니다." << endl;

			fclose(f);
			break;
		default:
			break;
		}
		if (flag == 3)
			break;
	}
	return 0;
}