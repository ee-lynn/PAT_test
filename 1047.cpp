#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int main()
{
    int N,K;
    cin>>N>>K;
    vector<vector<string>> Server(K);
    for (int i=0;i<N;i++)
    {
        string name;
        cin>>name;
        int num;
        cin>>num;
        for (int j=0;i<num;j++)
        {
            int tmp;
            cin>>tmp;
            Server[tmp-1].push_back(name);
        }
    }
    for (int i=0;i<K;i++)
    {
        cout<<i+1<<" "<< Server[i].size()<<endl;
        sort(Server[i].begin(),Server[i].end());
        for (int j=0;j<Server[i].size();j++)
            cout<<Server[i][j]<<endl;
    }   
    return 0;
}