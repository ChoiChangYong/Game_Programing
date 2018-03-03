#pragma once
#include "Student.h"
class Mun :
	public Student
{
private:
	int HISTORY;
public:
	virtual void Load(FILE* f);
	virtual void InputData(int n);
	virtual void OutputData();
	virtual void Save(FILE* f);

	Mun();
	~Mun();
};

