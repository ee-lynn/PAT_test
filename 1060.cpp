#include<iostream>
#include<string>
using namespace std;
string convert(string num,int n)
{
	string result;
	if (n != 0)
	{
		result = "0.";
		int exp10;
		int pos_of_dot = num.find_first_of('.');
		if (pos_of_dot == string::npos)
			pos_of_dot = num.length();
		for (int i = 0; i < n; i++)
			if (num[i] != '.')
				result += num[i];
		result += "*10^";
		result += pos_of_dot + '0';
	}
	else result = "0";
	return result;
}
int main()
{
	int N;
	string A, B;
	cin >> N >> A >> B;
	bool same = true;
	string A_c = convert(A,N);
	string B_c = convert(B,N);
	if (A_c == B_c)
		cout << "YES" << " " << A_c << endl;
	else
		cout << "NO" << " " << A_c << " " << B_c << endl;
	return 0;
}