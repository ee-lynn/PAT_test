#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <queue>
using namespace std;
typedef struct node
{
	int key;
	int gap;
}node;
int main()
{
	int num;
	cin >> num;
	map<int, vector<node>> Graph;
	float P;
	float r;
	cin >> P >> r;
	int head = 0;
	for (int i = 0; i < num; i++)
	{
		int t;
		cin >> t;
		if (t != -1)
		{
			if (Graph.find(t) == Graph.end())
			{
				vector<node> vt;
				vt.push_back({ i, -1 });
				Graph.insert(pair<int, vector<node>>(t,vt));
			}	
			else
				Graph[t].push_back({ i, -1 });
		}
		else
			head = i;
	}
	int maxgap = 0;
	int total_num = 0;
	queue<node> myQueue;
	myQueue.push({ head, 0 });
	while (!myQueue.empty())
	{
		if (Graph.find(myQueue.front().key)!=Graph.end())
		{
			for (int i = 0; i < Graph[myQueue.front().key].size(); i++)
			{
				Graph[myQueue.front().key][i].gap = myQueue.front().gap + 1;
				myQueue.push(Graph[myQueue.front().key][i]);
				if (maxgap < myQueue.back().gap)
				{
					maxgap = myQueue.back().gap;
					total_num = 1;
				}
				else if (maxgap == myQueue.back().gap)
					total_num++;
			}

		}
		myQueue.pop();
	}
	printf("%.2f %d\n", P*pow((1.0 + r / 100.0), maxgap*1.0), total_num);
	return 0;
}