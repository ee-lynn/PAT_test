#include <iostream>
#include <vector>
#include <stack>
#define inf 0xffffff
using namespace std;

class node
{
public:
	node(int d = inf,int c = inf)
		:dist(d), cost(c){}
	int dist;
	int cost;
};
int main()
{
	int N, M, S, D;
	cin >> N >> M >> S >> D;
	vector<node> myMap(N*N);
	vector<bool> visited(N,false);
	vector<int> lastnode(N,-1);
	vector<int> total_dist(N,inf);
	vector<int> total_cost(N,inf);
	for (int i = 0; i < M; i++)
	{
		int c1, c2, d, c;
		cin >> c1 >> c2 >> d >> c;
		node t(d, c);
		myMap[c1*N + c2] = t;
		myMap[c2*N + c1] = t;
	}
	total_cost[S] = 0;
	total_dist[S] = 0;
	visited[S] = true;
	for (int i = 0; i < N; i++) //initial
		if (myMap[S*N + i].dist != inf)
		{
			total_dist[i] = myMap[S*N + i].dist;
			total_cost[i] = myMap[S*N + i].cost;
			lastnode[i] = S;
		}
	for (int i = 1; i < N; i++)  //greedy
	{
		int minindex;
		int mindist = inf;
		int mincost = inf; //mindist对应的mincost
		for (int j = 0; j < N; j++)
		{
			if (!visited[j])
			{
				if (total_dist[j] == mindist&&total_cost[j] < mincost)
				{
					mincost = total_cost[j];
					minindex = j;
				}
				else if (total_dist[j] < mindist)
				{
					mindist = total_dist[j];
					mincost = total_cost[j];
					minindex = j;
				}
			}

		}
		visited[minindex] = true;
		for (int j = 0; j<N; j++)
		{
			if (!visited[j])
			{
				if (total_dist[j]>total_dist[minindex] + myMap[minindex*N + j].dist)
				{
					total_dist[j] = total_dist[minindex] + myMap[minindex*N + j].dist;
					total_cost[j] = total_cost[minindex] + myMap[minindex*N + j].cost;
					lastnode[j] = minindex;
				}
				else if (total_dist[j] == total_dist[minindex] + myMap[minindex*N + j].dist&& total_cost[j] > total_cost[minindex] + myMap[minindex*N + j].cost)
				{
					total_cost[j] = total_cost[minindex] + myMap[minindex*N + j].cost;
					lastnode[j] = minindex;
				}
					
			}
		}
	}
	stack<int> path;
	path.push(D);
	int last = lastnode[D];
	while (last != -1)
	{
		path.push(last);
		last = lastnode[last];
	}
	while (!path.empty())
	{
		cout << path.top() << " ";
		path.pop();
	}
	cout << total_dist[D] << " " << total_cost[D] << endl;

	return 0;
}