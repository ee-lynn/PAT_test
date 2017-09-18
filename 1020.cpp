#include<iostream>
#include <vector>
#include<queue>
using namespace std;
typedef struct node
{
	int key;
	node* left;
	node* right;
}node;
void printroot(vector<int> post, vector<int> in, node* p)
{
	int root = post[post.size() - 1];
	int rootindex = 0;
	for (int i = 0; i < in.size(); i++)
		if (root == in[i])
		{
			rootindex = i;
			break;
		}
	vector<int> leftin;
	vector<int> rightin;
	vector<int> leftpost;
	vector<int> rightpost;
	for (int i = 0; i < rootindex; i++)
		leftin.push_back(in[i]);
	for (int i = rootindex + 1; i < in.size(); i++)
		rightin.push_back(in[i]);
	int i = 0;
	for (i = 0; i < post.size() - 1; i++)
	{
		bool found = false;
		for (int j = 0; j < rootindex; j++)
			if (post[i] == in[j])
			{
				found = true;
				break;
			}
		if (found)
			leftpost.push_back(post[i]);
		else
			break;
	}
	for (int j = i; j < post.size() - 1; j++)
		rightpost.push_back(post[j]);
    if (leftpost.size() == 0)
	    p->left = NULL;
	else
	{
		node* left = new node;
		left->key = leftpost[leftpost.size() - 1];
		p->left = left;
		printroot(leftpost, leftin, left);
	}
	if (rightpost.size() == 0)
		p->right = NULL;
	else
	{
		node* right = new node;
		right->key = rightpost[rightpost.size() - 1];
		p->right = right;
		printroot(rightpost, rightin, right);
	}
}
void deletetree(node* r)
{
	if (r->left != NULL)
		deletetree(r->left);
	if (r->right != NULL)
		deletetree(r->right);
	delete r;
}
int main()
{
	int num;
	cin >> num;
	vector<int> post(num);
	for (int i = 0; i < num; i++)
	{
		cin >> post[i];
	}
	vector<int> in(num);
	for (int i = 0; i < num; i++)
	{
		cin >> in[i];
	}
	node* r = new node;
	r->key = post[post.size() - 1];
	printroot(post, in, r);
	queue<node*> level;
	level.push(r);
	cout << r->key;
	int aux = 0;
	while (!level.empty())
	{
		node* tmp = level.front();
		if (tmp->left!=NULL)
		    level.push(tmp->left);
		if (tmp->right!=NULL)
		    level.push(tmp->right);
		level.pop();
		if (!level.empty())
		    cout << " " << level.front()->key;
		else 
			cout << endl;
	}
	deletetree(r);
	return 0;
}