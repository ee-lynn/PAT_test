#include <iostream>
using namespace std;
int myMap[1000][1000] = { { 0 } };
void traverse(int start, int N, bool* status, int attacked)
{
	for (int i = 0; i < N; i++)
		if (i != attacked&&myMap[start][i] > 0 && !status[i])
		{
			status[i] = true;
			traverse(i, N, status, attacked);
		}
}
int main()
{
	int N, M, K;
	cin >> N >> M >> K;
	for (int i = 0; i < M; i++)
	{
		int node1, node2;
		cin >> node1 >> node2;
		myMap[node1 - 1][node2 - 1] = 1;
		myMap[node2 - 1][node1 - 1] = 1;
	}
	int* City_Concerned = new int[K];
	int* Connected_Componets = new int[K];
	for (int i = 0; i < K; i++)
	{
		cin >> City_Concerned[i];
		City_Concerned[i]--;
	}
	for (int i = 0; i < K; i++)
	{
		Connected_Componets[i] = 0;
		bool* status = new bool[N];
		for (int j = 0; j < N; j++)
			status[j] = false;
		for (int j = 0; j < N; j++)
		{
			if (!status[j] && j != City_Concerned[i])
			{
				Connected_Componets[i]++;
				traverse(j, N, status, City_Concerned[i]);
			}

		}
		delete[] status;
	}
	for (int i = 0; i < K; i++)
		cout << --Connected_Componets[i] << endl;
	delete[] Connected_Componets;
	delete[] City_Concerned;
	return 0;

}