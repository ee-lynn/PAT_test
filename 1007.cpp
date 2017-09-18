#pragma warning( disable : 4996) 
#include <iostream>
#include <stdio.h>
using namespace std;
int main()
{
	int num;
	cin >> num;
	int* storage = new int[num];
	for (int i = 0; i < num; i++)
		cin >> storage[i];
	int maxsum = -100;
	int sum = 0;
	int start = 0;
	int end = 0;
	for (int i = 0; i < num; i++)
	{
		sum = storage[i];
		for (int j = i+1; j < num; j++)
		{
			if (sum > maxsum)
			{
				start = i;
				end = j-1;
				maxsum = sum;
			}
			sum += storage[j];
		}		
	}
	if (maxsum < 0)
		printf("0 %d %d\n", storage[0], storage[num - 1]);
	else
		printf("%d %d %d\n", maxsum, storage[start], storage[end]);
	delete[] storage;
	return 0;
}