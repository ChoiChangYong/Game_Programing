#include "Student.h"
#include <iostream>
using namespace std;

int Student::Load(FILE* f)
{
	if (f == 0)
	{
		cout << "저장된 파일이 없습니다." << endl;
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
	cout << "입력하실 학생의 이름을 입력해주세요." << endl;
	cin >> name;
	cout << "입력하실 학생의 국어점수를 입력해주세요." << endl;
	cin >> K;
	cout << "입력하실 학생의 영어점수를 입력해주세요." << endl;
	cin >> E;
	cout << "입력하실 학생의 수학점수를 입력해주세요." << endl;
	cin >> M;
	cout << "입력이 완료되었습니다." << endl;
}

void Student::OutputData()
{
	cout << num << " 이름 : " << name << "  국어 : " << K << "  영어 : " << E << "  수학 : " << M << "  총점 : " << K + E + M << "  평균 : " << (K + E + M) / 3.00 << endl;
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
