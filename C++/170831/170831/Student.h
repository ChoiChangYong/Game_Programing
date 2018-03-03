#include <iostream>
using namespace std;
#pragma once
class Student
{
private:
	int num;
	char name[5];
	int K, E, M;

	int result;
public:

	int Load(FILE* f);
	void InputData(int n);
	void OutputData();
	void Save(FILE* f);

	int Getnum();
	Student();
	~Student();
};

