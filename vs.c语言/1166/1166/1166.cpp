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
		int ans = 0;
		if (n == 0) {
			break;
		}
		int a[1000];
		for (int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
		}
		for (int i = 0; i < n; i++) {
			for (int j = i+1; j < n; j++) {
				if (a[i] > a[j]) {
					ans++;
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
} 
