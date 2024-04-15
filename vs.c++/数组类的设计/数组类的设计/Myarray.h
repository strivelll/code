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
	//ͷ��
	void pushfront(int val);
	//β��
	void pushback(int val);
	//ͷɾ
	void popfront();
	//βɾ
	void popback();
	//��ȡ����Ԫ�ظ���
	int size();
	//��ȡ��������
	int capacity();
	//ָ��λ�ò���
	void insert(int pos,int val);
	//��ȡָ��λ�õ�ֵ
	int get(int pos);
	//��ָ��λ���޸�ֵ
	void set(int pos, int val);
private:
	int psize;
	int pcapacity;
	int* parray;
};

