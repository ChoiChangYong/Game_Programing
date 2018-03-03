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
	cout << "입력하실 학생의 이름을 입력해주세요." << endl;
	cin >> Input_G[student].name;
	cout << "입력하실 학생의 국어점수를 입력해주세요." << endl;
	cin >> Input_G[student].K;
	cout << "입력하실 학생의 영어점수를 입력해주세요." << endl;
	cin >> Input_G[student].E;
	cout << "입력하실 학생의 수학점수를 입력해주세요." << endl;
	cin >> Input_G[student].M;

	num++;
	student++;
	cout << "입력이 완료되었습니다." << endl;
}

void Grade::OutputData()
{
	cout << endl;
	cout << "********************* 학생 성적표를 출력합니다. *********************" << endl;
	cout << endl;
	for (int j = 0; j<i; j++)
	{
		cout << "이름 : " << Load_G[j].name << "  국어 : " << Load_G[j].K << "  영어 : " << Load_G[j].E << "  수학 : " << Load_G[j].M << "  총점 : " << Load_G[i].K + Load_G[i].E + Load_G[i].M << "  평균 : " << (Load_G[i].K + Load_G[i].E + Load_G[i].M) / 3.00 << endl;
	}
}

void Grade::End()
{
	cout << endl;
	cout << "****************** 성적관리 프로그램을 종료합니다. ******************" << endl;
	cout << endl;

	fclose(f);
}

void Grade::Save()
{
	f = fopen("score.txt", "a");
	cout << "score.txt 파일이 저장되었습니다." << endl;

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
