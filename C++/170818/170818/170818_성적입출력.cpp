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
		cout << "����� ������ �����ϴ�." << endl;
	}
	else
	{
		cout << "����� ������ �ҷ��ɴϴ�." << endl;
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

		cout << "******************************* �޴� ********************************" << endl;
		cout << "1.  �Է�" << endl;
		cout << "2.  ���" << endl;
		cout << "3.  ����" << endl;
		cout << "4.  ���Ϸ� ����" << endl;
		cout << "5.  �ٽ� �ε�" << endl;

		cin >> flag;

		switch (flag)
		{
		case 1:
			while (1) 
			{
				G[student].num = num;
				cout << "�Է��Ͻ� �л��� �̸��� �Է����ּ���." << endl;
				cin >> G[student].name;
				cout << "�Է��Ͻ� �л��� ���������� �Է����ּ���." << endl;
				cin >> G[student].K;
				cout << "�Է��Ͻ� �л��� ���������� �Է����ּ���." << endl;
				cin >> G[student].E;
				cout << "�Է��Ͻ� �л��� ���������� �Է����ּ���." << endl;
				cin >> G[student].M;

				num++;
				student++;
				cout << "�Է��� �Ϸ�Ǿ����ϴ�." << endl;
				cout << "�Է��� ��� �Ͻðڽ��ϱ�? [y/n]" << endl;
				cin >> YN;
				if (YN == 'y')
					continue;
				if (YN == 'n')
					break;
			}
			break;

		case 2:


			cout << endl;
			cout << "********************* �л� ����ǥ�� ����մϴ�. *********************" << endl;
			cout << endl;
			for(int j=0; j<i; j++)
			{
				cout << "�̸� : " << A[j].name << "  ���� : " << A[j].K << "  ���� : " << A[j].E << "  ���� : " << A[j].M << "  ���� : " << A[j].total << "  ��� : " << A[j].ave << endl;
			}
			break;

		case 3:
			cout << endl;
			cout << "****************** �������� ���α׷��� �����մϴ�. ******************" << endl;
			cout << endl;

			fclose(f);
			break;
		case 4:
			f = fopen("score.txt", "a");
			cout << "score.txt ������ �����Ǿ����ϴ�." << endl;

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
cout << "�̸� : " << G[i].name << "  ���� : " << G[i].K << "  ���� : " << G[i].E << "  ���� : " << G[i].M << "  ���� : " << G[i].total << "  ��� : " << G[i].ave << endl;
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
