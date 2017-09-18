//树根为中位数做出来的树只能是平衡的，但不能保证是完全的
//此版本只保证了平衡
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
typedef struct node
{
	int key;
	node* left;
	node* right;
}node;
node* creat_tree(vector<int>& key, int left, int right)
{
	node* r = new node;
	r->key = key[(left + right)/2];
	if ((left + right) / 2 > left)
		r->left = creat_tree(key, left, (left + right) / 2);
	else
		r->left = NULL;
	if ((right + left) / 2 + 1<right)
		r->right = creat_tree(key, (right + left) / 2+1, right);
	else
		r->right = NULL;
	return r;
}
void deletetree(node* t)
{
	if (t->left != NULL)
		deletetree(t->left);
	if (t->right != NULL)
		deletetree(t->right);
	delete t;
}
int main()
{
	int num;
	cin >> num;
	vector<int> key(num);
	for (int i = 0; i < num; i++)
		cin >> key[i];
	sort(key.begin(), key.end());
	node* root = creat_tree(key,0,num);
	queue<node> nodebook;
	nodebook.push(*root);
	cout << root->key;
	int cnt = 1;
	while (!nodebook.empty())
	{
		auto t = nodebook.front();
		if (cnt != 1)
		{
			cout << " " << t.key;
		}
		cnt++;
		if (t.left)
			nodebook.push(*(t.left));
		if (t.right)
			nodebook.push(*(t.right));
		nodebook.pop();
	}
	deletetree(root);
	cout << endl;
	return 0;
}