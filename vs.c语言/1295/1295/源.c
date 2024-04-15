#define _CRT_SECURE_NO_WARNINGS  1
#pragma warning(disable:6031)
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int is_prime(int n) {
	if (n == 1)
		return 0;
	for ( int i = 2; i * i <= n; i++)
	{
		if (n % i == 0) {
			return 0;
		}
	}
	return 1;
}
int main()
{
	int T;
	scanf("%d", &T);
	while (T--) {
		int n, i;
		char a[10] = { 0 };
		scanf("%s", &a);
		n = atoi(a);
		if (!is_prime(n)) {
			printf("No\n");
			continue;
		}
		int len=strlen(a),f=0;
		for (int i = 0; i < len; i++) {
			if (a[i] == '0') {
				f = 1;
				break;
			}
		}
		if (f) {
			printf("No\n");
			continue;
		}
		while(len--){
		for (i = 0; i < len; i++) {
			a[i] = a[i + 1];
		}
		a[i] = 0;
			int t = atoi(a);
			if (!is_prime(t)) {
				f = 1;
				printf("No\n");
				break;
			}
		}
		if (!f) {
			printf("Yes\n");
		}

	}
	return 0;
}