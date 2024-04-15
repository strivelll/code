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
		int n1 = n;
		int count = 0;
		while (n1) {
			count++;
			n1 /= 10;
		}
		int min = count * 9 > n ? n : count * 9;
		int f = 1;
		for (int i = n - min; i < n; i++) {
			int sum = i;
			int j = i;
			while (j) {
				sum += j % 10;
				j /= 10;
			}
			if (sum == n) {
				f = 0;
				printf("No\n");
				break;
			}
		}
		if (f)printf("Yes\n");
	}
	return 0;
}