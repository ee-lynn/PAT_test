#pragma warning( disable : 4996) 
#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;
int main()
{
	int num;
	cin >> num;
	string* ID = new string[num];
	int IDearliet = 0, IDlatest = 0;
	int minsec = 24 * 3600;
	int maxsec = 0;
	for (int i = 0; i < num; i++)
	{
		cin >> ID[i];
		int h, m, s;
		scanf("%d:%d:%d", &h, &m, &s);
		if (3600 * h + 60 * m + s < minsec)
		{
			IDearliet = i;
			minsec = 3600 * h + 60 * m + s;
		}
			
		scanf("%d:%d:%d", &h, &m, &s);
		if (3600 * h + 60 * m + s > maxsec)
		{
			IDlatest = i;
			maxsec = 3600 * h + 60 * m + s;
		}
			
	}
	cout << ID[IDearliet] << " " << ID[IDlatest]<<endl;
	delete[] ID;
	return 0;
}