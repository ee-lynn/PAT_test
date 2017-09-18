#include <stack>
#include <iostream>
#include <vector>
#include <string>
using namespace std;
typedef struct node
{
	int key;
	node* left;
	node* right;
}node;
int NUM;
node* creat_tree(stack<node*>&path, vector<string>&operation)
{
	string op;
	cin >> op;
	node* result = NULL;
	operation.push_back(op);
	if (op == "Push")
	{
		int num;
		cin >> num;
		result = new node{ num, NULL, NULL };
		path.push(result);
		result->left = creat_tree(path, operation);
		if (operation.size() < 2*NUM)
			result->right = creat_tree(path, operation);
		else
			result->right = NULL;
	}
	else
	    path.pop();
	return result;
}
void display_tree(node* root)
{
	if (root->left != NULL)
		display_tree(root->left);
	if (root->right != NULL)
		display_tree(root->right);
	cout << root->key<<" ";
}
void delete_tree(node* root)
{
	if (root->left != NULL)
		delete_tree(root->left);
	if (root->right)
		delete_tree(root->right);
	delete[] root;
}
int main()
{
	int num;
	cin >> num;
	NUM = num;
	vector<string> operation;
	stack<node*>path;
	bool keep = false;
	int cnt = 0;
	node* root = creat_tree(path,operation);
	if (root->left != NULL)
		display_tree(root->left);
	if (root->right != NULL)
		display_tree(root->right);
	cout << root->key << endl;
	delete_tree(root);
	return 0;
}