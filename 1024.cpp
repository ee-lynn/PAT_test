#include <iostream>
#include <string>
#include <deque>
using namespace std;
deque<int> add(deque<int> a, deque<int> b)
{
	deque<int> result;
	int i = 0;
	int full = 0;
	for (i = 0; i < a.size() && i < b.size(); i++)
	{
		int tmp = a[i] + b[i];
		result.push_front((tmp + full) % 10);
		full = tmp / 10;
	}
	for (int j = i; j < a.size(); j++)
	{
		int tmp = a[j] + full;
		result.push_front(tmp % 10);
		full = tmp / 10;
	}
	for (int j = i; j < b.size(); j++)
	{
		int tmp = b[j] + full;
		result.push_front(tmp % 10);
		full = tmp / 10;
	}
	if (full == 1)
		result.push_front(1);
	return result;
}
bool is_Palindromic(deque<int> num)
{
	bool Yes = true;
	for (int i = 0; i < num.size() / 2; i++)
		if (num[i] != num[num.size() - 1 - i])
		{
			Yes = false;
			break;
		}
	return Yes;
}
deque<int> reverse(deque<int> num)
{
	deque<int> result(num);
	for (int i = 0; i < num.size()/2; i++)
    {
        int t = result[i];
        result[i] = result[num.size() - 1 - i];
        result[num.size() - 1 - i] =t; 
    }
		
	return result;
}
int main()
{
	string num_s;
	int k;
	cin >> num_s >> k;
	deque<int> num(num_s.length());
	for (int i = 0; i < num_s.length(); i++)
		num[i] = num_s[i] - '0';
	int iteration = 0;
    bool printed = false;
	while (!is_Palindromic(num))
	{
		if (iteration >= k)
		{
			for (int i = 0; i < num.size(); i++)
				cout << num[i];
			cout << endl;
			cout << k << endl;
			printed = true;
			break;
		}
		else
		{
			deque<int> tmp = reverse(num);
			num = add(num, tmp);
			iteration++;
		}
	}
	if (!printed)
	{
		for (int i = 0; i < num.size(); i++)
			cout << num[i];
		cout << endl;
		cout << iteration << endl;
	}
	return 0;
}