#include <iostream>
#include "Grade.h"
#include "Student.h"
using namespace std;

void Grade::init(Student * s_)
{
	f = fopen("score.txt", "r");

	s = s_;
	s->Load(f);

	fclose(f);
}


void Grade::Load_G()
{
	int i = 0;

	S->Load(f);
}


void Grade::InputData()
{
	Input_G[student].num = num;
	cout << "�Է��Ͻ� �л��� �̸��� �Է����ּ���." << endl;
	cin >> Input_G[student].name;
	cout << "�Է��Ͻ� �л��� ���������� �Է����ּ���." << endl;
	cin >> Input_G[student].K;
	cout << "�Է��Ͻ� �л��� ���������� �Է����ּ���." << endl;
	cin >> Input_G[student].E;
	cout << "�Է��Ͻ� �л��� ���������� �Է����ּ���." << endl;
	cin >> Input_G[student].M;

	num++;
	student++;
	cout << "�Է��� �Ϸ�Ǿ����ϴ�." << endl;
}

void Grade::OutputData()
{
	cout << endl;
	cout << "********************* �л� ����ǥ�� ����մϴ�. *********************" << endl;
	cout << endl;
	for (int j = 0; j<i; j++)
	{
		cout << "�̸� : " << Load_G[j].name << "  ���� : " << Load_G[j].K << "  ���� : " << Load_G[j].E << "  ���� : " << Load_G[j].M << "  ���� : " << Load_G[i].K + Load_G[i].E + Load_G[i].M << "  ��� : " << (Load_G[i].K + Load_G[i].E + Load_G[i].M) / 3.00 << endl;
	}
}

void Grade::End()
{
	cout << endl;
	cout << "****************** �������� ���α׷��� �����մϴ�. ******************" << endl;
	cout << endl;

	fclose(f);
}

void Grade::Save()
{
	f = fopen("score.txt", "a");
	cout << "score.txt ������ ����Ǿ����ϴ�." << endl;

	for (int i = 0; i < student; i++)
	{
		fprintf(f, "%s %d %d %d \n", Input_G[i].name, Input_G[i].K, Input_G[i].E, Input_G[i].M);
	}
	fclose(f);
}

Grade::Grade()
{
}


Grade::~Grade()
{
}
