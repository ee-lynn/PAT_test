#include <iostream>
#include <vector>
using namespace std;
void swap(int& first, int& second)
{
	int t = first;
	first = second;
	second = t;
}
bool Insert_sort(vector<int>myList, const vector<int> Target)
{
	bool found = false;
	int i;
	for (i = 1; i < myList.size(); i++)
	{
		if (!found)
		{
			for (int j = i; j > 0; j--)
			{
				if (myList[j] < myList[j - 1])
					swap(myList[j], myList[j - 1]);
				else
					break;
			}
			int k;
			for (k = 0; k < myList.size(); k++)
				if (myList[k] != Target[k])
					break;
			if (k == myList.size())
				found = true;
		}
		else
		{
			for (int j = i; j > 0; j--)
			{
				if (myList[j] < myList[j - 1])
					swap(myList[j], myList[j - 1]);
				else
					break;
			}
			cout << "Insertion Sort" << endl;
			cout << myList[0];
			for (int j = 1; j < myList.size(); j++)
				cout << " " << myList[j];
			cout << endl;
			break;
		}
	}
	return found;

}
void Merge_sort(vector<int> myList, const vector<int> Target)
{
	vector<int> Storage = myList;
	bool found = false;
	for (int num = 1; num < myList.size(); num *= 2)
	{
		for (int lower = 0, upper_i = lower + num, upper_j = upper_i + num; upper_i < myList.size(); lower += 2 * num, upper_i = lower + num,upper_j = upper_i + num)
		{
			if (upper_j > myList.size())
				upper_j = myList.size();
			int i = 0, j = 0, k = 0;
			for (k = 0; k < 2 * num && i < num && j < upper_j - upper_i; k++)
				if (myList[lower + i] < myList[upper_i + j])
					Storage[lower+k] = myList[lower + i++];
				else
					Storage[lower + k] = myList[upper_i + j++];
			for (; j < upper_j - upper_i; j++)
			{
				Storage[lower + k] = myList[upper_i + j];
				k++;
				j++;
			}
			for (; i < num; i++)
			{
				Storage[lower + k] = myList[lower + i];
				k++;
				i++;
			}
		}
		if (found)
		{
			cout << "Merge Sort" << endl;
			cout << Storage[0];
			for (int index = 1; index < Storage.size(); index++)
				cout << " " << Storage[index];
			cout << endl;
		}
		found = true;
		for (int index = 0; index < myList.size(); index++)
		{
			myList[index] = Storage[index];
			if (myList[index] != Target[index])
				found = false;
		}
	}
}
int main()
{
	int num;
	cin >> num;
	vector<int> myList(num);
	for (int i = 0; i < num; i++)
		cin >> myList[i];
	vector<int>Target(num);
	for (int i = 0; i < num; i++)
		cin >> Target[i];
	bool finished = false;
	finished = Insert_sort(myList, Target);
	if (!finished)
		Merge_sort(myList, Target);
	return 0;
}