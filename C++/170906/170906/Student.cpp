#include "Student.h"
#include <iostream>
#include <string>
using namespace std;

void Student::Load(FILE* f)
{
	char name_[10] = "";

	fscanf(f, "%d %s %d %d %d \n", &num, name_, &korea, &english, &math);
	name = name_;
}

void Student::InputData(int n)
{
	num = n;
	cout << "�Է��Ͻ� �л��� �̸��� �Է����ּ���." << endl;
	cin >> name;
	cout << "�Է��Ͻ� �л��� ���������� �Է����ּ���." << endl;
	cin >> korea;
	cout << "�Է��Ͻ� �л��� ���������� �Է����ּ���." << endl;
	cin >> english;
	cout << "�Է��Ͻ� �л��� ���������� �Է����ּ���." << endl;
	cin >> math;
}

void Student::OutputData()
{
	cout << num << " �̸� : " << name << "  ���� : " << korea << "  ���� : " << english << "  ���� : " << math;
}

void Student::Save(FILE* f)
{
	fprintf(f, "%d %s %d %d %d \n", num, name.c_str(), korea, english, math);
}

Student::Student()
{
}

Student::~Student()
{
}
