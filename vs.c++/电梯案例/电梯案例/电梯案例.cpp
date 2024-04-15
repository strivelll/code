#define _CRT_SECURE_NO_WARNINGS  1
#pragma warning(disable:6031)
#include<iostream>
#include<vector>
#include<queue>
#include<list>
#include<ctime>
#include<string>
using namespace std;
int main() {
	int num;
	while (1) {
		cin >> num;
		if (num > 0 && num < 10) {
			cout << "输入正确" << endl;
			break;
		}
		cout<<"重新输入"<<endl;
		cin.clear();
		char buf[1024] = { 0 };
		cin.getline(buf, 1024);
	}
	return 0;
}

//class student {
//public:
//	string name;
//};
//void createstudent( queue<student>& que, int num) {
//	string n1 = "ABCDEFGHIJKLMN";
//	int s = rand() % 10;
//	char buf[64] = { 0 };
//	sprintf(buf, "%d", num);
//	string s1(buf);
//	for (int i = 0; i < s; i++) {
//		student ss;
//		string n2;
//		n2 += "第";
//		n2 += s1;
//		n2 += "层用户";
//		n2 += n1[rand() % 14];
//		ss.name = n2;
//		que.push(ss);
//	}
//}
//int pushmylist(list<student>& mylist, queue<student>& que, vector<student>& vc) {
//	int temp = 0;
//	if (mylist.size() < 15) {
//		while (!que.empty()) {
//			mylist.push_back(que.front());
//			vc.push_back(que.front());
//			que.pop();
//			temp++;
//		}
//	}
//	return temp;
//}
//int  popmylist(list<student>& mylist, vector<student>& vc, int num) {
//	int sum = rand() % 5;
//	int temp = 0;
//	if (num == 17) {
//		temp = mylist.size();
//		while (!mylist.empty()) {
//			vc.push_back(mylist.front());
//			mylist.pop_front();
//		}
//	}
//	if (mylist.size() != 0&&sum<= (int)mylist.size()) {
//		for (int i = 0; i < sum; i++) {
//			int t = rand()%mylist.size();
//			vc.push_back(mylist.front());
//			mylist.pop_front();
//			temp++;
//		}
//	}
//	return temp;
//}
//void myvectorprint(vector<student>& vec) {
//	for (vector<student>::iterator it = vec.begin(); it != vec.end(); it++) {
//		cout << "name:" << (*it).name << endl;
//	}
//}
//int main()
//{
//	srand((unsigned int)time(NULL));
//	list<student> mylist;
//	int pushnum = 0;
//	int popnum = 0;
//	vector<student>pushv;
//	vector<student>popv;
//	for (int i = 1; i < 18; i++) {
//		queue<student>que;
//		createstudent(que,i);
//		if (mylist.size() <= 15&&i<17) {
//			pushnum+=pushmylist(mylist,que,pushv);
//		}
//		if (mylist.size()>1) {
//			popnum += popmylist(mylist,popv,i);
//		}
//	}
//	cout << "进电梯的总人数:" <<pushnum<< endl;
//	myvectorprint(pushv);
//	cout << "出电梯的总人数:" << popnum << endl;
//	myvectorprint(popv);
//	return 0;
//}