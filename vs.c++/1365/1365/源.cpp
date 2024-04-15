#define _CRT_SECURE_NO_WARNINGS  1
#pragma warning(disable:6031)
#include<iostream>
using namespace std;

int main()
{
	int t;
	cin >> t;
	
	while (t--) {
		int max = 0;
		int a[4][4];
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				cin >> a[i][j];
			}
		}
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 3; j++) {
				for (int k = 0; k < 3; k++) {
					if (a[j][k] + a[j][k + 1] + a[j + 1][k] + a[j + 1][k + 1] > max) {
						max = a[j][k] + a[j][k + 1] + a[j + 1][k] + a[j + 1][k + 1];
					}
				}
			}
			int b = a[1][1],c=a[1][2],d=a[2][1],e=a[2][2];
			a[1][1] = d;
			a[1][2] = b;
			a[2][1] = e;
			a[2][2] = c;
		}
		cout << max << endl;
	}
	return 0;
}
