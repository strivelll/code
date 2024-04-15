#define _CRT_SECURE_NO_WARNINGS  1
#pragma warning(disable:6031)
#include"Myarray.h"
void myprint(Myarray &a) {
	for (int i = 0; i < a.size(); i++) {
		cout << a.get(i)<<' ';
	}
	cout << endl;
}
int main()
{
	Myarray a;
	a.pushfront(5);
	a.pushback(5);
	myprint(a);
	a.pushfront(4);
	a.pushback(6);
	myprint(a);
	a.popfront();
	a.popback();
	myprint(a);
	a.insert(1, 7);
	myprint(a);
	cout << a.get(1) << endl;
	cout <<"ÈÝÁ¿: "<< a.capacity() << endl;
	cout <<"´óÐ¡: "<< a.size() << endl;
	a.set(1, 8);
	myprint(a);
	return 0;
}