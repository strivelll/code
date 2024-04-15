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
		int x;
		char arr[32] = {0};
		scanf("%d", &x);
		if (x == 0) {
			printf("%d\n", x);
			continue;
		}
		int j = 31;
		while (x) {
			int t = x % 3;
			x /= 3;
			arr[j--] = t;
		}
		for (int i =31; i>j; i--) {
			if (arr[i] == 3) {
				arr[i] = 0;
				arr[i - 1]++;
				j--;
			}
			if (arr[i] == 2) {
				arr[i] = -1;
				arr[i - 1] += 1;
				j--;
			}
		}
		for (int i = j + 1; i < 32; i++) {
			if (arr[i] != 0) {
				j = i - 1;
				break;
			}
		}
		for (int i =j+1; i<32; i++) {
			if (arr[i] == -1) {
				printf("-");
			}
			else
			printf("%d", arr[i]);
		}
		printf("\n");
	}
	return 0;
}