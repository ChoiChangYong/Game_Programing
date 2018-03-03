#pragma once
#include "Student.h"
class Lee :
	public Student
{
private:
	int MATH_2;
public:
	virtual void Load(FILE* f);
	virtual void InputData(int n);
	virtual void OutputData();
	virtual void Save(FILE* f);

	Lee();
	~Lee();
};

