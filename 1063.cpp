#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	int num;
	cin >> num;
	vector<list<unsigned int>> Storage(num);
	for (int i = 0; i < num; i++)
	{
		int length;
		cin >> length;
		list<unsigned int> Origin_Set;
		for (int j = 0; j < length; j++)
		{
			int t;
			cin >> t;
			Origin_Set.push_back(t);
		}
		Storage[i] = Origin_Set;
	}
	int K;
	cin >> K;
	for (int i = 0; i < K; i++)
	{
		int first, second;
		cin >> first >> second;
		auto t1 = Storage[first - 1];
		auto t2 = Storage[second - 1];
		t1.sort();
		t1.unique();
		t2.sort();
		t2.unique();
		int Nc;
		if (t1.size() < t2.size())//长的用二分查找
		{
			Nc = t1.size();
			auto p = t1.begin();
			while (p != t1.end())
			{
				if (!binary_search(t2.begin(), t2.end(), *p))
				Nc--;
				p++;
			}
		}
		else
		{
			Nc = t2.size();
			auto p = t2.begin();
			while (p != t2.end())
			{
				if (!binary_search(t1.begin(), t1.end(), *p))
					Nc--;
				p++;
			}
		}
		t1.merge(t2);
        t1.unique();
		int Nt = t1.size();
		printf("%.1f%%\n", Nc*1.0 / Nt * 100);
	}
	return 0;
}