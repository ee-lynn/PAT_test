#pragma warning (disable:4996)
#include <iostream>
#include <string>
#include <cstdlib>
#include <cstring>
using namespace std;
int main()
{
	string num;
	bool positive_digit = true;
	char tmp;
	scanf("%c", &tmp);
	if (tmp == '-')
		positive_digit = false;
	char digit[10000];
	int index = 0;
	scanf("%c", &tmp);
	digit[index++] = tmp;
	scanf("%c", &tmp);//'.'
	while (true)
	{
		scanf("%c", &tmp);
		if (tmp == 'E' || tmp == 'e')
			break;
		else
		    digit[index++] = tmp;
	}
	digit[index] = '\0';
	bool positive_exp = true;
	char exponet[10000];
	scanf("%c", &tmp);
	if (tmp == '-')
		positive_exp = false;
	index = 0;
	while (tmp != '\n')
	{
		scanf("%c", &tmp);
		exponet[index++] = tmp;
	}
	exponet[index] = '\0';
	int exp;
	sscanf(exponet, "%d", &exp);
	//sscanf(exponet, "%d", exp);
	if (!positive_digit)
		cout << "-";
	if (!positive_exp)
	{
		if (exp != 0)//<0
		{
			cout << "0.";
			for (int i = 1; i < exp; i++)
				cout << "0";
			for (int i = 0; i < strlen(digit); i++)
				cout << digit[i];
			cout << endl;
		}
		else
		{
			cout << digit[0] << ".";
			for (int i = 1; i < strlen(digit); i++)
				cout << digit[i];
			cout << endl;
		}
	}
	else
	{
		cout << digit[0];
		int i;
		for (i = 1; i <= exp&&i < strlen(digit); i++)
			cout << digit[i];
		if (i < strlen(digit))
		{
			cout << ".";
			for (; i < strlen(digit); i++)
				cout << digit[i];
			cout << endl;
		}
		else
		{
			for (; i <= exp; i++)
				cout << "0";
			cout << endl;
		}
	}
	return 0;
}