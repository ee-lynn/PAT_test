#pragma warning (disable:4996)
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;
int main()
{
    char c;
    char original[80];
    char actual[80];
    scanf("%c",&c);
    int origin_len = 0;
    int actual_len = 0;
    while (c!='\n')
    {
        original[origin_len++] = c;
        scanf("%c",&c);
    }
    scanf("%c",&c);
    while (c!='\n')
    {
        actual[actual_len++] = c;
        scanf("%c",&c);
    }
    bool lack[35]{false};
    sort(actual,actual+actual_len);
    for (int i=0;i<origin_len;i++)
        if (!binary_search(actual,actual+actual_len,original[i]))
        {
            if (c>='A'&&c<='Z'&&!lack[c-'A'])
            {
                lack[c-'A'] = true;
                cout<<c;
            }
            else if (c>='a'&&c<='z'&&!lack[c-'a'])
            {
                lack[c-'a'] = true;
                cout<<c+'A'-'a';
            }
            else if (!lack[c+26])
            {
                lack[c+26] = true;
                cout<<c;
            }
        }
    cout<<endl;
    return 0;
}
