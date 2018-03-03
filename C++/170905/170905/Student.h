#pragma once
#include <iostream>
#include <string>
using namespace std;

class Student
{
private:
	int num;
	string name;
	int korea;
	int english;
	int math;
public:
	void Load(FILE* f, char* name_);
	void InputData(int n);
	void OutputData();
	void Save(FILE* f);

	Student();
	~Student();
};

