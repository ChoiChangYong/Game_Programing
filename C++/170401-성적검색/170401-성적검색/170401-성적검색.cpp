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
	cout << "이름 입력 : ";
	cin >> name;

	for (auto iter = st_sc.begin(); iter != st_sc.end(); ++iter) {
		if (iter->second->name == name)
			cout << "<검색 결과> " << "이름 : " << iter->second->name << " 성적 : " << iter->second->score << endl;
		else if (iter == st_sc.end() && iter->second->name != name)
			cout << "검색 결과가 없습니다!" << endl;
	}
	cout << endl;
	cout << endl;
}
void score_(multimap<string, vector<items>::iterator> st_sc) {
	cout << endl;

	int score;
	cout << "점수 입력 : ";
	cin >> score;

	for (auto iter = st_sc.begin(); iter != st_sc.end(); ++iter) {
		if (iter->second->score == score)
			cout << "<검색 결과> " << "이름 : " << iter->second->name << " 성적 : " << iter->second->score << endl;
		else if (iter == st_sc.end() && iter->second->score != score)
			cout << "검색 결과가 없습니다!" << endl;
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
	cout << "이름 기준 오름차순 정렬합니다." << endl;
	sort(item.begin(), item.end(), greaterName);
	
	int i = 1;
	for (auto iter = item.begin(); iter != item.end(); ++iter) {
		cout << i << ". " << "이름 : " << iter->name << " 성적 : " << iter->score << endl;
		i++;
	}
	cout << endl;
	cout << endl;
}

void score_sort(vector<items> item) {
	cout << endl;
	cout << "점수 기준 내림차순 정렬합니다." << endl;
	sort(item.begin(), item.end(), lessScore);

	int i = 1;
	for (auto iter = item.begin(); iter != item.end(); ++iter) {
		cout << i << ". " << "이름 : " << iter->name << " 성적 : " << iter->score << endl;
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

	cout << "==========성적관리 프로그램을 시작합니다.==========" << endl;
	cout << "==========이름, 점수를 순으로 입력합니다.==========" << endl;
	cout << "=======(입력을 마치시려면 -1을 입력해주세요.)======" << endl;
	cout << endl;
	cout << endl;

/*	while (1) {
		cout << "이름 입력 : ";
		cin >> student;
		if (student == "-1") break;
		cout << "점수 입력 : ";
		cin >> score;
		if (score == -1) break;

		st_sc.insert(pair<string, int>(student, score));
	}
	*/

	vector<items> item;
	item.push_back(items("최OO", 80));
	item.push_back(items("이OO", 90));
	item.push_back(items("장OO", 100));
	item.push_back(items("조OO", 70));
	item.push_back(items("김OO", 80));
	item.push_back(items("강OO", 90));
	item.push_back(items("유OO", 70));
	item.push_back(items("고OO", 100));
	vector<items>::iterator iter_v;

	for (auto iter_v = item.begin(); iter_v != item.end(); ++iter_v) {
		st_sc.insert(pair< string, vector<items>::iterator >(iter_v->name, iter_v));
	}
	cout << endl;
	cout << endl;
	cout << "==============자동입력이 완료되었습니다.===============" << endl;
	cout << "=============총 입력된 자료는 " << st_sc.size() << "개 입니다.==============" << endl;
	cout << endl;
	cout << endl;
	int i = 1;
	for (auto iter = st_sc.begin(); iter != st_sc.end(); ++iter) {
		cout << i << ". " << "이름 : " << iter->second->name << " 성적 : " << iter->second->score << endl;
		i++;
	}
	cout << endl;
	cout << endl;

	i = 0;

	int select = 0;
	while (select != -1) {
		cout << "========이름으로 검색하시려면 1을 입력해주세요.=========" << endl;
		cout << "=========점수로 검색하시려면 2을 입력해주세요.==========" << endl;
		cout << "========이름으로 정렬하시려면 3을 입력해주세요.=========" << endl;
		cout << "=========점수로 정렬하시려면 4을 입력해주세요.==========" << endl;
		cout << "=============끝내시려면 -1을 입력해주세요.==============" << endl;
		cout << endl;
		cout << endl;
		cout << "명령 입력 : ";
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
			cout << "명령어를 잘못 입력하셨습니다." << endl;
			cin.clear();
			cin.ignore();
			break;
		}
		cin.clear();
		cin.ignore();
	}


	return 0;
}