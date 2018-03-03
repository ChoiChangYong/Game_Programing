#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main_1()
{
	vector<int> v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);
	;
	for (vector<int>::size_type i = 0; i < v.size(); ++i)
		cout << v[i] << " ";
	cout << endl;

	vector<int>::iterator iter;
	vector<int>::iterator iter_b = v.begin();
	vector<int>::iterator iter_e = v.begin() + 2;
	iter = adjacent_find(iter_b, iter_e);

	if (iter != iter_e)
		cout << "1-1 " << *iter << endl;

	cout << "=====================" << endl;
	if (iter != v.end())
		cout << "1-2 " << *iter << endl;

	iter_b = v.begin();
	iter_e = v.end();
	iter = adjacent_find(iter_b, iter_e);

	if (iter != iter_e)
		cout << "2-1 " << *iter << endl;
	if (iter != v.end())
		cout << "2-2 " << *iter << endl;

	return 0;
}