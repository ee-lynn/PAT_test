#pragma warning (disable:4996)
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define inf 0x7fffffff
using namespace std;
typedef struct element
{
	int no;
	int content;
}element;
bool cmp(element first, element second)
{
	return first.content < second.content;
}
bool cmp2(element first, element second)
{
	return first.no < second.no;
}
int main()
{
	int num;
	cin >> num;
	vector<element> R(num);
	for (int i = 0; i < num; i++)
	{
		int bet;
		cin >> bet;
		element t = { i, bet };
		R[i] = t;
	}
	sort(R.begin(), R.end(), cmp);
	for (int i = 1; i < num; i++)
		if (R[i].content == R[i - 1].content)
		{
			R[i - 1].no = inf;
			R[i].no = inf;
		}
	sort(R.begin(), R.end(), cmp2);
	if (R.front().no == inf)
		cout << "None" << endl;
	else
		cout << R.front().content << endl;
	return 0;
}