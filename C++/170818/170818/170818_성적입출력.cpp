#include <iostream>
using namespace std;

struct grade
{
	int num;
	char name[5];
	int K, E, M;
	int total;
	float ave;
};

int main()
{
	int flag = 0;
	int student = 0;
	int num = 1;

	grade G[256];

	FILE* f;
	grade A[256];
	int total_num = 0;

	int i = 0;


	f = fopen("score.txt", "r");

	if (f == NULL)
	{
		cout << "저장된 파일이 없습니다." << endl;
	}
	else
	{
		cout << "저장된 파일을 불러옵니다." << endl;
	}

	while ((fscanf(f, "%s %d %d %d \n", &A[i].name, &A[i].K, &A[i].E, &A[i].M)) != EOF)
	{
		A[i].total = A[i].K + A[i].E + A[i].M;
		A[i].ave = A[i].total / 3.00;
		i++;
	}
	fclose(f);

	while (1)
	{

		char YN;

		cout << "******************************* 메뉴 ********************************" << endl;
		cout << "1.  입력" << endl;
		cout << "2.  출력" << endl;
		cout << "3.  종료" << endl;
		cout << "4.  파일로 저장" << endl;
		cout << "5.  다시 로드" << endl;

		cin >> flag;

		switch (flag)
		{
		case 1:
			while (1) 
			{
				G[student].num = num;
				cout << "입력하실 학생의 이름을 입력해주세요." << endl;
				cin >> G[student].name;
				cout << "입력하실 학생의 국어점수를 입력해주세요." << endl;
				cin >> G[student].K;
				cout << "입력하실 학생의 영어점수를 입력해주세요." << endl;
				cin >> G[student].E;
				cout << "입력하실 학생의 수학점수를 입력해주세요." << endl;
				cin >> G[student].M;

				num++;
				student++;
				cout << "입력이 완료되었습니다." << endl;
				cout << "입력을 계속 하시겠습니까? [y/n]" << endl;
				cin >> YN;
				if (YN == 'y')
					continue;
				if (YN == 'n')
					break;
			}
			break;

		case 2:


			cout << endl;
			cout << "********************* 학생 성적표를 출력합니다. *********************" << endl;
			cout << endl;
			for(int j=0; j<i; j++)
			{
				cout << "이름 : " << A[j].name << "  국어 : " << A[j].K << "  영어 : " << A[j].E << "  수학 : " << A[j].M << "  총점 : " << A[j].total << "  평균 : " << A[j].ave << endl;
			}
			break;

		case 3:
			cout << endl;
			cout << "****************** 성적관리 프로그램을 종료합니다. ******************" << endl;
			cout << endl;

			fclose(f);
			break;
		case 4:
			f = fopen("score.txt", "a");
			cout << "score.txt 파일이 수정되었습니다." << endl;

			for (int i = 0; i < sizeof(G); i++)
			{
				G[i].total = G[i].K + G[i].E + G[i].M;
				G[i].ave = G[i].total / 3;
				if (G[i].num == 0)
					break;
			}

			for (int i = 0; i < student; i++)
			{
				fprintf(f, "%s %d %d %d \n", G[i].name, G[i].K, G[i].E, G[i].M);
			}
			fclose(f);
			break;
		case 5:
			f = fopen("score.txt", "r");

			i = 0;
			while ((fscanf(f, "%s %d %d %d \n", &A[i].name, &A[i].K, &A[i].E, &A[i].M)) != EOF)
			{
				A[i].total = A[i].K + A[i].E + A[i].M;
				A[i].ave = A[i].total / 3.00;
				i++;
			}
			fclose(f);

			
		}
		if (flag == 3) 
			break;
	}
	return 0;
}


/*
for (int i = 0; i < sizeof(G); i++)
{
G[i].total = G[i].K + G[i].E + G[i].M;
G[i].ave = G[i].total / 3;
if (G[i].num == 0)
break;
}
*/

/*
for (int i = 0; i < student; i++)
{
cout << "*********************************************************************" << endl;
cout << "이름 : " << G[i].name << "  국어 : " << G[i].K << "  영어 : " << G[i].E << "  수학 : " << G[i].M << "  총점 : " << G[i].total << "  평균 : " << G[i].ave << endl;
}
cout << "*********************************************************************" << endl;
cout << endl;
*/

/*
fopen
fclose

fprint
fscanf

fwrite
fread

fseek
*/

//fread
/*
do
{
total_num = fread(A, sizeof(char), 255, f);
if (total_num >= 255)
{
cout << A;
memset(A, 0, 256);
continue;
}
cout << A << endl;

} while (total_num >= 255);
*/
