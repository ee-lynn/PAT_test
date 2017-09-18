#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int binary_index(vector<int>& myList, int key, int begin, int end)
{
	if (end - begin <= 1)
	{
		if (myList[begin] > key)
			return begin;
		else
			return end;
	}
	int mid = (begin + end) / 2;
	if (myList[mid] <= key)
		return binary_index(myList, key, mid, end);
	else
		return binary_index(myList, key, begin, mid); 
}

int main()
{
	int num, p;
	cin >> num >> p;
	vector<int> myList(num);
	for (int i = 0; i < num; i++)
		cin >> myList[i];
	sort(myList.begin(), myList.end());
	int maxnum = 0;
	for (int i = 0; i < myList.size() - maxnum; i++)
	{
		int end = binary_index(myList, myList[i] * p, i, myList.size());
	    if (maxnum < end - i)
			maxnum = end - i;
	}
	cout << maxnum << endl;
	return 0;
}