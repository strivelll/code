#define _CRT_SECURE_NO_WARNINGS  1
#pragma warning(disable:6031)
#include<iostream>
#include<string>
using namespace std;
class student {
public:
	void init() {
		name = "´ä»¨";
		age = 18;
	}
	void setname(string mname) {
		name = mname;
	}
	void setage(int mage) {
		if(mage>=0&&mage<=100)
		age = mage;
	}
	string getname() {
		return name;
	}
	int getage() {
		return age;
	}
	void myprint() {
		cout << "name:" << name << "age:" << age << endl;
	}
private:
	string name;
	int age=0;
};
int main()
{
	student s;
	s.init();
	s.myprint();
	s.setname("666");
	s.setage(101);
	s.myprint();
	cout << "name:" << s.getname() << "age:" << s.getage() << endl;
	return 0;
}