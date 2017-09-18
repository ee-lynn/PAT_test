#include <iostream>
#include <string>
#include <deque>
using namespace std;
deque<int> doublebignum(string num)
{
    deque<int> result;
    int full = 0;
    for(int i=num.length()-1;i>=0;i--)
    {
        int tmp = (num[i]-'0')*2+full;
        result.push_front(tmp%10);
        if (tmp>9)
            full = 1;
        else
            full = 0;
    }
    return result;        
}
int main()
{
    string bignum;
    cin>>bignum;
    deque<int> after = doublebignum(bignum);
    int a1[10]{0};
    int a2[10]{0};
    for (int i=0;i<bignum.length();i++)
        a1[bugnum[i]-'0']++;
    for (int i=0;i<after.size();i++)
        a2[after[i]]++;
    bool magic = true;
    for (int i=0;i<10;i++)
        if (a1[i]!=a2[i])
        {
            magic = false;
            break;
        }    
    if (magic)
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;
    for (int i = 0;i<after.size();i++)
        cout<<after[i];
    cout<<endl;        
      
    return 0;
}
