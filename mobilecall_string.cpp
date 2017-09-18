#pragma  warning (disable: 4996)
#include <iostream>
#include <string>
#include <iostream>
#include <map>
#include <vector>
using namespace std;
//九宫格打字问题
/*
符号+- abc def
ghi  jkl  mno
pqrs  tuv  wxyz
*/
void print(string& num, int index, map<char,string>& Server,vector<char>path)//记录path是非常关键的，直接用深度优先会丢掉祖先节点
{
	if (index >= num.length())
	{
		for (int i = 0; i < path.size(); i++)
			cout << path[i];
		cout << endl;
		return;
	}	
	else
	{
		int len = Server[num[index]].length();
		for (int i = 0; i < len; i++)
		{
			path[index] = Server[num[index]][i];
			print(num, index + 1, Server,path);
		}
	}	
}
int main()
{
	map<char, string> Server;
	pair<char, string> t('1', "+-");
	Server.insert(t);
	t = pair<char, string>('2', "abc");
	Server.insert(t);
	t = pair<char, string>('3', "def");
	Server.insert(t);
	t = pair<char, string>('4', "ghi");
	Server.insert(t);
	t = pair<char, string>('5', "jkl");
	Server.insert(t);
	t = pair<char, string>('6', "mno");
	Server.insert(t);
	t = pair<char, string>('7', "pqrs");
	Server.insert(t);
	t = pair<char, string>('8', "tuv");
	Server.insert(t);
	t = pair<char, string>('9', "wxyz");
	Server.insert(t);

	string num;
	cin >> num;
	vector<char>path(num.length());
	print(num, 0, Server,path);
}