#pragma once
#define _CRT_SECURE_NO_WARNINGS  1
#pragma warning(disable:6031)
#include<iostream>
#include<string>
using namespace std;
class Mystring
{
	friend ostream& operator <<(ostream& out, Mystring& str);
	friend istream& operator >>(istream&out, Mystring&str);
public:
	Mystring();
	Mystring(int n, char c);
	Mystring(const Mystring& str);
	Mystring& operator=(const Mystring& str);
	~Mystring();

	Mystring operator+(const Mystring& str);
	Mystring operator+(const char*s);

	Mystring& operator+=(const Mystring& str);
	Mystring& operator+=(const char* s);
	char& operator[](int index);

	int getsize();
private:
	int msize;
	char* mp;
};

