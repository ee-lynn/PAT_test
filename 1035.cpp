#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef struct record
{
    string usrname;
    string password;
}record;
int main()
{
    int num;
    cin>>num;
    vector<record> records;
    for (int i=0;i<num;i++)
    {
        string usrname,password;
        cin>>usrname>>password;
        bool changed = false;
        for (int j=0;j<password.length();j++)
        {
            switch (password[j])
            {
            case '1':
                password[j] = '@';
                changed = true;
                break;
            case '0':
                password[j] = '%';
                changed = true;
                break;
            case 'l':
                password[j] = 'L';
                changed = true;
                break;
            case 'O':
                password[j] = 'o';
                changed = true;
            }
        }
        if (changed)
        {
            record t= {usrname,password};
            records.push_back(t);
        }           
    }
    if (num==1&&records.size()==0)
        cout<<"There is 1 account and no account is modified"<<endl;
    else if (records.size()=0)
        cout<< "There is" <<num<< "accounts and no account is modified"<<endl;
    else
    {
        cout<<records.size()<<endl;;
        for (int i=0;i<records.size();i++)
            cout<<records[i].usrname<<" "<<records[i].password<<endl;
    }
    
    return 0;
}