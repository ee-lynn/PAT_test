#pragma  warning (disable:4996)
#include <iostream>
#include <string>
#include <vector>
using namespace std;
vector<char> find_suffix(vector<char> first, vector<char> second)
{
	vector<char> result;
	int index_A = first.size() - 1;
	int index_B = second.size() - 1;
	bool same = true;
	while (same&&index_A >= 0 && index_B >= 0)
	{
		same = first[index_A] == second[index_B];
		index_A--;
		index_B--;
	}	
	if (index_A < 0)
		result = first;
	else
		result = vector<char>(first.begin()+index_A+2,first.end());
	return result;
}
int main()
{
	int num;
	cin >> num;
	vector<char> t1, t2;
	char c;
	int index = 0;
	getchar();
	while (true)
	{
		scanf("%c", &c);
		if (c == '\n')
		{
			t1.push_back('0');
			break;
		}
		else
			t1.push_back(c);
	}
	for (int i = 1; i < num; i++)
	{
		index = 0;
		while (true)
		{
			scanf("%c", &c);
			if (c == '\n')
			{
				t2.push_back('0');
				break;
			}
			else
				t2.push_back(c);
		}
		t1 = find_suffix(t1, t2);
	}
	if (t1.size() >1 )
	{
		bool nonempty = false;
		for (int i = 0; i < t1.size() - 1; i++)
		{
			if (t1[i] != ' ')
				nonempty = true;
			if (nonempty)
				cout << t1[i];
		}
		cout << endl;
	}
		
	else
		cout << "nai" << endl;
	return 0;
}