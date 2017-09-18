#include <iostream>
#include <algorithm>
#include <vector> 
using namespace std;
bool insertion_sort(vector<int> myList, const vector<int> result)
{
	bool ok = false;
	for (int i = 1; i < myList.size(); i++)
	{
		int t = myList[i];
		int j;
		for (j = i - 1; j >= 0; j--)
		{
			if (t < myList[j])
				myList[j + 1] = myList[j];
			else
				break;
		}
		myList[j + 1] = t;
		bool found = true;
		for (int k = 0; k < myList.size(); k++)
			if (myList[k] != result[k])
				found = false;
		if (found)
		{
			cout << "Insertion Sort" << endl;
			i++;
			t = myList[i];
			for (j = i - 1; j >= 0; j--)
			{
				if (t < myList[j])
					myList[j + 1] = myList[j];
				else
					break;
			}
			myList[j + 1] = t;
			cout << myList[0];
			for (int k = 1; k < myList.size(); k++)
				cout << " " << myList[k];
			cout << endl;
			ok = true;
			break;
		}
	}
	return ok;
}
void heap_sort(vector<int> myList, const vector<int> result)
{
	make_heap(myList.begin(),myList.end());
	int len = myList.size();
	cout << "Heap Sort" << endl;
	int i;
	for (i = 0; i < len; i++)
	{
		pop_heap(myList.begin(), myList.begin() + len - i);
		bool found = true;
		for (int j = 0; j < len; j++)
			if (myList[j] != result[j])
				found = false;
		if (found)
		{
			pop_heap(myList.begin(), myList.begin() + len - i - 1);
			cout << myList[0];
			for (int j = 1; j < len; j++)
				cout << " " << myList[j];
			cout << endl;
			break;
		}
	}
}
int main()
{
	int num;
	cin >> num;
	vector<int> original(num);
	for (int i = 0; i < num; i++)
		cin >> original[i];
	vector<int> result(num);
	for (int i = 0; i < num; i++)
		cin >> result[i];
	bool insert = insertion_sort(original, result);
	if (!insert)
		heap_sort(original, result);
	return 0;
}