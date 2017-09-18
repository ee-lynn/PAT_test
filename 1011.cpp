#include <iostream>
#include <vector>
#include <stdio.h>
using namespace std;

int main()
{
    vector<char> result;
    double profit = 1;
    for (int i=0;i<3;i++)
    {
        int score[3];
        cin>>score[0]>>score[1]>>score[3];
        if (score[0]>score[1]&&score[0]>score[2])
        {
            result.push_back('W');
            profit *=score[0];
        }    
        else if (score[1]>score[0]&&score[1]>score[2])
        {
            result.push_back('T');
            profit *= score[1];
        }    
        else
        {
            result.push_back('L');
            profit *= score[2];
        }    
    }
    profit = 2.0*(profit*0.65-1);
    for (int i = 0;i<result.size();i++)
        cout<<result[i]<<" ";
    printf("%.2f\n",profit);
    return 0;
    
}
