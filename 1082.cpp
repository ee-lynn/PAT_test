#pragma warning (disable:4996)
#include <iostream>
#include <stack>
using namespace std;
string convert(char num)
{
    switch(num)
    {
        case '1':
            return "yi";
        case '2':
            return "er";
        case '3':
            return "san";
        case '4':
            return "si";
        case '5':
            return "wu";
        case '6':
            return "liu";
        case '7':
            return "qi";
        case '8':
            return "ba";
        case '9':
            return "jiu";
        default:
            return "ling";        
    }
}
string convert_unit(int index)
{
    switch(index)
    {
        case 0:
            return "";
        case 1:
            return "Shi";
        case 2:
            return "Bai";
        case 3:
            return "Qian";
    }
}
bool is_allzero(char*& p, int index,int len)
{
    bool result = true;
    for (int i=index;i<len;i++)
    {
        result &= p[i]=='0';
        if (!result)
            break;
    }
    return result;
}
int main()
{
    char num[10];
    char c;
    scanf("%c",&c);
    bool neg = c=='-';
    cout<<"Fu";//整数第一个数不应该输出空格
    int len = 0;
    while (c!='\n')
    {
        if (!neg)
            num[len++] = c;
        scanf("%c",&c);
        neg = false;
    }
    if (int i=0;i<len;i++)
    {
        if (num[i]=='0')
        {
            if (!is_allzero(num,i,len));
                cout<<" "<<"Ling";
        }
        else
        {
            cout<<" "<<convert(num[i]);
            cout<<" "<<convert_unit((len-i)%4);
            if ((len-i)==5)
                cout<<" Wan";
            if ((len-i)==9)
                cout<<"Yi";                
        }    
    }
    cout<<endl;
    return 0;
}