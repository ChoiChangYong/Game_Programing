#pragma once
#include "Scene.h"
class Story :
	public Scene
{
private:
	char szStory[30][50];
	int nTotal_line;
public:
	virtual void init();
	virtual int Input();
	virtual void Draw();
	virtual void Update();
	virtual void Release();
	Story();
	~Story();
};

