#include <iostream>
#include <string>
#include <vector>
using namespace std;
void sort (vector<int>& index,vector<int> Id,vector<int> forsort)
{
	int num = index.size();
    for (int i=0;i<num;i++)
    {
        for (int j = 0; j<num-1-i;j++)
            if (forsort[index[j]]>forsort[index[j+1]]||(forsort[index[j]]==forsort[index[j+1]]&&Id[index[j]]>Id[index[j+1]]))
            {
                int tmp;
                tmp = index[j];
                index[j] = index[j+1];
                index[j+1] = tmp;
            }
    }
}
void sort(vector<int>& index,vector<int> Id,vector<string> forsort)
{
	int num = index.size();
	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j < num - 1 - i; j++)
			if (forsort[index[j]] > forsort[index[j + 1]] || (forsort[index[j]] == forsort[index[j + 1]] && Id[index[j]] > Id[index[j + 1]]))
			{
				int tmp;
				tmp = index[j];
				index[j] = index[j + 1];
				index[j+1] = tmp;
			}
	}
}

int main()
{
    int num,col;
    cin>>num>>col;
    vector<int> Id(num);
    vector<string> Name(num);
    vector<int> Score(num);
    for (int i=0;i<num;i++)
    {
        int tmp_i;
        cin>>tmp_i;
        Id[i] = tmp_i;
        string tmp_s;
        cin>>tmp_s;
        Name[i] = tmp_s;
        cin>>tmp_i;
        Score[i] = tmp_i;
    }
    vector<int> index(num);
    for (int i=0;i<num;i++)
        index[i] = i;
    if (col==1)
        sort(index,Id,Id);
    else if (col==2)
        sort(index,Id,Name);
    else
        sort(index,Id,Score);
    for (int i=0;i<num;i++)
        printf("%06d %s %d\n",Id[index[i]],Name[index[i]].c_str(),Score[index[i]]);   
    return 0;
}