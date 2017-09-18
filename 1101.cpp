#pragma warning (disable:4996)
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
	int N;
	scanf("%d", &N);
	int* p = new int[N];
	for (int i = 0; i < N; i++)
		scanf("%d", p + i);
	int* max_forward = new int[N];
	int* min_backward = new int[N];
	vector<int> result;
	max_forward[0] = 0;
	min_backward[N-1] = 1e9 + 1;
	for (int i = 1; i <= N; i++)
		max_forward[i] = max_forward[i-1] > p[i - 1] ? max_forward[i-1] : p[i - 1];
	for (int i = N - 2; i >= 0; i--)
		min_backward[i] = min_backward[i+1]< p[i + 1] ? min_backward[i+1] : p[i + 1];
		
	for (int i = 0; i<N; i++)
	{
		if (p[i]>max_forward[i] && p[i] < min_backward[i])
			result.push_back(p[i]);
	}
	sort(result.begin(), result.end());
	printf("%d\n", result.size());
	if (result.size() > 0)
		printf("%d", result[0]);
	for (int i = 1; i < result.size(); i++)
		printf(" %d", result[i]);
	printf("\n");
	delete[] p;
	delete[] max_forward;
	delete[] min_backward;
	return 0;
}