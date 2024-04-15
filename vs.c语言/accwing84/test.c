#define _CRT_SECURE_NO_WARNINGS  1
#pragma warning(disable:6031)
//#include<stdio.h>
//int main()
//{
//	int n,a,b,max=0;
//	int hm[24][60]=0;
//	scanf("%d", &n);
//	while (n--) {
//		scanf("%d %d", &a, &b);
//		hm[a][b]++;
//		if (hm[a][b] > max) {
//			max = hm[a][b];
//		}
//	}
//
//	return 0;
//}
#include<stdio.h>
#include<stdlib.h>
int int_cmp(const void* e1, const void* e2) {
	return *(int*)e1 - *(int*)e2;
}
int main()
{
	int n, m;
	long long a[100000]={0};
	long long b[100000]={0};
	int c[10000][3];
	int sum;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%lld", &a[i]);
		b[i] = a[i];
	}
	
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < 3; j++) {
			scanf("%d", &c[i][j]);
		}
	}
	qsort(b, n, sizeof(b[0]), int_cmp);
	for (int i = 0; i < m; i++) {
			sum = 0;
			if (c[i][0] == 1) {
				for (int k = c[i][1]-1; k < c[i][2];k++) {
					sum += a[k];
				}
			}
			else{
				for (int k = c[i][1]-1; k < c[i][2];k++) {
					sum += b[k];
				}
			}
			printf("%lld\n", sum);
	}
	return 0;
}