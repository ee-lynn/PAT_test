#include <iostream>
#include <vector>
using namespace std;
typedef struct node
{
	int key;
	node* left;
	node* right;
}node;
int splitBST(vector<int> s, bool& status)
{
	int index = 0;
	for (int i = 1; i < s.size(); i++)
	{
		index++;
		if (s[i] >= s[0])
			break;
	}
	for (int i = index; i < s.size(); i++)
		if (s[i] < s[0])
		{
			status = false;
			break;
		}
	return index;
}
int splitrBST(vector<int> s, bool& status)
{
	int index = 0;
	for (int i = 1; i < s.size(); i++)
	{
		index++;
		if (s[i] < s[0])
			break;
	}
	for (int i = index; i < s.size(); i++)
		if (s[i] >= s[0])
		{
			status = false;
			break;
		}
	return index;
}
node* create_subtree(vector<int> s, bool& status, int en)
{
	node* p = new node;
	p->key = s[0];
	if (s.size()>1)
	{
		int index;
		if (en == 0)
			index = splitBST(s, status);
		else
			index = splitrBST(s, status);
		if (status)
		{
			if (index > 1)
			{
				vector<int> storage_l(s.begin() + 1, s.begin() + index);
				p->left = create_subtree(storage_l, status, en);
			}
			else
				p->left = NULL;
			if (index < s.size())
			{
				vector<int> storage_r(s.begin() + index, s.end());
				p->right = create_subtree(storage_r, status, en);
			}
			else
				p->right = NULL;
		}
		else
		{
			p->left = NULL;
			p->right = NULL;
		}
	}
	else
	{
		p->left = NULL;
		p->right = NULL;
	}
	return p;
}
void deletetree(node*& root)
{
	if (root->left != NULL)
		deletetree(root->left);
	if (root->right != NULL)
		deletetree(root->right);
	delete root;
    root = NULL;
}
void traverse(node* root, vector<int>& r)
{
	if (root->left != NULL)
		traverse(root->left, r);
	if (root->right != NULL)
		traverse(root->right, r);
	r.push_back(root->key);
}

int main()
{
	int num;
	cin >> num;
	bool status = true;
	vector<int> storage(num);
	for (int i = 0; i < num; i++)
		cin >> storage[i];
	node* root;
	root = create_subtree(storage, status, 0);
	if (!status)
	{
		status = true;
		deletetree(root);
		root = create_subtree(storage, status, 1);
		if (!status)
		{
			cout << "NO" << endl;
			deletetree(root);
		}
	}
	if (status)
	{
		vector<int>record;//postorder traverse of BST
		traverse(root, record);
		cout << "YES" << endl;
		cout << record[0];
		for (int i = 1; i < record.size(); i++)
			cout << " " << record[i];
		cout << endl;
	}
	return 0;
}