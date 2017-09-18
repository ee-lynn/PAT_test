#include<vector>
using namespace std;
typedef struct node
{
    unsigned int address;
    int key;
    unsigned int next;
}node;
bool cmp(node first,node second)
{
    return first.key<second.key;
}
int main()
{
    int num,dummy;
    cin>>num>>dummy;
    vector<node> mylist(num);
    for (int i=0;i<num;i++)
    {
        unsigned int address;
        int key;
        cin>>address>>key>>dummy;
        node t = {address,key,dummy};
        mylist[i] = t;
    }
    sort(mylist.begin(),myulist.end(),cmp);
    cout<<num<<" "<<mylist[0].address<<endl;
    for (int i=0;i<num-1;i++)
    {
        printf("%05d %d %05d\n",mylist[i].address,mylist[i].key,mylist[i+1].address);
    }
    printf("%05d %d -1\n",mylist[num-1].address,mylist[num-1].key);
    return 0;
}