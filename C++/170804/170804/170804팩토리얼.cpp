#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

int factorial(int n)
{
	if(n != 1)
	{
		n = n * factorial(n - 1);
	}
	return n;
}
int main()
{
	int num = 0;

	cin >> num;

	cout << num << "! = " << factorial(num) << endl;

	return 0;
}