#pragma once
#include"point.h"
#include<iostream>
#include<cmath>
using namespace std;
class circle
{

	public:
		void setheaderpoint(point& a);
		void setheaderpoint(int x, int y);
		void setr(int a);
		point getheader();
		int getr();
		void isccc(point& a);
	private:
		point header;
		int r;
};

