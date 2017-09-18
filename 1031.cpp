#include <iostream>
#include <string>
using namespace std;
int main()
{
    string ch;
    cin>>ch;
    int flag = (ch.length()+2)/3;
    int middle = ch.length()-2*flag;
    for (int i=0;i<flag-1;i++)
    {
        cout<<ch[i];
        for (int j = 0;j<middle;j++)
            cout<<" ";
        cout<<ch[ch.length()-1-i]<<endl;
    }
    for (int i=flag-1;i<=ch.length()-flag;i++)
        cout<< ch[i];
    cout<<endl;    
    return 0;
    
}