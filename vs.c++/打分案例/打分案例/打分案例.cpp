#define _CRT_SECURE_NO_WARNINGS  1
#pragma warning(disable:6031)
#include<iostream>
#include<vector>
#include<string>
#include<deque>
#include<algorithm>
#include<ctime>
using namespace std;
class student {
public:
	string name;
	int mscore;
};
void create_student(vector<student> &vstu) {
	string s1 = "ABCDE";
	string s2 = "Ñ§Éú";
	for (int i = 0; i < 5; i++) {
		student s;
		s.name = s2 + s1[i];
		s.mscore = 0;
		vstu.push_back(s);
	}
}
void setscore(vector<student>& vstu) {
	srand((unsigned)time(NULL));
	for (vector<student>::iterator it = vstu.begin(); it != vstu.end(); it++) {
		int sc = 0;
		deque<int> dv;
		for (int i = 0; i < 10; i++) {
			dv.push_back(rand() % 70 + 30);
		}
		sort(dv.begin(), dv.end());
		dv.pop_front();
		dv.pop_back();
		for (deque<int>::iterator it = dv.begin(); it != dv.end(); it++) {
			sc += *it;
		}
		it->mscore = sc / dv.size();
	}

}
bool mysort(const student& s1, const student &s2) {
	return s2.mscore < s1.mscore;
}
void showscore(vector<student>& vstu) {
	sort(vstu.begin(), vstu.end(), mysort);
	for (vector<student>::iterator it = vstu.begin(); it != vstu.end(); it++) {
		cout << "name:" << it->name << " " << "score:" << it->mscore<<endl;
	}
}
int main()
{
	vector<student> vstu;
	create_student(vstu);
	setscore(vstu);
	showscore(vstu);
	return 0;
}