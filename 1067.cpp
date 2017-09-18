#include <iostream>
#include <vector>
using namespace std;
void swap(vector<int>& myList,int first,int second)
{
    int t;
    t = myList[second];
    myList[second] = myList[first];
    myList[first] = t;
}

int main()
{
    int num;
    vector<int> myList(num);
    int pos = 0;
    map<int,int> myMap;//num:index
    for (int i=0;i<num;i++)
    {
        cin>>myList[i];
        pair<int,int> t(myList[i],i);
        myMap.insert(t);
        if (myList[i]==0)
            pos = i;
    }
    int cnt = 0;
    while (pos!=0)
    {
        swap(myList,pos,myMap[pos]);
        cnt++;
        pos = myMap[pos];
    }
    for (int i=0;i<num;i++)
    {
        while (myList[i]!=i)
        {
            swap(myList,0,myList[i]);
            cnt++;
            while (pos!=0)
            {
                swap(myList,pos,myMap[pos]);
                cnt++;
                pos = myMap[pos];
            }
        }    
    }
    for (int i=0;i<num;i++)
        cout<<myList[i]<<" ";
    cout<<endl;
    cout<<cnt<<endl;
    return 0;
}