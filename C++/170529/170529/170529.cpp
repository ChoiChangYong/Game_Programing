// 170529.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
	int i = 0 , j=0, flag=0;
	int num[3];
	int mynum[3];

	srand((unsigned)time(NULL));
	
	for (i = 0; i < 3; i++) {
		num[i] = rand() % 9 + 1;
		flag = 0;

		if (i > 0) {

			while (num[i] == num[i-1]) {
				num[i] = rand() % 9 + 1;
			}
		}
		cout << num[i] << "+" << i << "\n";
	}


    return 0;
}

/*
for (j = 0; j < i; j++) {
	if (num[i] == num[j]) {
		flag = 1;
		break;
	}
}
if (!flag) {
	break;
}
*/