#define _CRT_SECURE_NO_WARNINGS  1
#pragma warning(disable:6031)
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
int main() {
	int n = 1, m = 1;
	while (1) {
		vector<int> a;
		scanf("%d %d", &n, &m);
		if (n == 0 && m == 0) {
			break;
		}
		int max = 0;
		for (int i = 0; i < n; i++) {
			int t;
			scanf("%d", &t);
			a.push_back(t);
		}
		int init=0;
		for (int i = 0; i < m; i++) {
			init += a[i];
		}
		max = init;
		for (int i = 0; i + m < n; i++) {
				init = init - a[i] + a[i + m];
				if (init > max) {
					max = init;
				}
		}
			printf("%d\n", max);
	}
	return 0;
}
