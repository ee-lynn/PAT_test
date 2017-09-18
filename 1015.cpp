#include <iostream>
#include <stdio.h>
#include <math.h>
#include <queue>
using namespace std;
bool is_prim(int num)
{
	if (num <= 1)
		return false;
	for (int i = 2; i <= sqrt(num) + 1; i++)
		if (num%i == 0)
			return false;
	return true;
}
int reverse(int num, int radix)
{
	queue<int> num_radix;
	while (num)
	{
		num_radix.push(num%radix);
		num /= radix;
	}
	int result = num_radix.front();
	num_radix.pop();
	while (!num_radix.empty())
	{
		result = result*radix + num_radix.front();
		num_radix.pop();
	}
	return result;
}
int main()
{
	int num, radix;
	while (true)
	{
		cin >> num;
		if (num > 0)
		{
			cin >> radix;
			if (is_prim(num) && is_prim(reverse(num, radix)))
				cout << "Yes" << endl;
			else
				cout << "No" << endl;
		}
		else
			break;
	}

	return 0;
}