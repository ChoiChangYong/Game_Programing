#include "Student.h"
#include <iostream>
using namespace std;

int Student::Load(FILE* f)
{
	if (f == 0)
	{
		cout << "����� ������ �����ϴ�." << endl;
	}
	else
	{
		result = fscanf(f, "%d %s %d %d %d \n", &num, &name, &K, &E, &M);
	}
	return result;
}

void Student::InputData(int n)
{
	num = n;
	cout << "�Է��Ͻ� �л��� �̸��� �Է����ּ���." << endl;
	cin >> name;
	cout << "�Է��Ͻ� �л��� ���������� �Է����ּ���." << endl;
	cin >> K;
	cout << "�Է��Ͻ� �л��� ���������� �Է����ּ���." << endl;
	cin >> E;
	cout << "�Է��Ͻ� �л��� ���������� �Է����ּ���." << endl;
	cin >> M;
	cout << "�Է��� �Ϸ�Ǿ����ϴ�." << endl;
}

void Student::OutputData()
{
	cout << num << " �̸� : " << name << "  ���� : " << K << "  ���� : " << E << "  ���� : " << M << "  ���� : " << K + E + M << "  ��� : " << (K + E + M) / 3.00 << endl;
}

void Student::Save(FILE* f)
{
	fprintf(f, "%d %s %d %d %d \n", num, name, K, E, M);
}

int Student::Getnum()
{
	return num;
}

Student::Student()
{
}

Student::~Student()
{
}
