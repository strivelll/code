#define _CRT_SECURE_NO_WARNINGS  1
#pragma warning(disable:6031)
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int c[1010][1010] = { 0};
int ans[1000] = { 0 };
int s[1000] = { 0 };
int Min(int arr[],int len) {
	int min = 2001;
	int t = 0;
	for (int i = 0; i < len; i++) {
		if (min > arr[i]&&!s[i]) {
			min = arr[i];
			t= i;
		}
	}
	return t;
}
int main()
{
	int n, m;
	for (int i = 0; i < 1010; i++) {
		for (int j = 0; j < 1010; j++) {
			c[i][j] = 2001;
		}
	}
	c[0][0] = 0;
	scanf("%d %d", &n, &m);
	while (m--) {
		int a, b, x;
		scanf("%d %d %d", &a, &b, &x);
		c[a-1][b-1] = x;
		c[b-1][a-1] = x;
	}
	for (int j = 0; j < n; j++) {
			if(!s[j])
			ans[j] = c[0][j];
		}
	int z = n;
	while(z--){
		int t = Min(ans, n);
		s[t] = 1;
		int y = ans[t];
		for (int k = 0; k < n; k++) {
			if(!s[k])
			ans[k] = ans[k] > y + c[t][k] ? y + c[t][k] : ans[k];
		}
	}
	printf("%d\n", ans[n - 1]);
	return 0;
}