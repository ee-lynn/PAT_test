#pragma warning( disable : 4996) 
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
#include <cstdlib>
#include <list>
//#include <ctime>
using namespace std;
int main()
{
	char s1[10000], s2[10000];
	int i = 0;
	do 
	{
		scanf("%c", s1 + i);
		i++;
	} while (s1[i-1]!='\n');
	int length1 = i;
	i = 0;
	int length2;
	do
	{
		scanf("%c", s2 + i);
		i++;
	} while (s2[i - 1] != '\n');
	length2 = i;
	sort(s2, s2 + length2);
	list<char> mystring;
	for (int j = 0; j < length1; j++)
		if (!binary_search(s2, s2 + length2, s1[j]))
			mystring.push_back(s1[j]);
	for (auto p = mystring.begin(); p != mystring.end(); p++)
		cout << *p;
	cout << endl;
	return 0;
}