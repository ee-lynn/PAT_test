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
	Generation.push_back(1);
	BFS.push({ 0, 1 });
	while (!BFS.empty())
	{
		for (int i = 0; i < Family[BFS.front().id].size(); i++)
		{
			int gen;
			gen = BFS.front().generation + 1;
			Family[BFS.front().id][i].generation = gen;
			if (Generation.size() < gen)
				Generation.push_back(1);
			else
				Generation.back()++;
			BFS.push(Family[BFS.front().id][i]);
		}
		BFS.pop();
	}
	int max_generation = 1;
	int generation_num = 1;
	for (int i = 0; i < Generation.size(); i++)
		if (max_generation < Generation[i])
		{
			max_generation = Generation[i];
			generation_num = i;
		}
	cout << max_generation << " " << generation_num + 1 << endl;
	return 0;
}