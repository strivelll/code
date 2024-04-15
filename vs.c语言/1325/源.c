#define _CRT_SECURE_NO_WARNINGS  1
#pragma warning(disable:6031)
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
	int T;
	scanf("%d", &T);
	while (T--) {
		int n,j=0,count=0;
		int arr[32] = {0};
		scanf("%d", &n);
		while (n) {
			int t=n % 2;
			n /= 2;
			arr[j++] = t;
		}
		for (int i = 0; i < j; i++) {
			if (arr[i] == 1) {
				count++;
			}
		}
		if (count <=j/2) {
			printf("0\n");
		}
		else
			printf("%d\n", 2 * count - j);
	}
	return 0;
}