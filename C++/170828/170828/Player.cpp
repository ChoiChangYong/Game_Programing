#include "Player.h"
#define SIZE_H 20
#define SIZE_V 20



Player::Player(int a, int b)
{
	x = a;
	y = b;
}
Player::Player()
{
}

int Player::GetX()
{
	return x;
}

int Player::GetY()
{
	return y;
}


void Player::SetUp()
{
	y = y - 1;
}

void Player::SetDown()
{
	y = y + 1;
}

void Player::SetLeft()
{
	x = x - 1;
}

void Player::SetRight()
{
	x = x + 1;
}


Player::~Player()
{
}
