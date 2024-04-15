#define _CRT_SECURE_NO_WARNINGS  1
#pragma warning(disable:6031)
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int x1[10010];
int y1[10010];
int main()
{
	int T;
	scanf("%d", &T);
	while (T--) {
		int n, m, x, y, k ;
		memset(x1, 0, sizeof(int) * 10010);
		memset(y1, 0, sizeof(int) * 10010);
		scanf("%d %d %d", &n, &m, &k);
		int n1 = n,m1=m,count=0;
		for (int i = 0; i < k; i++) {
			scanf("%d %d", &x, &y);
			if (x1[x] == 0) {
				x1[x] = 1;
				n1--;
			}
			if (y1[y] == 0) {
				y1[y] = 1;
				m1--;
			}
		}
		count += n1 * m;
		count += m1 * (n-n1);
		printf("%d\n", count);
	}
	return 0;
}