#define _CRT_SECURE_NO_WARNINGS  1
#pragma warning(disable:6031)
#include<iostream>
using namespace std;
int main()
{
	int n;
	while (cin >> n, n) {
		if (n / 1000) {
			int r = n / 1000;
			for (int i = 0; i < r; i++) {
				cout << "M";
			}
			n %= 1000;
		}
		if (n / 100) {
			int r = n / 100;
			if (r == 9) {
				cout << "CM";
				r -= 9;
			}
			else if (r >= 5) {
				cout << "D";
				r -= 5;
			}
			else if (r == 4) {
				cout << "CD";
				r -= 4;
			}
				for (int i = 0; i < r; i++) {
					cout << "C";
				}
				n %= 100;
		}
		if (n / 10) {
			int r = n / 10;
			if (r == 9) {
				cout << "XC";
				r -= 9;
			}
			else if (r >= 5) {
				cout << "L";
				r -= 5;
			}
			else if (r == 4) {
				cout << "XL";
				r -= 4;
			}
			for (int i = 0; i < r; i++) {
				cout << "X";
			}
			n %= 10;
		}
		if (n == 9) {
			cout << "IX";
			n -= 9;
		}
		else if (n >= 5) {
			cout << "V";
			n -= 5;
		}
		else if (n == 4) {
			cout << "IV";
			n -= 4;
		}
		for (int i = 0; i < n; i++) {
			cout << "I";
		}
		cout << endl;
	}
	return 0;
}