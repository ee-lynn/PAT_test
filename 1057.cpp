#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <string>
using namespace std;
int main()
{
    int num;
    cin>>num;
    list<int> myStack;
    int Top = 0;
    for (int i=0;i<num;i++)
    {
        string command;
        cin>>command;
        if (command=="Pop")
        {
            if(!Top)
                cout<<"Invalid"<<endl;
            else
            {
                Top--;
                cout<<myStack.back();
                myStack.pop_back();
                
            }
                
        }
        else if (command=="Push")
        {
            int key;
            cin>>key;
            myStack.push_back(key);
            Top++;
        }     
        else
        {
            if (!Top)
                cout<<"Invalid"<<endl;
            else
            {
                vector<int> sortedstack(myStack.begin(),myStack.begin()+Top);
                sort(sortedstack.begin(),sortedstack.end());
                cout<<sortedstack[(Top-1)/2]<<endl;
            }
            
        }            
    }
    return 0;
}