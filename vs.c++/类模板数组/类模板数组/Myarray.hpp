#pragma once
#define _CRT_SECURE_NO_WARNINGS  1
#pragma warning(disable:6031)
#include<iostream>
#include<string>
using namespace std;
template<class T>
class Myarray 
{
public:
	Myarray(int capacity) {
		msize = 0;
		mcapacity = capacity;
		mp = new T[capacity];
	}
	Myarray(Myarray& a) {
		msize = a.msize;
		mcapacity = a.mcapacity;
		mp = new T[a.mcapacity];
		for (int i = 0; i < a.msize; i++) {
			mp[i] = a.mp[i];
		}
	}
	Myarray& operator = (const Myarray & a)
	{
		if (mp != NULL) {
			delete[] mp;
		}

	msize = a.msize;
	mcapacity = a.mcapacity;
		mp = new T[a.mcapacity];
		for (int i = 0; i < a.msize; i++) {
			mp[i] = a.mp[i];
		}
		return *this;
	}
	void push_back(const T& m)
	{
		if (msize == mcapacity) {
			return;
		}
		mp[msize++] = m;
	}
	void pop_back() {
		if (msize == 0) {
			return;
		}
		msize--;
	}
	T& operator[](int index) {
		return mp[index];
	}
	int getsize() {
		return msize;
	}
	int getcapacity() {
		return mcapacity;
	}
	~Myarray() {
		if (mp != NULL) {
			delete[] mp;
		}
	}
private:
	T *mp;
	int msize;
	int mcapacity;
};