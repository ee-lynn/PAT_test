#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;
typedef struct node
{
	int id;
	int generation;
}node;
int main()
{
	int N, K;
	cin >> N >> K;
	vector<vector<node>> Family(N);
	for (int i = 0; i < K; i++)
	{
		int id;
		cin >> id;
		int num_child;
		cin >> num_child;
		for (int j = 0; j < num_child; j++)
		{
			int id_child;
			cin >> id_child;
			Family[id - 1].push_back({ id_child - 1, 0 });
		}
	}
	queue<node> BFS;
	vector<int> Generation;
	BFS.push({ 0, 1 });
	while (!BFS.empty())
	{
		if (Generation.size() < BFS.front().generation)
			Generation.push_back(0);
		if (Family[BFS.front().id].size() == 0)
			Generation.back()++;
		for (int i = 0; i < Family[BFS.front().id].size(); i++)
		{
			int gen;
			gen = BFS.front().generation + 1;
			Family[BFS.front().id][i].generation = gen;
			BFS.push(Family[BFS.front().id][i]);
		}
		BFS.pop();
	}
	cout << Generation[0];
	for (int i = 1; i < Generation.size(); i++)
		cout << " " << Generation[i];
	cout << endl;
	return 0;
}