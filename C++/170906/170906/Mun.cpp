#include "Mun.h"
#define MUN_FLAG 20;

void Mun::Load(FILE* f)
{
	char name_[10] = "";

	fscanf(f, "%d %s %d %d %d %d \n", &num, name_, &korea, &english, &math, &HISTORY);
	name = name_;
}

void Mun::InputData(int n)
{
	Student::InputData(n);
	cout << "�Է��Ͻ� �л��� \"����\" ������ �Է����ּ���." << endl;
	cin >> HISTORY;
}

void Mun::OutputData()
{
	Student::OutputData();
	cout << " \"��ll\" : " << "  " << " \"����\" : " << HISTORY << "  ���� : " << korea + english + math << "  ��� : " << (korea + english + math) / 3.00 << endl;
}

void Mun::Save(FILE* f)
{
	LeeMun_flag = MUN_FLAG;

	fprintf(f, "%d %d %s %d %d %d %d \n", LeeMun_flag, num, name.c_str(), korea, english, math, HISTORY);
}

Mun::Mun()
{
}


Mun::~Mun()
{
}
