#pragma  warning (disable: 4996)
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <iostream>
using namespace std;
//学习心得
/*
* operator 有两种理解方式，本质上都是函数operator(first,second),当first为this时，就是该类中的成员函数；
该类没法再添加时，可以直接添加一个全局函数，显式声明；
* 构造string时，char*表示的字符串至少有一个‘\0’，strlen()返回数字不包括该值，strcpy()时需要为该结尾预留空间
*/
class myString
{
public:
	myString(char* p= NULL);
	myString(const myString& another);
	myString& operator=(const myString& another);
	myString operator+(const myString& another);
	int length();
	friend ostream& operator<<(ostream&, myString&);
	friend istream& operator>>(istream&, myString&);
	char* c_str() const;
	char& myString::operator[](int);
	~myString();
private:
	char* m_char;
};



myString::myString(char* p)
{
	if (p)
	{
		m_char = new char[strlen(p)+1];
		strcpy(m_char,p);
	}
	else
	{
		m_char = new char;
		m_char = '\0';
	}
}
myString::myString(const myString& another)
{
    m_char = new char[strlen(another.m_char)+1];
    strcpy(m_char, another.m_char);
}
myString& myString::operator=(const myString& another)
{
	if (another.m_char != m_char)
	{
		delete[] m_char;
		m_char = new char[strlen(another.m_char)+1];
		strcpy(m_char, another.m_char);
	}
	return *this;
}
myString myString::operator+(const myString& another)
{
	char* p = new char[strlen(m_char) + strlen(another.m_char) + 1];
	strcpy(p, m_char);
	strcat(p, another.m_char);
	return myString(p);
}
int myString::length()
{
	return strlen(m_char);
}

ostream& operator<<(ostream& cout, myString& another)
{
	cout << another.m_char;
	return cout;
}
istream& operator>>(istream& cin , myString& another)
{
	char buffer[1024];
	cin >> buffer;
	delete[] another.m_char;
	another.m_char = new char[strlen(buffer) + 1];
	strcpy(another.m_char, buffer);
	return cin;
}
char* myString::c_str() const
{
	return m_char;
}
char& myString::operator[](int i)
{
	if (i < strlen(m_char))
		return m_char[i];
	else
		throw -1;
}


myString::~myString()
{
    delete[] m_char;
}
int main()
{
	cout << "input a string" << endl;
	myString A;
	cin >> A;
	cout << "input another string" << endl;
	myString B;
	cin >> B;
	myString C(A);
	cout << "copy constrcutor:" << endl;
	cout << C<<endl;
	C = B;
	cout << "operator=:" << endl;
	cout << C<<endl;
	C = A + B;
	cout << "operator+:" << endl;
	cout << C << endl;
	for (int i = 0; i < C.length(); i++)
	{
		cout << C[i] << "+";
	}
	cout << endl;
	return 0;
}