#include "Menu.h"
#include <iostream>
using namespace std;



void Menu::init()
{
}

int Menu::Input()
{
	cin >> nMenu_flag;
	return nMenu_flag;
}

void Menu::Draw()
{
	cout << "******************************* �޴� ********************************" << endl;
	cout << "1.  ���ӽ���" << endl;
	cout << "2.  ������" << endl;
	cout << "3.  ����" << endl;
}

void Menu::Update()
{
}

void Menu::Release()
{
}

Menu::Menu()
{
}


Menu::~Menu()
{
}
