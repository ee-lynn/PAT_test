#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int num, cost;
	cin >> num >> cost;
	vector<int> diamond(num);
	for (int i = 0; i < num; i++)
	{
		cin >> diamond[i];
	}
	vector<pair<int, int>> result;
	int overcostmin = 0x7fffffff;
	int i = 0, j = 1, sum = diamond[i];
	while (true)
	{
		if (sum < cost)
		{
			if (j >= num)
				break;
			else
				sum += diamond[j++];
		}
		else if (sum > cost)
		{
			if (sum < overcostmin)
				overcostmin = sum;
			sum -= diamond[i++];
		}
		else
		{
			pair<int, int> t = pair<int, int>(i, j);
			result.push_back(t);
			sum -= diamond[i++];
		}
	}
	if (!result.size())
	{
		cost = overcostmin;
		int i = 0; j = 1, sum = diamond[i];
		while (true)
		{
			if (sum<cost)
			{
				if (j >= num)
					break;
				else
					sum += diamond[j++];
			}
			else if (sum>cost)
				sum -= diamond[i++];
			else
			{
				pair<int, int> t = pair<int, int>(i, j);
				result.push_back(t);
				sum -= diamond[i++];
			}
		}
	}
	for (int i = 0; i < result.size(); i++)
		cout << result[i].first + 1 << "-" << result[i].second << endl;
	return 0;
}