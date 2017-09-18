#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int main()
{
	int num;
	cin >> num;
	int bak = num;
	vector<int> Prime_list;
	vector<int> Exp;
	vector<int> Prime_componet;
	//筛法确定小于它的所有素数   //注意：是比自己小，不能包含自己是质数的情况!!
 	//分解质因数
	Prime_list.push_back(2);
	bool found;
	for (int i = 2; i < sqrt(num) + 1; i++)
	{
		found = false;
		for (int j = 0; j < Prime_list.size(); j++)
			if (i%Prime_list[j] == 0)
			{
				found = true;
				break;
			}
		if (!found)
			Prime_list.push_back(i);
	}
	found = false;
	for (int i = 0; i < Prime_list.size();i++)
		if (num%Prime_list[i] == 0)
		{
			found = true;
			break;
		}
	if (!found)
	{
		cout << num << "=" << num << endl;
		return 0;
	}   //自己是质数
		
	if (num == 1)
	{
		cout << "1=1" << endl;
		return 0;
	}
	for (int i = 0; i < Prime_list.size(); i++)
	{
		if (num == 1)
			break;
		if (num%Prime_list[i] == 0)
		{
			Prime_componet.push_back(Prime_list[i]);
		    Exp.push_back(1);
			num /= Prime_list[i];
			while (num%Prime_list[i] == 0)
			{
				Exp[Exp.size()-1]++;
				num /= Prime_list[i];
			}
		}
	}
	cout << bak << "=" << Prime_componet[0];
	if (Exp[0]>1)
		cout << "^" << Exp[0];
	for (int i = 1; i < Exp.size(); i++)
	{
		cout << "*" << Prime_componet[i];
		if (Exp[i]>1)
			cout << "^" << Exp[i];
	}
	cout <<endl;
	return 0;
}