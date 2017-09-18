#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
using namespace std;
typedef struct record
{
	string name;
	int age;
	int worth;
}record;
typedef struct query
{
	int num;
	int agemin;
	int agemax;
}query;
bool cmp_by_age(record first, record second)
{
	return first.age<second.age;
}
bool cmp_disp(record first, record second)
{
	/*
	non-increasing order of the net worths.
	In case there are equal worths, it must be in non-decreasing order of the ages.
	If both worths and ages are the same, then the output must be in non-decreasing alphabetical order of the names.
	*/
	return (first.worth > second.worth) || (first.worth == second.worth&&first.age < second.age) || (first.worth == second.worth&&first.age == second.age&&first.name < second.name);
}
int main()
{
	int N, K;
    cin >> N >> K;
	vector<record> Server(N);
	for (int i = 0; i<N; i++)
	{
		char name[10];
		int age;
		int worth;
		cin >> name >> age >> worth;
        Server[i] = { name, age, worth };
	}
	sort(Server.begin(), Server.end(), cmp_by_age);
	vector<query> Query(K);
	for (int i = 0; i<K; i++)
	{
		int q, w, e;
		cin >> q >> w >> e;
		Query[i] = { q, w, e };
	}
	for (int i = 0; i<K; i++)
	{
		cout << "Case #" << i + 1 << ":" << endl;
		int maxindex;
		int minindex;
		for (minindex = 0; minindex < N; minindex++)
			if (Server[minindex].age >= Query[i].agemin)
				break;
		for (maxindex = N - 1; maxindex >= 0; maxindex--)
			if (Server[maxindex].age <= Query[i].agemax)
				break;
		++maxindex;
		if (maxindex <= minindex)
			cout << "None" << endl;
		else
		{
			vector<record> process(Server.begin() + minindex, Server.begin() + maxindex);
			sort(process.begin(), process.end(), cmp_disp);
			for (int j = 0; j<process.size()&&j<Query[i].num; j++)
				cout << process[j].name << " " << process[j].age << " " << process[j].worth << endl;
		}
	}
	return 0;
}