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

	cout << "����� ������ �ҷ��ɴϴ�." << endl;
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
		cout << "******************************* �޴� ********************************" << endl;
		cout << "1.  �ٽ� �ε�" << endl;
		cout << "2.  �Է�" << endl;
		cout << "3.  ���" << endl;
		cout << "4.  ���Ϸ� ����" << endl;
		cout << "5.  ����" << endl;

		cin >> flag;

		switch (flag)
		{
		case 1:
			cout << "����� ������ �ҷ��ɴϴ�." << endl;
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

				cout << "�Է��� ��� �Ͻðڽ��ϱ�? [y/n]" << endl;
				cin >> YN;
				if (YN == 'y')
					continue;
				if (YN == 'n')
					break;
			}
			break;
		case 3:
			cout << endl;
			cout << "********************* �л� ����ǥ�� ����մϴ�. *********************" << endl;
			cout << endl;
			for (int j = 0; j < i; j++)
			{
				Load_S[j].OutputData();
			}
			break;
		case 4:
			f = fopen("score.txt", "a");
			cout << "score.txt ������ ����Ǿ����ϴ�." << endl;

			for (int j = 0; j < count; j++)
			{
				Input_S[j].Save(f);
			}

			fclose(f);
			break;
		case 5:
			cout << endl;
			cout << "****************** �������� ���α׷��� �����մϴ�. ******************" << endl;
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