#define _CRT_SECURE_NO_WARNINGS  1
#pragma warning(disable:6031)
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
	char n;
	while (scanf(" %c", &n), n != '#') {
		char arr[60][60] = { 0 };
		int count = 1;
		for (int i = 0; i < n - 'A'; i++) {
			count += 2;
		}
		for (int i = 0; i < n - 'A'; i++) {
			for (int j = 0; j <= n - 'A'; j++) {
				arr[i][j] = "A" + j;
			}
			for (int j = 1; j<=n-'A'; j++) {
				arr[i][j] = n - j;
			}
		}
		for (int i = 0; i <count; i++) {
			for (int j = 0; j < count; j++) {
				printf("%c", arr[i][j]);
			}
			printf("\n");
		}
	}
	return 0;
}