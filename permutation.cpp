#pragma  warning (disable: 4996)
#include <iostream>
#include <string>
#include <iostream>
#include <map>
#include <vector>
using namespace std;
void swap(vector<int>& r, int first, int second)
{
	if (first != second)
	{
		int t = r[first];
		r[first] = r[second];
		r[second] = t;
	}
}
void permutation(vector<int>&myList, int index, vector<int>& permut)
{
	if (index == myList.size())
	{
		for (int j = 0; j < permut.size(); j++)
			cout << permut[j];
		cout << endl;
		return;
	}
	for (int j = index; j < myList.size(); j++)
	{
		swap(myList, index, j);
		permut[index] = myList[index];
		permutation(myList, index+1, permut);
		swap(myList, index, j);
	}
}
int main()
{
	int num;
	cin >> num;
	vector<int> myList(num);
	for (int i = 0; i < num; i++)
		cin >> myList[i];
	vector<int> permut(num);
	permutation(myList, 0, permut);
	return 0;
}