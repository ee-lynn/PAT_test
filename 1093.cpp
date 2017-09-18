#include <vector> 
#include <iostream>
#include <string>
using namespace std;
int main()
{
	string PAT;
	cin >> PAT;
	int len = PAT.length();
	vector<int> ensemble_T(len);
	vector<int> ensemble_A(len);
		int num = 0;
	for (int i = 0; i < len; i++)
		if (PAT[i] == 'T')
			ensemble_T[i] = 1;
	for (int i = len - 1; i >= 1; i--)
		ensemble_T[i - 1] = (ensemble_T[i - 1] + ensemble_T[i]) % 1000000007;
	//vector<int> ensemble_A = ensemble_T;
	for (int i = 0; i < len; i++)
		if (PAT[i] == 'A')
			ensemble_A[i] = ensemble_T[i];
	for (int i = len - 1; i >= 1; i--)
		ensemble_A[i - 1] = (ensemble_A[i - 1] + ensemble_A[i]) % 1000000007;
	for (int i = -0; i < len; i++)
		if (PAT[i] == 'P')
			num = (num + ensemble_A[i]) % 1000000007;
	cout << num << endl;
	return 0;

}