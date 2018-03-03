#include <math.h>
#include <iostream>
using namespace std; 

float GetDistance(int x1, int y1, int x2, int y2)
{
	return sqrtf(powf(x2 - x1, 2) + powf(y2 - y1, 2));
}
int main()
{
	//가로 3, 세로 4
	cout << GetDistance(1, 1, 4, 5) << endl;
	return 0;
}