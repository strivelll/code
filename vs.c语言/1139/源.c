#define _CRT_SECURE_NO_WARNINGS  1
#pragma warning(disable:6031)
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
	int k;
	scanf("%d", &k);
	while (k--) {
		int n;
		scanf("%d", &n);
		int f=0;
		int k = n;
		for (int i = 2; i*i<n; i++) {
			if (k%i==0) {
				k /= i;f = 1;
				//这里一定要取=;如9,不取=则会判断为素数;
				for (int j = 2; j*j <= k; j++) {
					if (k % j == 0) {
						f = 0;
						break;
					}
				}
				break;
			}
		}
		if (f==0) {
			printf("No\n");
		}
		else
			printf("Yes\n");
	}
	return 0;
}
//int a[10001];
//int main()
//{
//	for (int i = 2; i < 10001; i++) {
//		a[i] = 1;
//	}
//	for (int i = 2; i < 10001; i++) {
//		if (a[i]) {
//			for (int j = 2; j*i < 10001; j++) {
//				a[i * j] = 0;
//			}
//		}
//	}
//	int k;
//	scanf("%d", &k);
//	while (k--) {
//		int n;
//		scanf("%d", &n);
//		int f,k = n;
//		for (int i = 2; i< sqrt(n); i++) {
//			f = 0;
//			if (a[i]) {
//				while (k % i == 0) {
//					f = 1;
//					if ( a[k /= i]) {
//						printf("Yes\n");
//					}
//					else printf("No\n");
//					break;
//				}
//				if (f)break;
//			}
//		}
//		if (k == n) {
//			printf("No\n");
//		}
//	}
//	return 0;
//}