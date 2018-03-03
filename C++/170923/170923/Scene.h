#pragma once
class Scene
{
public:
	bool bGameOver_flag;
protected:
	int nMenu_flag;
	int nStory_flag;
public:
	void gotoxy(int y, int x);
	virtual void init() = 0;
	virtual int Input() = 0;
	virtual void Draw() = 0;
	virtual void Update() = 0;
	virtual void Release() = 0;

	Scene();
	~Scene();
};

