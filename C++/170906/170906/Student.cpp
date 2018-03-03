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
	cout << "입력하실 학생의 이름을 입력해주세요." << endl;
	cin >> name;
	cout << "입력하실 학생의 국어점수를 입력해주세요." << endl;
	cin >> korea;
	cout << "입력하실 학생의 영어점수를 입력해주세요." << endl;
	cin >> english;
	cout << "입력하실 학생의 수학점수를 입력해주세요." << endl;
	cin >> math;
}

void Student::OutputData()
{
	cout << num << " 이름 : " << name << "  국어 : " << korea << "  영어 : " << english << "  수학 : " << math;
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
