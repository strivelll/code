#include "Mystring.h"
ostream& operator <<(ostream& out, Mystring& str) {
	out << str.mp;
	return out;
}
istream& operator >>(istream& in, Mystring& str) {
	char t[1024] = { 0 };
	in >> t;
	if (str.mp) {
		delete[] str.mp;
		str.mp = NULL;
	}
	str.mp = new char[strlen(t) + 1];
	memset(str.mp, 0, strlen(t) + 1);
	strcpy(str.mp, t);
	str.msize = strlen(t);
	return in;
}
Mystring::Mystring() {
	msize = 0;
	mp = new char[1];
	mp[0] = '\0';
}
Mystring::Mystring(int n, char c) {
	msize = n;
	mp = new char[n + 1];
	for (int i = 0; i < n; i++) {
		mp[i] = c;
	}
	mp[n] = '\0';
}
Mystring::Mystring( const Mystring& str) {
	mp = new char[strlen(str.mp)+1];
	strcpy(mp, str.mp);
	msize = str.msize;
}
Mystring& Mystring:: operator=(const Mystring& str) {
	if (mp) {
		delete[] mp;
		mp = NULL;
	}
	mp = new char(str.msize + 1);
	strcpy(mp, str.mp);
	msize = str.msize;
	return *this;
}
Mystring::~Mystring() {
	if (this->mp!=NULL) {
		delete[] this->mp;
		this->mp = NULL;
	}
}
Mystring Mystring:: operator+(const Mystring& str) {
	Mystring t;
	if (t.mp) {
		delete[] t.mp;
		t.mp = NULL;
	}
	t.mp= new char[msize + str.msize];
	memset(t.mp, 0, msize + str.msize);
	strcat(t.mp, mp);
	strcat(t.mp, str.mp);
	t.msize = msize + str.msize;
	return t;
}
Mystring Mystring:: operator+(const char* s) {
	Mystring t;
	if (t.mp) {
		delete[] t.mp;
		t.mp = NULL;
	}
	t.mp = new char[msize + strlen(s)];
	memset(t.mp, 0, msize + strlen(s) + 1);
	strcat(t.mp, mp);
	strcat(t.mp, s);
	t.msize = msize + strlen(s);
	return t;
}
Mystring& Mystring:: operator +=(const Mystring& str) {
	int newstrlen = str.msize + msize;
	char* newspace = new char[newstrlen+1];
	memset(newspace, 0, newstrlen);
	strcat(newspace,mp);
	strcat(newspace, str.mp);
	if (mp) {
		delete[] mp;
		mp = NULL;
	}
	mp = newspace;
	msize = newstrlen;
	return *this;
}
Mystring& Mystring:: operator+=(const char* s) {
	int newstrlen = strlen(s) + msize;
	char* newspace = new char[newstrlen + 1];
	memset(newspace, 0, newstrlen);
	strcat(newspace, mp);
	strcat(newspace, s);
	if (mp) {
		delete[] mp;
		mp = NULL;
	}
	mp = newspace;
	msize = newstrlen;
	return *this;
}
int Mystring::getsize() {
	return msize;
}
char& Mystring::operator[ ](int index) {
	return mp[index];
}