#pragma warning (disable:4996)
#include <iostream>
#include <string>
using namespace std;
int main()
{
	char tc[1010];
	for (int i = 0; i < 1000; i++)
	{    
		char tmp;
		scanf("%c", &tmp);
		if (tmp != '\0'&&tmp != '\n')
			tc[i] = tmp;
		else
		{
			tc[i] = '\0';
			break;
		}
	}
	string t = tc;
	int len = t.length();
	int max_len = 0;
	for (int i = 0; i < len; i++)
	{
		int p = 1;
		int sym_len1 = 1; //   sts
		int sym_len2 = 0;  //  ss
		while (i - p >= 0 && i + p < len)
		{
			if (t[i - p] != t[i + p])
				break;
			else
			{
				sym_len1 += 2;
				p++;
			}
		}
		if (sym_len1 > max_len)
			max_len = sym_len1;
		p = 1;
		while (i + p< len && i - p + 1 >= 0)
		{
			if (t[i - p + 1] != t[i + p])
				break;
			else
			{
				sym_len2 += 2;
				p++;
			}
		}
		if (sym_len2>max_len)
			max_len = sym_len2;
	}
	cout << max_len << endl;
	return 0;
}