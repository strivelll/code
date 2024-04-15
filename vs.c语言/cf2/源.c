#define _CRT_SECURE_NO_WARNINGS  1
#pragma warning(disable:6031)
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//Ò»:¼Ó¼õºÅ
int main()
{
	int n, m;
	char a[100];
	scanf("%d", &n);
	while (n--) {
		int count = 0;
		scanf("%d", &m);
		scanf("%s", a);
		int len = strlen(a);
		for (int i = 0; i < len; i++) {
			if (i != 0) {
				if (a[i] == '1') {
					count++;
				}
				if (count % 2 == 1) {
					printf("-");
				}
				else
					printf("+");
			}
		}
		printf("\n");
	}
	return 0;
}