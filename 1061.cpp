#include <iostream>
#include <string>
using namespace std;
string calcweekday(char c)
{
	string result;
	int sw = c - 'A';
	switch (sw)
	{
	case 0:
		return "MON";
	case 1:
		return "TUE";
	case 2:
		return "WED";
	case 3:
		return "THU";
	case 4:
		return "FRI";
	case 5:
		return "SAT";
	case 6:
		return "SUN";
	default:
		return "NULL";
	}
	return result;
}
int calchour(char c)
{
	int result;
	if (c >= '0'&&c <= '9')
		result = c - '0';
	else
		result = c - 'A' + 10;
	if (result < 0 || result>23)
		result = -1; 
	return result;
}
inline bool is_letter(char c)
{
	return (c <= 'Z'&&c >= 'A') || (c <= 'z'&&c >= 'a');
}
int main()
{
	char A[60], B[60], C[60], D[60];
	string week;
	int hour;
	int min;
	cin >> A >> B >> C >> D;
	bool first = true;
	for (int i = 0; A[i]!=0 && B[i]!=0; i++)
		if (A[i] >= 'A'&&A[i] <= 'Z'&&A[i] == B[i])
		{
			if (first)
			{
				week = calcweekday(A[i]);
				if (week!="NULL")
				    first = false;
			}
			else
			{
				hour = calchour(A[i]);
				if (hour!=-1)
				    break;
			}

		}
	for (int i = 0; C[i]!=0 && D[i]!=0; i++)
		if (is_letter(C[i]) && C[i] == D[i])
		{
			min = i;
			break;
		}
	printf("%s %02d:%02d\n", week.c_str(), hour, min);
	return 0;
}