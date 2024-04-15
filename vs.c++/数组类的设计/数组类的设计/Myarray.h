#pragma once
#include<iostream>
using namespace std;
class Myarray
{
public:
	Myarray();
	Myarray(const Myarray & arr);
	Myarray(int capacity, int val = 0);
	~Myarray();
	//头插
	void pushfront(int val);
	//尾插
	void pushback(int val);
	//头删
	void popfront();
	//尾删
	void popback();
	//获取数组元素个数
	int size();
	//获取数组容量
	int capacity();
	//指定位置插入
	void insert(int pos,int val);
	//获取指定位置的值
	int get(int pos);
	//在指定位置修改值
	void set(int pos, int val);
private:
	int psize;
	int pcapacity;
	int* parray;
};

