#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
typedef struct node
{
    int addr;
    int key;
    int next;
}node;
using namespace std;
bool cmp(node first,node second)
{
    return first.addr<second.addr;
}
int binary_search(vector<node>& myList,int addr,int begin,int end)
{
    int mid = (end+begin)/2;
    while(end-begin>1)
    {
        if (myList[mid].addr==addr)
            return mid;
        if (myList[mid].addr<addr)
            begin = mid+1;
        else if (myList[mid].addr>addr)
            end = mid;
    }
    return begin;
}
int main()
{
    int num;
    int ini_addr;
    cin>>num>>ini_addr;
    vector<bool> exists(10000,false);
    vector<node> Storage(num);
    for (int i=0;i<num;i++)
    {
        int addr;
        int key;
        int next;
        cin>>addr>>key>>next;
        Storage[i] = {addr,key,next};
    }
    vector<node> Deduplicated;
    vector<node> Removed;
    sort(Storage.begin(),Storage.end());
    while (addr!=-1)
    {
        int index = binary_search(Storage,addr,0,Storage.size());
        node t = Storage[index];
        if (exists[abs(t.key)])
            Removed.push_back(t);
        else
        {
            Deduplicated.push_back(t);
            exists[abs(t.key)] = true;
        }
        addr = Storage[index].next;
    }
    for (int i=0;i<Deduplicated.size()-1;i++)
        printf("%05d %d %05d\n",Deduplicated[i].addr,Deduplicated[i].key,Deduplicated[i+1].addr);
    printf("%05d %d -1\n",Deduplicated.back().addr,Deduplicated.back().key);
    for (int i=0;i<Removed.size()-1;i++)
        printf("%05d %d %05d\n",Removed[i].addr,Removed[i].key,Removed[i+1].addr);
    printf("%05d %d -1\n",Removed.back().addr,Removed.back().key);
    return 0;
}