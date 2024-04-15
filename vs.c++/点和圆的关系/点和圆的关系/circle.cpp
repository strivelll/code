#include "circle.h"
	void circle::setheaderpoint(point &a) {
		header = a;
	}
	void circle::setheaderpoint(int x,int y) {
		header.setx(x);
		header.sety(y);
	}
	point circle::getheader() {
		return header;
	}
	void circle::setr(int a) {
		r = a;
	}
	int circle::getr() {
		return r;
	}
	void circle::isccc(point& a) {
		if (pow(a.getx() - header.getx(), 2) + pow(a.gety() - header.gety(), 2) > pow(r, 2)) {
			cout << "点在圆外" << endl;
		}
		else if (pow(a.getx() - header.getx(), 2) + pow(a.gety() - header.gety(), 2) == pow(r, 2)) {
			cout << "点在圆上" << endl;
		}
		else
			cout << "点在圆内" << endl;
	}