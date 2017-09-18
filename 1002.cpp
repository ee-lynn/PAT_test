#include <iostream>
#include <vector>
#include <math.h>
#include <stdio.h>
using namespace std;
int main()
{
	int N1, N2;
	cin >> N1;
	float* coeff1 = new float[N1];
	int* exp1 = new int[N1];
	for (int i = 0; i < N1; i++)
		cin >> exp1[i] >> coeff1[i];
	cin >> N2;
	float* coeff2 = new float[N2];
	int* exp2 = new int[N2];
	for (int i = 0; i < N2; i++)
		cin >> exp2[i] >> coeff2[i];
	int N3 =0;
	vector<int> exp3;
	vector<float>coeff3;
	int i1 = 0;
	int i2 = 0;
	while (i1 < N1 && i2 < N2)
	{
		if (exp1[i1] < exp2[i2])
		{
			exp3.push_back(exp2[i2]);
			coeff3.push_back(coeff2[i2]);
			i2++;
		}
		else if (exp1[i1]>exp2[i2])
		{
			exp3.push_back(exp1[i1]);
			coeff3.push_back(coeff1[i1]);
			i1++;
		}
		else
		{
			if (fabs(coeff1[i1] + coeff2[i2]) < 1e-2)
			{
				i1++;
				i2++;
			}
			else
			{
				exp3.push_back(exp1[i1]);
				coeff3.push_back(coeff1[i1] + coeff2[i2]);
				i1++;
				i2++;
			}
		}		
	}
	if (i1 < N1)
	{
		for (int j = i1; j < N1; j++)
		{
			exp3.push_back(exp1[j]);
			coeff3.push_back(coeff1[j]);
		}
	}
	else
	{
		for (int j = i2; j < N2; j++)
		{
			exp3.push_back(exp2[j]);
			coeff3.push_back(coeff2[j]);
		}
	}
	cout << exp3.size();
	for (int j = 0; j < exp3.size(); j++)
		printf(" %d %.1f", exp3[j], coeff3[j]);
	cout << endl;
	delete[]coeff1;
	delete[]exp1;
	delete[]coeff2;
	delete[]exp2;
	return 0;
}