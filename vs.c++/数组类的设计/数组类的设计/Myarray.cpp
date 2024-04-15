#include "Myarray.h"
	Myarray::Myarray()
	{
		this->psize = 0;
		pcapacity = 20;
		parray = new int[pcapacity];
		for (int i = 0; i < psize; i++) {
			parray[i] = 0;
		}
	}
	Myarray::Myarray(const Myarray& arr) {
		psize = arr.psize;
		pcapacity = arr.pcapacity;
		parray = new int[pcapacity];
		for (int i = 0; i < psize; i++) {
			parray[i] = arr.parray[i];
		}
	}
	Myarray::Myarray(int capacity, int val) {
		psize = capacity;
		pcapacity = capacity;
		parray = new int[pcapacity];
		for (int i = 0; i < psize; i++) {
			parray[i] = val;
		}
	}
	Myarray::~Myarray() {
		if (parray != NULL) {
			delete[] parray;
			parray = NULL;
		}
	}
	//头插
	void Myarray::pushfront(int val) {
		if (pcapacity == psize) {
			return;
		}
		for (int i = psize; i > 0; i--) {
			parray[i] = parray[i - 1];
		}
		parray[0] = val;
		psize++;
	}
	//尾插
	void Myarray::pushback(int val) {
		if (pcapacity == psize) {
			return;
		}
		parray[psize] = val;
		psize++;
	}
	//头删
	void Myarray::popfront() {
		if (0 == psize) {
			return;
		}
		for (int i = 0; i<psize; i++) {
			parray[i] = parray[i + 1];
		}
		psize--;
	}
	//尾删
	void Myarray::popback() {
		if (0 == psize) {
			return;
		}
		psize--;
	}
	//获取数组元素个数
	int Myarray::size() {
		return psize;
	}
	//获取数组容量
	int Myarray::capacity() {
		return pcapacity;
	}
	//指定位置插入
	void Myarray::insert(int pos, int val) {
		if (pcapacity == psize) {
			return;
		}
		if (pos<0 || pos>psize - 1) {
			pos = psize;
		}
		for (int i = psize; i > pos; i--) {
			parray[i] = parray[i - 1];
		}
		parray[pos] = val;
		psize++;
	}
	//获取指定位置的值
	int Myarray::get(int pos) {
		return parray[pos];
	}
	//在指定位置修改值
	void Myarray::set(int pos, int val) {
		parray[pos] = val;
	}
