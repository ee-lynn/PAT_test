#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int num, cost;
	cin >> num >> cost;
	vector<int> coin(num);
	for (int i = 0; i < num; i++)
		cin >> coin[i];
	sort(coin.begin(), coin.end());
	bool found = false;
	int index;
	for (int i = 0; i<num; i++)
		if (coin[i]>(cost / 2 + 1))
			break;
		else
		{
			if (binary_search(coin.begin() + i + 1, coin.end(), cost - coin[i]))
			{
				index = i;
				found = true;
				break;
			}
		}
	if (!found)
		cout << "No Solution" << endl;
	else
		cout << coin[index] << " " << cost - coin[index] << endl;
	return 0;
}