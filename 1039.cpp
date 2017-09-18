#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int main()
{
	int num, num_course;
	cin >> num >> num_course;
	map<string, vector<int>> Server;
	for (int i = 0; i < num_course; i++)
	{
		int index, num_student;
		cin >> index >> num_student;
		for (int j = 0; j < num_student; j++)
		{
			string name;
			cin >> name;
			if (Server.find(name) == Server.end())
			{
				vector<int> t(1);
				t[0] = index;
				Server.insert(pair<string, vector<int>>(name, t));
			}
				
			else
				Server[name].push_back(index);
		}
	}
	vector<string> querylist(num);
	for (int i = 0; i < num; i++)
		cin >> querylist[i];
	map<string, vector<int>>::iterator p;
	for (p = Server.begin(); p != Server.end(); p++)
		sort(p->second.begin(), p->second.end());
	for (int i = 0; i < num; i++)
	{
		cout<< querylist[i] << " ";
		if (Server.find(querylist[i])==Server.end())
			cout << 0 << endl;
		else
		{
			cout << Server[querylist[i]].size();
			for (int j = 0; j < Server[querylist[i]].size(); j++)
				cout << " " << Server[querylist[i]][j];
			cout << endl;
		}
	}
	return 0;
}