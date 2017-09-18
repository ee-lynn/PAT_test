#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
typedef struct node
{
	int key;
	int left;
	int right;
}node;
int NUM = 0;
void invert(vector<node>& BTree, int root)
{
	if (BTree[root].left != -1)
		invert(BTree, BTree[root].left);
	if (BTree[root].right != -1)
		invert(BTree, BTree[root].right);
	int tmp;
	tmp = BTree[root].left;
	BTree[root].left = BTree[root].right;
	BTree[root].right = tmp;
}
void display_inorder(vector<node>& BTree, int root)
{
	if (BTree[root].left != -1)
		display_inorder(BTree, BTree[root].left);
	if (NUM == 0)
	{
		cout << root;
		NUM++;
	}
	else
		cout << " " << root;
	if (BTree[root].right != -1)
		display_inorder(BTree, BTree[root].right);
}
int main()
{
	int N;
	cin >> N;
	vector<node> BTree(N);
	vector<bool> Exits(N, false);
	for (int i = 0; i < N; i++)
	{
		char c;
		int key, left, right;
		cin >> c;
		if (c != '-')
		{
			left = c - '0';
			Exits[left] = true;
		}

		else
			left = -1;
		cin >> c;
		if (c != '-')
		{
			right = c - '0';
			Exits[right] = true;
		}

		else
			right = -1;
		BTree[i] = { i, left, right };
	}
	int root;
	for (int i = 0; i < N; i++)
		if (!Exits[i])
		{
			root = i;
			break;
		}
	invert(BTree, root);
	queue<node> myQueue;
	cout << root;
	myQueue.push(BTree[root]);
	while (!myQueue.empty())
	{
		int index = myQueue.front().left;
		if (index != -1)
		{
			node t = BTree[index];
			cout << " " << t.key;
			myQueue.push(t);
		}
		index = myQueue.front().right;
		if (index != -1)
		{
			node t = BTree[index];
			cout << " " << t.key;
			myQueue.push(t);
		}
		myQueue.pop();
	}
	cout << endl;
	display_inorder(BTree, root);
	cout << endl;
	return 0;
}