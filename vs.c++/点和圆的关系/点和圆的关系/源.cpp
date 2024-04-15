#define _CRT_SECURE_NO_WARNINGS  1
#pragma warning(disable:6031)
#include<iostream>
#include"circle.h"
using namespace std;
void iscc(circle& c,point& s) {
	int k = (s.getx() - c.getheader().getx()) * (s.getx() - c.getheader().getx()) + (s.gety() - c.getheader().gety()) * (s.gety() - c.getheader().gety());
	if (k > c.getr() * c.getr()) {
		cout << "全局 点在圆外" << endl;
	}
	else if (k == c.getr() * c.getr()) {
		cout << "全局 点在圆上" << endl;
	}
	else
		cout << "全局 点在圆内" << endl;
}
int main()
{
	point s,d;
	circle c;
	s.setx(6);
	s.sety(6);
	/*d.setx(2);
	d.sety(3);*/
	c.setr(5);
	c.setheaderpoint(2,3);
	c.isccc(s);
	iscc(c, s);
	return 0;
}