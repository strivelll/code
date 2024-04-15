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
	//ͷ��
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
	//β��
	void Myarray::pushback(int val) {
		if (pcapacity == psize) {
			return;
		}
		parray[psize] = val;
		psize++;
	}
	//ͷɾ
	void Myarray::popfront() {
		if (0 == psize) {
			return;
		}
		for (int i = 0; i<psize; i++) {
			parray[i] = parray[i + 1];
		}
		psize--;
	}
	//βɾ
	void Myarray::popback() {
		if (0 == psize) {
			return;
		}
		psize--;
	}
	//��ȡ����Ԫ�ظ���
	int Myarray::size() {
		return psize;
	}
	//��ȡ��������
	int Myarray::capacity() {
		return pcapacity;
	}
	//ָ��λ�ò���
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
	//��ȡָ��λ�õ�ֵ
	int Myarray::get(int pos) {
		return parray[pos];
	}
	//��ָ��λ���޸�ֵ
	void Myarray::set(int pos, int val) {
		parray[pos] = val;
	}
