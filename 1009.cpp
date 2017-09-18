#pragma warning( disable : 4996) 
#include <iostream>
#include <stdio.h>
#include <math.h>
#include <vector>
using namespace std;
typedef struct
{
	vector<int> exp;
	vector<float> coeff;
} polynomial;
polynomial addpoly(polynomial p1, polynomial p2)
{
	polynomial result;
	int N1 = p1.exp.size();
	int N2 = p2.exp.size();
	int i, j;
	for (i = 0, j = 0; i < N1 && j<N2;)
	{
		if (p1.exp[i]>p2.exp[j] && fabs(p1.coeff[i])>=0.0001)
		{
			result.exp.push_back(p1.exp[i]);
			result.coeff.push_back(p1.coeff[i]);
			i++;
		}
		else if (p1.exp[i] < p2.exp[j]&&fabs(p2.coeff[j])>=0.0001)
		{
			result.exp.push_back(p2.exp[i]);
			result.coeff.push_back(p2.coeff[i]);
			j++;
		}
		else
		{
			float tmp = p1.coeff[i] + p2.coeff[j];
			if (fabs(tmp) > 1e-2)
			{
				result.exp.push_back(p1.exp[i]);
				result.coeff.push_back(tmp);
			}
			i++;
			j++;
		}
	}
	if (i < N1)
	{
		while (i < N1)
		{
			result.exp.push_back(p1.exp[i]);
			result.coeff.push_back(p1.coeff[i]);
			i++;
		}
	}
	if (j < N2)
	{
		while (j < N2)
		{
			result.exp.push_back(p2.exp[j]);
			result.coeff.push_back(p2.coeff[j]);
			j++;
		}
	}
	return result;
}
int main()
{
	polynomial p1, p2;
	int num1;
	cin >> num1;
	for (int i = 0; i < num1; i++)
	{
		int exp;
		scanf("%d", &exp);
		p1.exp.push_back(exp);
		float coeff;
		scanf("%f", &coeff);
		p1.coeff.push_back(coeff);
	}
	int num2;
	cin >> num2;
	for (int i = 0; i < num2; i++)
	{
		int exp;
		scanf("%d", &exp);
		p2.exp.push_back(exp);
		float coeff;
		scanf("%f", &coeff);
		p2.coeff.push_back(coeff);
	}
	if (num2 != 0 && num1 != 0)
	{
		polynomial* p = new polynomial[num2];
		for (int i = 0; i < num2; i++)
		{
			for (int j = 0; j < num1; j++)
			{
				float tmp = p1.coeff[j] * p2.coeff[i];
				if (fabs(tmp)>0.0005)
				{
					p[i].exp.push_back(p1.exp[j] + p2.exp[i]);
					p[i].coeff.push_back(tmp);
				}
			}
		}
		polynomial result = p[0];
		for (int i = 1; i < num2; i++)
			result = addpoly(p[i], result);

		cout << result.exp.size();
		for (int i = 0; i < result.exp.size(); i++)
		{
			printf(" %d %.1f", result.exp[i], result.coeff[i]);
		}
		cout << endl;
		delete[] p;
	}
	else
		cout << "0" << endl;
	
	return 0;
}