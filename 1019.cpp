#include <iostream>
#include <vector>
using namespace std;

vector<int> convert(int N, int b)
{
	vector<int> result;
	while (N)
	{
		result.push_back(N%b);
		N /= b;
	}
	return result;
}
int main()
{
	int num, b;
	cin >> num >> b;
	vector<int> seq = convert(num, b);
	bool diff = false;
	for (int i = 0; i < seq.size() / 2; i++)
		if (seq[i] != seq[seq.size() - 1 - i])
		{
			diff = true;
			break;
		}
	if (diff)
		cout << "No" << endl;
	else
		cout << "Yes" << endl;
	if (seq.size() == 0)
		cout << "0" << endl;
	else
	{
		cout << seq[seq.size() - 1];
		for (int i = seq.size() - 2; i >= 0; i--)
		{
			cout << " " << seq[i];
		}
		cout << endl;
	}
	return 0;
}