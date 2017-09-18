#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> num2digit(int num)
{
	vector<int> result(4);
	for (int i = 0; i < 4; i++)
	{
		result[3 - i] = num % 10;
		num /= 10;
	}
	return result;

}
int digit2num(vector<int> num)
{
	int result = 0;
	for (int i = 0; i < 4; i++)
	{
		result *= 10;
		result += num[i];
	}
	return result;
}
bool cmp(int a, int b)
{
	return a > b;
}
int main()
{
	int num;
	cin >> num;
	auto t = num2digit(num);
	if (t[0] == t[1] && t[1] == t[2] && t[2] == t[3])
		printf("%04d - %04d = 0000\n", num, num);
	else
	{
		int result = num;
		do
		{
			t = num2digit(result);
			sort(t.begin(),t.end());
			auto t1 = t;
			sort(t1.begin(), t1.end(),cmp);
			int t_n = digit2num(t);
			int t1_n = digit2num(t1);
			result = t1_n - t_n;
			printf("%04d - %04d = %04d\n", t1_n, t_n, result);
		} while (result != 6174);
	}
	return 0;
}