#define _CRT_SECURE_NO_WARNINGS  1
#pragma warning(disable:6031)
#include<iostream>
#include<map>
#include<vector>
#include<string>
#include<ctime>
using namespace std;
enum {
	SALE_DEPATMENT=1,
	DEVELOP_DEPATMENT,
	FINACIAL_DEPATIMENT
};
class woker {
//public:
//	woker() {};
//	woker(woker& m) {
//		this->name = m.name;
//		this->age = m.age;
//		this->salary = m.salary;
//	}
public:
	string name;
	int age;
	int salary;
};
void createwoker(vector<woker>& vwoker) {
	
	string p = "ABCDE";
	for (int i = 0; i < 5; i++) {
		woker w;
		w.age = rand() % 20 + 20;
		w.name = "员工";
		w.name += p[i];
		w.salary = rand() % 20000 + 20000;
		vwoker.push_back(w);
	}
}
void wokerbygroup(vector<woker>& vwoker, multimap<int, woker>& mwoker) {
	for (vector<woker>::iterator it = vwoker.begin(); it != vwoker.end(); it++) {
		int id = rand() % 3 + 1;
		mwoker.insert(multimap<int, woker>::value_type(id, *it));

	}
}
void mygroup(multimap<int, woker>& mwoker,int id) {
	multimap<int, woker>::iterator it = mwoker.find(id);
	int mcount = mwoker.count(id);
	int index = 0;
	for (; it != mwoker.end()&&index<mcount; index++,it++) {
		cout << "name:" << it->second.name << " age:" << it->second.age << " salary:" << it->second.salary << endl;
	}

}
void printwoker(multimap<int, woker>& mwoker) {
	cout << "财务部门:" << endl;
	mygroup(mwoker, FINACIAL_DEPATIMENT);
	cout << "研发部门:" << endl;
	mygroup(mwoker, DEVELOP_DEPATMENT);
	cout << "销售部门:" << endl;
	mygroup(mwoker, SALE_DEPATMENT);


}
int main()
{
	srand((unsigned int)time(NULL));
	vector<woker> vwoker;
	multimap<int,woker> mwoker;
	createwoker(vwoker);
	wokerbygroup(vwoker, mwoker);
	printwoker(mwoker);
	return 0;
}