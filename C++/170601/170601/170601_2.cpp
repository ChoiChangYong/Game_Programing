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

		cout << "******************************* �޴� ********************************" << endl;
		cout << "1.  �Է�" << endl;
		cout << "2.  ���" << endl;
		cout << "3.  ����" << endl;

		cin >> flag;

		switch (flag) {
		case 1:
			while (1) {
				G[student].num = num;
				cout << "�Է��Ͻ� �л��� �̸��� �Է����ּ���." << endl;
				cin >> G[student].name;
				cout << "�Է��Ͻ� �л��� ���������� �Է����ּ���." << endl;
				cin >> G[student].K;
				cout << "�Է��Ͻ� �л��� ���������� �Է����ּ���." << endl;
				cin >> G[student].E;
				cout << "�Է��Ͻ� �л��� ���������� �Է����ּ���." << endl;
				cin >> G[student].M;

				num++;
				student++;
				cout << "�Է��� �Ϸ�Ǿ����ϴ�." << endl;
				cout << "�Է��� ��� �Ͻðڽ��ϱ�? [y/n]" << endl;
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
			cout << "********************* �л� ����ǥ�� ����մϴ�. *********************" << endl;
			cout << endl;

			for (int i = 0; i < student; i++) {
				cout << "*********************************************************************" << endl;
				cout << "�̸� : " << G[i].name << "  ���� : " << G[i].K << "  ���� : " << G[i].E << "  ���� : " << G[i].M << "  ���� : " << G[i].total << "  ��� : " << G[i].ave << endl;
			}
			cout << "*********************************************************************" << endl;
			cout << endl;

			break;

		case 3:
			cout << endl;
			cout << "****************** �������� ���α׷��� �����մϴ�. ******************" << endl;
			cout << endl;
			break;
		}
		if (flag == 3) break;
	}
	return 0;
}
