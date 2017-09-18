#pragma warning < disable:4996>
#include <iostream>
#include <string>
using namespace std;

string formation(int i)
{
	string result;
	switch (i / 13)
	{
	case 0:
		result = "S";
		break;
	case 1:
		result = "H";
		break;
	case 2:
		result = "C";
		break;
	case 3:
		result = "D";
		break;
	default:
		result = "J";
	}
	result += to_string(i % 13 + 1);
	return result;
}
int main()
{
	int num;
	string t1[54], t2[54];
	for (int i = 0; i < 54; i++)
	{
		t1[i] = formation(i);
	}
	cin >> num;
	int order[54];
	
	
	for (int i = 0; i < 54; i++)
	{
		cin >> order[i];
	}
	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j < 54; j++)
			t2[order[j] - 1] = t1[j];
		for (int j = 0; j < 54; j++)
			t1[j] = t2[j];
	}

	cout << t1[0];
	for (int i = 1; i < 54; i++)
		cout << " " << t1[i];
	cout << endl;
	return 0;
}