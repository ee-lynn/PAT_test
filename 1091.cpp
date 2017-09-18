#include <vector>
#include <iostream>
using namespace std;
typedef struct node
{
	int key;
	bool visited;
}node;
int M, N, L, T;
void traverse(node*** p, int& vol,int i,int j,int k)
{
	p[i][j][k].visited = true;
	if (p[i][j][k].key)
	{
		vol++;
		if (i+1<L&&!p[i+1][j][k].visited)
		    traverse(p, vol, i + 1, j, k);
		if (i-1>=0&&!p[i-1][j][k].visited)
			traverse(p, vol, i -1, j, k);
		if (j + 1 < M&&!p[i][j+1][k].visited)
			traverse(p, vol, i, j+1, k);
		if (j - 1 >= 0 && !p[i][j-1][k].visited)
			traverse(p, vol, i, j-1, k);
		if (k + 1 < N&&!p[i][j][k+1].visited)
			traverse(p, vol, i , j, k+1);
		if (k - 1 >= 0 && !p[i][j][k-1].visited)
			traverse(p, vol, i , j, k-1);
	}
	else
		return;
		
}
int main()
{
	cin >> M >> N >> L >> T;
	node*** p = new node**[L];
	for (int i = 0; i < L; i++)
	{
		node **q = new node*[M];
		for (int j = 0; j < N; j++)
			q[j] = new node[N];
		p[i] = q;
	}
	for (int i = 0; i < L; i++)
		for (int j = 0; j < M; j++)
			for (int k = 0; k < N; k++)
			{
				cin >> p[i][j][k].key;
				p[i][j][k].visited = false;
			}
	int vol = 0;
	int sumvol = 0;
	for (int i = 0; i < L; i++)
		for (int j = 0; j < M; j++)
			for (int k = 0; k < N; k++)
				if (!p[i][j][k].visited)
				{
					vol = 0;
					traverse(p, vol, i, j, k);
					if (vol >= T)
						sumvol += vol;
				}
					
	cout << sumvol << endl;
	delete[] p;
	return 0;
}