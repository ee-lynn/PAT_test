#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
typedef struct record
{
	string  name;
	char gender;
	string ID;
	int grade;
}record;
bool cmp(record first, record second)
{
	return first.grade > second.grade;
}
int main()
{
	vector<record> Mrecord;
	vector<record> Frecord;
	int num;
	cin >> num;
	for (int i = 0; i < num; i++)
	{
		string name;
		string ID;
		char gender;
		int grade;
		cin >> name >> gender>> ID >> grade;
		record t = { name, gender, ID, grade };
		if (gender == 'M')
			Mrecord.push_back(t);
		else
			Frecord.push_back(t);
	}
	bool fnull = true, mnull = true;
	if (Frecord.size() != 0)
	{
		fnull = false;
		sort(Frecord.begin(), Frecord.end(), cmp);
	}
	if (Mrecord.size() != 0)
	{
		mnull = false;
		sort(Mrecord.begin(), Mrecord.end(), cmp);
	}
	if (!fnull)
		cout << Frecord.front().name << " " << Frecord.front().ID << endl;
	else
		cout << "Absent" << endl;
	if (!mnull)
		cout << Mrecord.back().name << " " << Mrecord.back().ID << endl;
	else
		cout << "Absent" << endl;
	if (!fnull&&!mnull)
		cout << Frecord.front().grade - Mrecord.back().grade << endl;
	else
		cout << "NA" << endl;

	return 0;
}