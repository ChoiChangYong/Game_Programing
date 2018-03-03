#include <iostream>
#pragma once

class Student;
class Grade
{
private:
	Student* s;

	FILE* f;

	int i = 0;

	int num = 1;
	int student = 0;

public:
	void init(Student* s_);

	void InputData();
	void OutputData();
	void End();
	void Save();

	Grade();
	~Grade();
};

