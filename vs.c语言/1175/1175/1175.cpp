#define _CRT_SECURE_NO_WARNINGS  1
#pragma warning(disable:6031)
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
	int n=1;
	while (n) {
		scanf("%d", &n);
		vector<int> x, y;
		int up = 0, down = 0, bb = 0;
		if (n == 0) {
			break;
		}
		for (int i = 0; i < n; i++) {
			int t;
			scanf("%d", &t);
			x.push_back(t);
		}
		for (int i = 0; i < n; i++) {
			int t;
			scanf("%d", &t);
			y.push_back(t);
		}
		for (int i = 0; i < n; i++) {
			if (y[i] - x[i] > 0) {
				up++;
			}
			else if (y[i] - x[i] == 0) {
				bb++;
			}
			else {
				down++;
			}
		}
		printf("%d %d %d\n", up, bb, down);
	}

	return 0;
} 
