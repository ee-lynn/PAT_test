#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef struct record{
	int weight;
	double price;
	double price_per_weight;
}record;
bool cmp(record first, record second)
{
	return first.price_per_weight > second.price_per_weight;
}
int main()
{
	int N, D;
	cin >> N >> D;
	vector<record> Server(N);
	for (int i = 0; i < N; i++)
		cin >> Server[i].weight;
	for (int i = 0; i < N; i++)
		cin >> Server[i].price;
	for (int i = 0; i < N; i++)
		Server[i].price_per_weight = Server[i].price / Server[i].weight;
	sort(Server.begin(), Server.end(), cmp);
	double profit = 0.0;
	int total_weight = 0;
	int index = 0;
	while (total_weight < D)
	{
		profit += Server[index].price;
		total_weight += Server[index].weight;
		index++;
		if (index >= N)
			break;
	}
	if (total_weight > D)
	{
		profit -= Server[--index].price_per_weight*(total_weight - D);
	}
	printf("%.2f\n", profit);
	return 0;
}