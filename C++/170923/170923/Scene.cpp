#include "Scene.h"
#include <Windows.h>



void Scene::gotoxy(int y, int x)
{
	COORD Pos = { y - 1, x - 1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

Scene::Scene()
{
	nMenu_flag = 0;
	nStory_flag = 0;
	bGameOver_flag = false;
}


Scene::~Scene()
{
}
