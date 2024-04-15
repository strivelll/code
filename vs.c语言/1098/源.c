#define _CRT_SECURE_NO_WARNINGS  1
#pragma warning(disable:6031)
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
int c[1000001];
int main()
{
	int i, j, k;
	for (i = 2; i < 1000001; i++) {
		c[i] = 1;
	}
	for (i = 2; i < 500001; i++) {
		if (c[i]) {
			for (j = 2;j*i < 1000001; j++) {
				c[j*i] = 0;
			}
		}
	}
	
	scanf("%d", &k);
	while (k--) {
		int count = 0;
		int a, b, t;
		scanf("%d %d", &a, &b);
		if (a > b) {
			 t = b;
			b = a;
			a = t;
		}
		for (int i = a; i <= b; i++) {
			if (c[i]) {
				count++;
			}
		}
		printf("%d\n", count);
	}
	return 0;
}
//暴力方法:
//int isprime(int n) {
//	for (int j = 2; j <= sqrt(n); j++) {
//		if (n % j == 0) {
//			return 0;
//		}
//	}
//	return 1;
//}
//int main()
//{
//	int k,a,b;
//	scanf("%d", &k);
//	while (k--) {
//		int count = 0;
//		scanf("%d %d", &a, &b);
//		for (int i = a; i <= b; i++) {
//			if(isprime(i))
//				count++;
//		}
//		printf("%d\n", count);
//	}
//	return 0;
//}
//优化:
//int main()
//{
//	int k, a, b;
//	scanf("%d", &k);
//	int* c=(int*)calloc(1000000,sizeof(int));
//	if (!c) {
//		return 0;
//	}
//	c[0] = 1;
//	c[1] = 1;
//	for (int i = 2; i <= 1000000; i++) {
//		if (c[i] == 0) {
//			for (int j = 2; j * i < 1000000; j++) {
//				c[i * j] = 1;
//			}
//		}
//	}
//	while (k--) {
//		int count = 0;
//		scanf("%d %d", &a, &b);
//		if (a > b) {
//			int t = b;
//			b = a;
//			a = t;
//		}
//		for (int i = a; i <= b; i++) {
//			if (c[i] == 0) {
//				count++;
//			}
//		}
//		printf("%d\n", count);
//	}
//	if (c != NULL) {
//		free(c);
//		c = NULL;
//	}
//	return 0;
//}