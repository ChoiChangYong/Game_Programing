#include "Lee.h"
#define LEE_FLAG 10;

void Lee::Load(FILE* f)
{
	char name_[10] = "";

	fscanf(f, "%d %s %d %d %d %d \n", &num, name_, &korea, &english, &math, &MATH_2);
	name = name_;
}

void Lee::InputData(int n)
{
	Student::InputData(n);
	cout << "�Է��Ͻ� �л��� \"����ll\" ������ �Է����ּ���." << endl;
	cin >> MATH_2;
}

void Lee::OutputData()
{
	Student::OutputData();
	cout << " \"��ll\" : " << MATH_2 << " \"����\" : " << "  " << "  ���� : " << korea + english + math << "  ��� : " << (korea + english + math) / 3.00 << endl;
}

void Lee::Save(FILE* f)
{
	LeeMun_flag = LEE_FLAG;

	fprintf(f, "%d %d %s %d %d %d %d \n", LeeMun_flag, num, name.c_str(), korea, english, math, MATH_2);
}

Lee::Lee()
{
}


Lee::~Lee()
{
}
