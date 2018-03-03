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
		cout << "������ �������� �ʽ��ϴ�." << endl;
	else
	{
		cout << "����� ������ �ҷ��ɴϴ�." << endl;

		fscanf(f, "%d \n", &total);

		while (total != 0 && count != total)
		{
			Load_S[count].Load(f, name_sub);
			count++;
		}
		if (total == 0)
			cout << "���Ͽ� ������ �����ϴ�." << endl;

		fclose(f);
	}
	while (1)
	{
		cout << endl;
		cout << "******************************* �޴� ********************************" << endl;
		cout << "1.  �Է�" << endl;
		cout << "2.  ���" << endl;
		cout << "3.  ����" << endl;
		cout << "4.  ���Ϸ� ����" << endl;

		cin >> flag;

		switch (flag)
		{
		case 1:
			while (1)
			{
				char YN;

				Load_S[count].InputData(count + 1);
				count++;

				cout << "�Է��� ��� �Ͻðڽ��ϱ�? [y/n]" << endl;
				cin >> YN;
				if (YN == 'y')
					continue;
				if (YN == 'n')
					break;
			}
			total = count;
			break;
		case 2:
			cout << "********************* �л� ����ǥ�� ����մϴ�. *********************" << endl;
			cout << endl;
			for (int i = 0; i < total; i++)
			{
				Load_S[i].OutputData();
			}
			break;
		case 3:
			cout << endl;
			cout << "****************** �������� ���α׷��� �����մϴ�. ******************" << endl;
			cout << endl;
			break;
		case 4:
			f = fopen("score.txt", "w");

			fprintf(f, "%d \n", total);
			for (int i = 0; i < total; i++)
			{
				Load_S[i].Save(f);
			}
			cout << "score.txt ������ ����Ǿ����ϴ�." << endl;

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