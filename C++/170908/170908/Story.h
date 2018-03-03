#pragma once
#include <iostream>
class Story
{
private:
	char szStory[30][50];
	int nTotal_line = 0;
public:
	void Load();
	void Print();
	Story();
	~Story();
};

