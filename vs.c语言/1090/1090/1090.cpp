#define _CRT_SECURE_NO_WARNINGS  1
#pragma warning(disable:6031)
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

__int64 jiechen(int n,int x) {
	__int64 ans = 1;
	if (n == 0||x==0) {
		return 1;
	}
	for (int i = n; i >n-x; i--) {
		ans *= i;
	}
	return ans;
}
int main(){
	int n = 1;
	while (n) {
		scanf("%d", &n);
		__int64 a[35];
		for (int i = 0; i <= n; i++) {
			a[i] = jiechen(n,i) /jiechen(i,i);
		}
		printf("2^%d=", n);
		for (int i = 0; i <= n; i++) {
			if (i != n) {
				printf("%I64d+", a[i]);
			}
			else {
				printf("%I64d\n", a[i]);
			}
		}
	}
	return 0;
} 
