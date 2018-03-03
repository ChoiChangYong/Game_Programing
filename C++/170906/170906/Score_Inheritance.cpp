#include "Student.h"
#include "Lee.h"
#include "Mun.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;
#define LEE_FLAG 10
#define MUN_FLAG 20

int main()
{
	vector<Student*> vec;
	vec.reserve(1024);

	FILE* f;

	int flag = 0;
	int flag_student = 0;

	int LeeMun_flag = 0;
	int total = 0;
	int count = 0;

	f = fopen("score.txt", "r");
	if (f == 0)
		cout << "������ �������� �ʽ��ϴ�." << endl;
	else
	{
		cout << "����� ������ �ҷ��ɴϴ�." << endl;

		fscanf(f, "%d \n", &total);

		while (total != 0 && count != total)
		{
			fscanf(f, "%d ", &LeeMun_flag);
			if (LeeMun_flag == LEE_FLAG)
			{
				Lee* L_student = new Lee();
				L_student->Load(f);
				vec.push_back(L_student);
			}
			else if (LeeMun_flag == MUN_FLAG)
			{
				Mun* M_student = new Mun();
				M_student->Load(f);
				vec.push_back(M_student);
			}
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
				Lee* L_student;
				Mun* M_student;
				char YN;

				cout << "1.  �̰�" << endl;
				cout << "2.  ����" << endl;

				cin >> flag_student;

				switch (flag_student)
				{
				case 1:
					L_student = new Lee();
					vec.push_back(L_student);

					vec[count]->InputData(count + 1);
					count++;
					break;
				case 2:
					M_student = new Mun();
					vec.push_back(M_student);

					vec[count]->InputData(count + 1);
					count++;
					break;
				default :
					break;

				}
				cout << "�Է��� �Ϸ�Ǿ����ϴ�." << endl;

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
			for (auto iter = vec.begin(); iter != vec.end(); iter++)
			{
				Lee* pTemp = dynamic_cast<Lee*>(*iter);
				if (pTemp != NULL)
					pTemp->OutputData();
			}
			for (auto iter = vec.begin(); iter != vec.end(); iter++)
			{
				Mun* pTemp = dynamic_cast<Mun*>(*iter);
				if (pTemp != NULL)
					pTemp->OutputData();
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

			for (auto iter = vec.begin(); iter != vec.end(); iter++)
			{
				(*iter)->Save(f);
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

	for (auto iter = vec.begin(); iter != vec.end(); iter++)
	{
		delete (*iter);
	}
	return 0;

}

/*
vector<int> vec;
vec.reserve(1024);
vec.push_back(1); // vec[0] = 1;
vec.push_back(2);
vec.push_back(3);

vec[0] = 0;
int c = vec[0];

for (int i = 0; i < vec.size(); i++)
cout << vec[i] << endl;
for (auto iter = vec.begin(); iter != vec.end(); iter++)
cout << *iter << endl;
*/

/*
for (int i = 0; i < total; i++)
{
vec[i]->Save(f);
}
*/
