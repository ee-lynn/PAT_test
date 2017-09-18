#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef struct info
{
	int key;
	int layer;
}info;
void traverse(int from, vector<vector<int>>& myGraph, vector<bool>& visited)
{
	for (auto p = myGraph[from].begin(); p != myGraph[from].end(); p++)
		if (!visited[*p])
		{
			visited[*p] = true;
			traverse(*p, myGraph, visited);
		}
}
int main()
{
	int N;
	cin >> N;
	vector<vector<int>> myGraph(N);
	for (int i = 0; i < N - 1; i++)
	{
		int from, to;
		cin >> from >> to;
		myGraph[--from].push_back(--to);
		myGraph[to].push_back(from);
	}
	vector<info> deepest_root;
	int global_max_layer = 0;
	int components = 0;
	bool connected = false;
	for (int i = 0; i < N; i++)
	{
		vector<bool> visited(N, false);
		queue<info> myQueue;
		myQueue.push({ i, 0 });
		visited[i] = true;
		int max_layer = 0;
		while (!myQueue.empty())
		{
			auto t = myQueue.front();
			myQueue.pop();
			if (myGraph[t.key].size() > 0 && global_max_layer <= t.layer + 1)
			{
				max_layer = t.layer + 1;
			}
			for (auto p = myGraph[t.key].begin(); p != myGraph[t.key].end(); p++)
				if (!visited[*p])
			    {
				    myQueue.push({ *p, t.layer + 1 });
				    visited[*p] = true;
			    }
		}
		if (global_max_layer <= max_layer)
		{
			global_max_layer = max_layer;
			while (deepest_root.size() > 0 && deepest_root.back().layer < max_layer)
				deepest_root.pop_back();
			deepest_root.push_back({ i, global_max_layer });
		}
		components = 1;
		if (!connected)
		{
			for (int i = 0; i < N; i++)
				if (!visited[i])
				{
					visited[i] = true;
					traverse(i, myGraph, visited);
					components++;
				}
		}
		if (components > 1)
			break;
		else
			connected = true;
	}
	if (components > 1)
		cout << "Error: " << components << " components" << endl;
	else
	{
		for (int i = 0; i < deepest_root.size(); i++)
			cout << ++deepest_root[i].key << endl;
	}
	return 0;
}