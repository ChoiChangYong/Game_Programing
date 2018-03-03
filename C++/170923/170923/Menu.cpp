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
	cout << "******************************* 메뉴 ********************************" << endl;
	cout << "1.  게임시작" << endl;
	cout << "2.  점수판" << endl;
	cout << "3.  종료" << endl;
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
