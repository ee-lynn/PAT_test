#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef struct node
{
	int addr;
	int key;
	int next;
}node;
bool cmp(node first, node second)
{
	return first.addr < second.addr;
}
int search_index(vector<node>& s, int key)
{
	int lower = 0,upper = s.size();
	while (true)
	{
		if (upper - lower <= 1)
			return lower;
		int middle = (upper + lower) / 2;
		if (s[middle].addr < key)
			lower = middle + 1;
		else if (s[middle].addr > key)
			upper = middle;
		else
			return middle;
	}
}
void swap(node& a, node& b)
{
	node t;
	t = a;
	a = b;
	b = t;
}
int main()
{
	int addr, N, K;
	cin >> addr >> N >> K;
	vector<node> Storage(N);
	for (int i = 0; i < N; i++)
	{
		int addr_t, key, next;
		cin >> addr_t >> key >> next;
		node t = { addr_t, key, next };
		Storage[i] = t;
	}
	sort(Storage.begin(), Storage.end(), cmp);
	vector<node> myList(N);
	for (int i = 0; i < N; i++)
	{
		int index = search_index(Storage, addr);
		myList[i] = Storage[index];
		addr = myList[i].next;
	}
	int i;
	int len = myList.size();
	if (K > 1)
	{
		for (i = 0; i + K <= N; i += K)
			for (int j = 0; j < K / 2; j++)
				swap(myList[i + j], myList[i + K - j - 1]);
		
		for (int j = 0; j < len - 1; j++)
			printf("%05d %d %05d\n", myList[j].addr, myList[j].key, myList[j + 1].addr);
		printf("%05d %d -1\n", myList[len - 1].addr, myList[len - 1].key);
		//for (int j = 0; j < (N - i) / 2; j++)
		//	swap(myList[i + j], myList[N - j - 1]);
	}
	else
	{
		for (int j = 0; j < len-1; j++)
			printf("%05d %d %05d\n", myList[j].addr, myList[j].key, myList[j].next);
		printf("%05d %d -1\n", myList[len - 1].addr, myList[len - 1].key);
	}
	return 0;
}