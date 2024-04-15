#define _CRT_SECURE_NO_WARNINGS  1
#pragma warning(disable:6031)
#include<iostream>
#include<string>
#include<stdexcept>
using namespace std;
class My_out:public exception {
public:
	My_out(const char* errorinfo) {
		my_info = string(errorinfo);
	}
	My_out(const string errorinfo) {
		my_info = errorinfo;
	}
	const char* what() {
		return my_info.c_str();
	}
public:
	string my_info;
};
class Mater {
public:
	Mater(int age) {
		if (age < 0 || age>200) {
			//throw My_out("自己的类,年龄超出范围");
			throw out_of_range("年龄超出范围");
		}
		else
			this->age = age;
	}
public:
	int age;
};
void test() {
	Mater(-1);
}
int main()
{
	try {
		test();
	}
	/*catch (My_out& ex) {
		cout << ex.what() << endl;
	}*/
	catch (out_of_range& ex) {
		cout << ex.what() << endl;
	}
	return 0;
}