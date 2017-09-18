#include <iostream>
#include <stack>
using namespace std;
int main()
{
	int M, N, K;
	cin >> M >> N >> K;
	for (int i = 0; i < K; i++)
	{
		bool wrong = false;
		stack<int> myStack;
		int currentnum = 1;
		int j = 0;
		for (j = 0; j < N; j++)
		{
			int t;
			cin >> t;
			while (myStack.empty()||myStack.top() < t)
			{
				myStack.push(currentnum);
				currentnum++;
			}
			if (myStack.size() > M || myStack.top() > t)
			{
				cout << "NO" << endl;
				j++;  //跳出去后还要加，否则就对不齐了
				wrong = true;
				break;
			}
			if (myStack.top() == t)
				myStack.pop();
		}
		int dummy;
		for (; j < N; j++)
			cin >> dummy;
		if (!wrong)
			cout << "YES" << endl;
	}
	return 0;
}