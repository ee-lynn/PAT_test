#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
typedef struct record
{
	int left;
	int right;
}record;
typedef struct node
{
	int key;
	node* left;
	node* right;
}node;
node* creat_tree(int index, vector<record>& Record)
{
	node* root = new node;
	if (Record[index].left != -1)
		root->left = creat_tree(Record[index].left, Record);
	else
		root->left = NULL;
	if (Record[index].right != -1)
		root->right = creat_tree(Record[index].right, Record);
	else
		root->right = NULL;
	return root;
}
void delete_tree(node*& root)
{
	if (root != NULL)
	{
		if (root->left != NULL)
			delete_tree(root->left);
		if (root->right != NULL)
			delete_tree(root->right);
		delete root;
		root = NULL;
	}
}
void in_order(node* root, int& num, vector<int>Key)
{
	if (root->left != NULL)
		in_order(root->left, num, Key);
	root->key = Key[num++];
	if (root->right != NULL)
		in_order(root->right, num, Key);
}
int main()
{
	int N;
	cin >> N;
	vector<record> Record(N);
	for (int i = 0; i < N; i++)
		cin >> Record[i].left >> Record[i].right;
	vector<int> Key(N);
	for (int i = 0; i < N; i++)
		cin >> Key[i];
	sort(Key.begin(), Key.end());
	node* root;
	root = creat_tree(0, Record);
	int num = 0;
	in_order(root, num, Key);
	queue<node*> myQueue;
	myQueue.push(root);
	cout << root->key;
	while (!myQueue.empty())
	{
		node* t = myQueue.front();
		myQueue.pop();
		if (t->left != NULL)
		{
			cout << " " << t->left->key;
			myQueue.push(t->left);
		}
		if (t->right != NULL)
		{
			cout << " " << t->right->key;
			myQueue.push(t->right);
		}
	}
	cout << endl;
	delete_tree(root);
	return 0;
}