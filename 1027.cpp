#include<iostream>
#include<stack>
using namespace std;
char map(int num)
{
    if (num>=10)
        return num-10+'A';
    else
        return num+'0';
}
int main()
{
    int r,g,b;
    cin>>r>>g>>b;
    stack<int> rmars;
    stack<int> gmars;
    stack<int> bmars;
    rmars.push(r%13);
    rmars.push(r/13);
    gmars.push(g%13);
    gmars.push(g/13);
    bmars.push(b%13);
    bmars.push(b/13);
    cout<<"#";
    while (!rmars.empty())
    {
        cout<<map(rmars.top());
        rmars.pop();
    }
    while (!gmars.empty())
    {
        cout<<map(gmars.top());
        gmars.pop();
    }
    while (!bmars.empty())
    {
        cout<<map(bmars.top());
        bmars.pop();
    }
    cout<<endl;
}
