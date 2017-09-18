#pragma warning( disable : 4996) 
#include <iostream>
#include <stdio.h>
using namespace std;
int main()
{
	int num;
	cin >> num;
	int* storage = new int[num+1];
    int duration = 0;
    for (int i=1;i<=num;i++)
        cin>>storage[i];
    storage[0] = 0;
	for (int i = 1; i <= num; i++)
	{
        duration += 5;
        int tmp = storage[i]-storage[i-1];
        if (tmp<0)
            duration -= 4*tmp;
        else if(tmp>0)
            duration += 6*tmp;
            
    }	
    
	cout<<duration<<endl;
	//printf("%d %d %d\n", maxsum, storage[start], storage[end]);
	delete[] storage;
	return 0;
}