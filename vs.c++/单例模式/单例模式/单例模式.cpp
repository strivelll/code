#define _CRT_SECURE_NO_WARNINGS  1
#pragma warning(disable:6031)
#include<iostream>
using namespace std;
#include<string>
class mater {
	mater() {
		count = 0;
	}
	mater(mater& p) {
		//count = 0;
	}
public:
	static mater* getmater() {
		return pmater;
	}
	void print(string name) {
		cout << ":" << name << endl;
		count++;
	}
	int countnum() {
		return count;
	}
private:
	static mater* pmater;
	int count;
};
mater* mater::pmater = new mater;
int main()
{
	mater* m1 = mater::getmater();
	m1->print("张三");
	mater* m2 = mater::getmater();
	m2->print("李四");
	mater* m3 = mater::getmater();
	m3->print("王五");
	mater* m4 = mater::getmater();
	cout << "打印次数:" << m4->countnum() << endl;
	return 0;
}