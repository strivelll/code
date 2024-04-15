#include"Mystring.h"
int main()
{
	Mystring s1(10, 'a');
	cout << s1 << endl;
	Mystring s2(3, 'b');
	cout << s2 << endl;
	Mystring s3=s1+s2;
	cout << s3 << endl;
	Mystring s4 = s3 + "hello";
	cout << s4 << endl;
	for (int i = 0; i < s4.getsize(); i++) {
		cout << s4[i] << " ";
	}
	cout << endl;
	Mystring s5(5, 'c');
	s4 += "world";
	cout << s4 << endl;
	s4 += s5;
	cout << s4 << endl;
	cin >> s4;
	cout << s4 << endl;
	return 0;
}
