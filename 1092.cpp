#include <iostream>
#include <string>
using namespace std;
int convert(char c)
{
    if (c<='z'&&c>='a')
        return c-'a'+36;
    else if (c<='Z'&&c>='A')
        return c-'A'+10;
    else
        return c-'0';
    
}
int main()
{
    string shop,eva;
    cin>>shop>>eva;
    vector<int> shop_map(62,0),eva_map(62,0);
    int lack = 0;
    for (int i=0;i<shop.length();i++)
        shop_map[convert(shop[i])]++;
    for (int i=0;i<eva.length();i++)
        eva_map[convert(eva[i])]++;
    for(int i=0;i<62;i++)
        lack += max(eva_map[i]-shop_map[i],0);
    if (lack>0)
        cout<<"Yes "<<lack<<endl;
    else
        cout<<"No "<<shop.length()-eva.length()<<endl;
    
    return 0;
}