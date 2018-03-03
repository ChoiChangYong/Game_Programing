#pragma once
class Player
{
private:
	int x;
	int y;

public:
	Player(int a, int b);

	int GetX();
	int GetY();

	void SetUp();
	void SetDown();
	void SetLeft();
	void SetRight();

	Player();
	~Player();
};

