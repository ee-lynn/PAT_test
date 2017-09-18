#include <iostream>
#include <string>
using namespace std;

int main()
{
    int num;
    cin>>num;
    for (int i=0;i<num;i++)
    {
        long long A;
        long long B;
        long long C;
        cin>>A>>B>>C;
        if (A+B>C)
            cout<<"Case #"<<i+1<<": true"<<endl;
        else
            cout<<"Case #"<<i+1<<": false"<<endl;        
    }
    return 0;
}