#include <iostream>
#include <vector>
#include <math.h>
#include <string>
using namespace std;

int main()
{
    int a,b;
    int sum = 0;
    cin>>a>>b;
    sum = a+b;
    int tmp = abs(sum);
    vector<string>storage;
    while (tmp/1000)
    {
		char stmp[4];
		sprintf_s(stmp,"%03d",tmp%1000);
		storage.push_back(string(stmp));
        tmp/=1000;
        storage.push_back(",");
    }
    if (sum<0)
        cout<<"-";
	if (tmp < 1000)
		cout << tmp;
    for (int i = storage.size()-1; i>=0; i--)
        cout<<storage[i];
    cout<<endl;            
	system("pause");
    return 0;
}