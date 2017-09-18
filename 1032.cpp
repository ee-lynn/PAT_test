#include <iostream>
#include <vector>
using namespace std;
typedef struct node
{
	int addr;
	char ch;
	int next;
	bool visited;
}node;
int main()
{
	int addr1, addr2, num;
	cin >> addr1 >> addr2 >> num;
	vector<node> record(num);
	int maxaddr = 0;
	for (int i = 0; i < num; i++)
	{
		int addr, next;
		char ch;
		node thisnode;
		cin >> addr >> ch >> next;
		if (maxaddr < addr)
			maxaddr = addr;
		thisnode = { addr, ch, next, false };
		record[i] = thisnode;
	}
	node* storage = new node[maxaddr];
	for (int i = 0; i < num; i++)
	{
		int thisadd = record[i].addr;
		storage[thisadd - 1] = record[i];
	}
		
	while (addr1 != -1)
	{
		storage[addr1 - 1].visited = true;
		addr1 = storage[addr1 - 1].next;
	}
	while (addr2 != -1)
	{
		if (storage[addr2 - 1].visited)
			break;
		else
		{
			storage[addr2 - 1].visited = true;
			addr2 = storage[addr2 - 1].next;
		}
	}
	if (addr2 == -1)
		printf("-1\n");
	else
		printf("%05d\n", addr2);
	delete[] storage;
	return 0;
}