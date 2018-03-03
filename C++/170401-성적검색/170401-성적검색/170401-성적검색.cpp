#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

class items
{
	public:
	string name;
	int score;
	explicit items(string st, int sc) {
		name = st;
		score = sc;
	}
	void operator() (string st, int sc)
	{
		name = st;
		score = sc;
	}
};

void name_(multimap<string, vector<items>::iterator> st_sc) {
	cout << endl;

	string name;
	cout << "�̸� �Է� : ";
	cin >> name;

	for (auto iter = st_sc.begin(); iter != st_sc.end(); ++iter) {
		if (iter->second->name == name)
			cout << "<�˻� ���> " << "�̸� : " << iter->second->name << " ���� : " << iter->second->score << endl;
		else if (iter == st_sc.end() && iter->second->name != name)
			cout << "�˻� ����� �����ϴ�!" << endl;
	}
	cout << endl;
	cout << endl;
}
void score_(multimap<string, vector<items>::iterator> st_sc) {
	cout << endl;

	int score;
	cout << "���� �Է� : ";
	cin >> score;

	for (auto iter = st_sc.begin(); iter != st_sc.end(); ++iter) {
		if (iter->second->score == score)
			cout << "<�˻� ���> " << "�̸� : " << iter->second->name << " ���� : " << iter->second->score << endl;
		else if (iter == st_sc.end() && iter->second->score != score)
			cout << "�˻� ����� �����ϴ�!" << endl;
	}
	cout << endl;
	cout << endl;
}



bool greaterName(items& first, items& second)
{
	return first.name < second.name;
}
bool lessScore(items& first, items& second)
{
	return first.score > second.score;
}



void name_sort(vector<items> item) {
	cout << endl;
	cout << "�̸� ���� �������� �����մϴ�." << endl;
	sort(item.begin(), item.end(), greaterName);
	
	int i = 1;
	for (auto iter = item.begin(); iter != item.end(); ++iter) {
		cout << i << ". " << "�̸� : " << iter->name << " ���� : " << iter->score << endl;
		i++;
	}
	cout << endl;
	cout << endl;
}

void score_sort(vector<items> item) {
	cout << endl;
	cout << "���� ���� �������� �����մϴ�." << endl;
	sort(item.begin(), item.end(), lessScore);

	int i = 1;
	for (auto iter = item.begin(); iter != item.end(); ++iter) {
		cout << i << ". " << "�̸� : " << iter->name << " ���� : " << iter->score << endl;
		i++;
	}
	cout << endl;
	cout << endl;
}
int main()
{
	multimap<string, vector<items>::iterator> st_sc;
	string student;
	int score;

	cout << "==========�������� ���α׷��� �����մϴ�.==========" << endl;
	cout << "==========�̸�, ������ ������ �Է��մϴ�.==========" << endl;
	cout << "=======(�Է��� ��ġ�÷��� -1�� �Է����ּ���.)======" << endl;
	cout << endl;
	cout << endl;

/*	while (1) {
		cout << "�̸� �Է� : ";
		cin >> student;
		if (student == "-1") break;
		cout << "���� �Է� : ";
		cin >> score;
		if (score == -1) break;

		st_sc.insert(pair<string, int>(student, score));
	}
	*/

	vector<items> item;
	item.push_back(items("��OO", 80));
	item.push_back(items("��OO", 90));
	item.push_back(items("��OO", 100));
	item.push_back(items("��OO", 70));
	item.push_back(items("��OO", 80));
	item.push_back(items("��OO", 90));
	item.push_back(items("��OO", 70));
	item.push_back(items("��OO", 100));
	vector<items>::iterator iter_v;

	for (auto iter_v = item.begin(); iter_v != item.end(); ++iter_v) {
		st_sc.insert(pair< string, vector<items>::iterator >(iter_v->name, iter_v));
	}
	cout << endl;
	cout << endl;
	cout << "==============�ڵ��Է��� �Ϸ�Ǿ����ϴ�.===============" << endl;
	cout << "=============�� �Էµ� �ڷ�� " << st_sc.size() << "�� �Դϴ�.==============" << endl;
	cout << endl;
	cout << endl;
	int i = 1;
	for (auto iter = st_sc.begin(); iter != st_sc.end(); ++iter) {
		cout << i << ". " << "�̸� : " << iter->second->name << " ���� : " << iter->second->score << endl;
		i++;
	}
	cout << endl;
	cout << endl;

	i = 0;

	int select = 0;
	while (select != -1) {
		cout << "========�̸����� �˻��Ͻ÷��� 1�� �Է����ּ���.=========" << endl;
		cout << "=========������ �˻��Ͻ÷��� 2�� �Է����ּ���.==========" << endl;
		cout << "========�̸����� �����Ͻ÷��� 3�� �Է����ּ���.=========" << endl;
		cout << "=========������ �����Ͻ÷��� 4�� �Է����ּ���.==========" << endl;
		cout << "=============�����÷��� -1�� �Է����ּ���.==============" << endl;
		cout << endl;
		cout << endl;
		cout << "��� �Է� : ";
		cin >> select;

		switch (select)
		{
		case 1:
			name_(st_sc);break;
		case 2:
			score_(st_sc); break;
		case 3:
			name_sort(item); break;
		case 4:
			score_sort(item); break;
		default:
			cout << select << endl;
			cout << "��ɾ �߸� �Է��ϼ̽��ϴ�." << endl;
			cin.clear();
			cin.ignore();
			break;
		}
		cin.clear();
		cin.ignore();
	}


	return 0;
}