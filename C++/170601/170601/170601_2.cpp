#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

/*
int main() {
	char szName[256];
	cin >> szName;

	int len = 0;

	for (int i = 0; i < sizeof(szName); i++) {
		if (szName[i] != NULL) len++;
		else break;
	}

	cout << len << endl;
	return 0;
}
*/
/*
int main() {
	char szIn[256];
	char szOut[256];
	cin >> szIn;

	for (int i = 0; i < sizeof(szIn); i++) {
		szOut[i] = szIn[i];
		if (szIn[i] == NULL) break;
	}
	cout << szOut << endl;
	return 0;
}
*/


int main() {
	int flag = 0;
	int student = 0;
	int num = 1;

	struct grade {
		int num = 0;
		char name[5] = { 0 };
		int K = 0, E = 0, M = 0;
		int total = 0;
		float ave = 0.0f;
	};
	grade G[256];
	while (1) {
		
		char YN;

		cout << "******************************* 메뉴 ********************************" << endl;
		cout << "1.  입력" << endl;
		cout << "2.  출력" << endl;
		cout << "3.  종료" << endl;

		cin >> flag;

		switch (flag) {
		case 1:
			while (1) {
				G[student].num = num;
				cout << "입력하실 학생의 이름을 입력해주세요." << endl;
				cin >> G[student].name;
				cout << "입력하실 학생의 국어점수를 입력해주세요." << endl;
				cin >> G[student].K;
				cout << "입력하실 학생의 영어점수를 입력해주세요." << endl;
				cin >> G[student].E;
				cout << "입력하실 학생의 수학점수를 입력해주세요." << endl;
				cin >> G[student].M;

				num++;
				student++;
				cout << "입력이 완료되었습니다." << endl;
				cout << "입력을 계속 하시겠습니까? [y/n]" << endl;
				cin >> YN;
				if (YN == 'y') continue;
				if (YN == 'n') break;
			}
			break;

		case 2:
			for (int i = 0; i < sizeof(G); i++) {
				G[i].total = G[i].K + G[i].E + G[i].M;
				G[i].ave = G[i].total / 3;
				if (G[i].num == 0) break;
			}
			cout << endl;
			cout << "********************* 학생 성적표를 출력합니다. *********************" << endl;
			cout << endl;

			for (int i = 0; i < student; i++) {
				cout << "*********************************************************************" << endl;
				cout << "이름 : " << G[i].name << "  국어 : " << G[i].K << "  영어 : " << G[i].E << "  수학 : " << G[i].M << "  총점 : " << G[i].total << "  평균 : " << G[i].ave << endl;
			}
			cout << "*********************************************************************" << endl;
			cout << endl;

			break;

		case 3:
			cout << endl;
			cout << "****************** 성적관리 프로그램을 종료합니다. ******************" << endl;
			cout << endl;
			break;
		}
		if (flag == 3) break;
	}
	return 0;
}
