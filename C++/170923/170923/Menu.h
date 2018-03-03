#pragma once
#include "Scene.h"
class Menu :
	public Scene
{
private : 

public:
	virtual void init();
	virtual int Input();
	virtual void Draw();
	virtual void Update();
	virtual void Release();
	Menu();
	~Menu();
};

