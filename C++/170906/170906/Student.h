#pragma once
#include <iostream>
#include <string>
using namespace std;

class Student
{
protected:
	int num;
	string name;
	int korea;
	int english;
	int math;

	int LeeMun_flag;
public:
	virtual void Load(FILE* f);
	virtual void InputData(int n);
	virtual void OutputData();
	virtual void Save(FILE* f);

	Student();
	~Student();
};

