#include <iostream>
#include <vector>
#include <stack>
#include <cmath>
using namespace std;
int main()
{
	int num;
	cin >> num;
	int max_num_factor = 0;
	stack<int> factors;
	for (int i = 2; i < pow(num,1.0/max_num_factor);)
	{
		int procee_num = num;
		int this_max = 0;
		while (procee_num%i == 0)
		{
			factors.push(i);
			this_max++;
			procee_num /= i;
			i++;
		}
		if (max_num_factor < this_max)
		{
			max_num_factor = this_max;
		}
		else
		{
			for (int j = 0; j < this_max; j++)
				factors.pop();
		}
        if (this_max==0)
            i++;
	}
	cout << max_num_factor << endl;
	stack<int> display;
	for (int i = 0; i < max_num_factor; i++)
	{
		display.push(factors.top());
		factors.pop();
	}
	cout << display.top();
	display.pop();
	for (int i = 1; i < max_num_factor; i++)
	{
		cout << "*" << display.top();
		display.pop();
	}
	cout << endl;
	return 0;
}