#include <iostream>
#include <stdio.h>
using namespace std;
int main()
{
	int num1;
	cin >> num1;
	int* seq1 = new int[num1];
	for (int i = 0; i < num1; i++)
		cin >> seq1[i];
	int num2;
	cin >> num2;
	int* seq2 = new int[num2];
	for (int i = 0; i < num2; i++)
		cin >> seq2[i];
	int i = 0, j = 0;
	int total = (num1 + num2) / 2;
	if ((num1 + num2) % 2 != 0)
		total++;
	int count = 0;
	int median = 0;
	while (count < total)
	{
		if (i > num1-1 || (j<num2&&seq1[i] >= seq2[j]))
		{
			median = seq2[j];
			j++;
			count++;
		}
		else if (j > num2-1 || (i<num1&&seq1[i] < seq2[j]))
		{
			median = seq1[i];
			i++;
			count++;
		}
		
	}
	cout << median << endl;
	delete[] seq1;
	delete[] seq2;
}