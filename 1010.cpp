#pragma warning(disable: 4996)
#include <iostream>
#include <vector>
#include <string>
using namespace std;
int mapset(char ch)
{
	if (ch >= '0'&&ch <= '9')
		return ch - '0';
	else
		return ch - 'a' + 10;
}
int convert(string num, int radix)
{
	int result = mapset(num[0]);
	for (int i = 1; i < num.length(); i++)
		result = result*radix + mapset(num[i]);
	return result;
}
int main()
{
	string N1;
	string N2;
	int tag;
	int radix;
	cin >> N1 >> N2 >> tag >> radix;
	if (tag == 2)
	{
		string tmp = N2;
		N2 = N1;
		N1 = tmp;
	}//无论tag是多少，都是N1为已知radix
	int num1 = convert(N1, radix);
	int minradix = 1;
	for (int i = 0; i < N2.length(); i++)
		if (minradix < mapset(N2[i]))
			minradix = mapset(N2[i]);
	minradix++;
	bool found = false;
	for (int i = minradix; i <= 100; i++)
	{
		int num2 = convert(N2, i);
		if (num2 == num1)
		{
			found = true;
			cout << i << endl;
			break;
		}
	}
	if (!found)
		cout << "impossible" << endl;
	return 0;
}