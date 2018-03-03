#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

int main()
{
	int input = 0;
	cin >> input;

	int* arr = new int[input];
	cout << "입력하세요." << endl;

	for (int i = 0; i < input; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < input; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;

	delete [] arr;
	return 0;
}