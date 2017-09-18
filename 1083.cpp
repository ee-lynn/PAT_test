#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;
typedef struct record
{
	string name;
	string id;
	int grade;
}record;
bool cmp(record first, record second)
{
	return first.grade > second.grade;
}
int main()
{
	int N;
	cin >> N;
	vector<record> Records(N);
	for (int i = 0; i < N; i++)
	{
		string name, id;
		int grade;
		cin >> name >> id >> grade;
		Records[i] = { name, id, grade };
	}
	sort(Records.begin(), Records.end(), cmp);
	int lower, upper;
	cin >> lower >> upper;
	record t = { "dummy", "dummy", upper };
	auto p_l = lower_bound(Records.begin(), Records.end(), t, cmp);
	t = { "dummy", "dummy", lower };
	auto p_u = upper_bound(Records.begin(), Records.end(), t, cmp);
	bool found = false;
	for (auto p = p_l; p != p_u; p++)
	{
		cout << p->name << " " << p->id << endl;
		found = true;
	}
		
	if (!found)
		cout << "NONE" << endl;
	return 0;
}