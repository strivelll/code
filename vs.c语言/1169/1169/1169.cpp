#define _CRT_SECURE_NO_WARNINGS  1
#pragma warning(disable:6031)
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
int main(){
	int n=1, m=1;
	vector<int> a;
	while (n || m) {
		scanf("%d %d", &n, &m);
		int max = 0;
		for (int i = 0; i < n; i++) {
			int t;
			scanf("%d", &t);
			a.push_back(t)
		}
		if (n <= 3) {
			int sum = 0;
			for (int i = 0; i < n; i++) {
				sum += a[i];
			}
			printf("%d\n", sum);
		}
		else {
			int init = a[0] + a[1] + a[2];
			for (int i = 0; i+m < n; i++) {
				int t=init-a[i]+a[i+m]
					if (t > max) {
						max = t;
					}
			}
			printf("%d\n", max);
		}
	}
	return 0;
} 
