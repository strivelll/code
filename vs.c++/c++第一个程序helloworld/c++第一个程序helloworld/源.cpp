#define _CRT_SECURE_NO_WARNINGS  1
#pragma warning(disable:6031)
#include<iostream>
using namespace std;
int main()
{
	cout << "hello world!" << endl;
	int c = 100;
	int* s = &c;
	int*& ss = s;
	cout << *ss << endl;

	int a = 10;
	const int b = a;
	int* p = (int*)&b;
	*p = 100;
	cout << "b=" << &b << endl;
	cout << "b=" << p << endl;
	return 0;
}