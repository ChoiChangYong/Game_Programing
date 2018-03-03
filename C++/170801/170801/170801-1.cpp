#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
/*
void my_strstr1(char* input, char find) {
	int size = strlen(input);
	for (int i = 0; i < size; i++) {
		if (*input != find) input++;
		else {
			cout << input;
			break;
		}
	}
	cout << endl;
}*/

char* my_strstr2(char* input, char* find) {
	int size_input = strlen(input);
	int size_find = strlen(find);
	char* point;

	for (int i = 0; i < size_input+1; i++) {
		if (*input == NULL) {
			return NULL;
		}

		if (*input != find[0]) {
			input++;
		}
		else {
			point = input;

			for (int j = 0; j < size_find; j++) {
				if (input[0] != find[0]) {
					return NULL;
				}
				input++;
				find++;
			}
			break;
		}
	}
	return point;
}
int main() {
	char a[20] = "abcdefg";
	char c[20];

	cout << "비교할 문자열를 입력하세요." << endl;
	cin >> c;

	cout << my_strstr2(a, c) << endl;

	return 0;
}