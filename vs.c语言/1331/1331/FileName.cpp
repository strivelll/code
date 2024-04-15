#define _CRT_SECURE_NO_WARNINGS  1
#pragma warning(disable:6031)
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
	int k;
	scanf("%d", &k);
	while (k--) {
		int n;
		scanf("%d", &n);
		if (n <= 0) {
			printf("0\n");
			continue;
		}
		if (n == 1) {
			printf("4\n");
			continue;
		}
		__int64 x = 2, y = 2;
		for (int i = 2; i < n; i++) {
			__int64 t = x,m=y;
			x = 2 * m;
			y = 2 * t + m;
		}
		printf("%I64d\n", x * 2 + y * 3);
	}
	return 0;
} 
