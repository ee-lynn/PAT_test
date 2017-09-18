#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int N;
    cin>>N;
    int* D = new int[N+1];
    cin>>D[0];
    for (int i=1;i<N+1;i++)
    {
        int t;
        cin>>t;
        D[i] = t+D[i-1];
    }
    int M;
    cin>>M;
    vector<pair<int,int>> record(M);
    for (int i=0;i<M;i++)
    {
        int first,second;
        cin>>first>>second;
        auto pp = pair<int,int>(first-1,second-1);
        record[i] = pp;        
    }
    for (int i=0;i<M;i++)
    {
        if (record[i].first<record[i].second)
        {
            int minind = record[i].first;
            int maxind = record[i].second;
        }
        else
        {
            int minind = record[i].second;
            int maxind = record[i].first;
        }
        int dist = 0;
        if (D[maxind]-D[minind]<D[minind]+D[N]-D[minind])
            dist = D[maxind]-D[minind];
        else
            dist = D[minind]+D[N]-D[minind];
        cout<<dist<<endl;
    }        
    delete[] D;
    return 0;
    
}