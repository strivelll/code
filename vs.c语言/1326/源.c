#define _CRT_SECURE_NO_WARNINGS  1
#pragma warning(disable:6031)
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int jh(int x,int y) {
	if (y == 0) {
		return x;
	}
	else {
		return jh(y, x % y);
	}
}
int main()
{
	char arr[1001] = { 0 };
	
	while (scanf("%s", arr)!=EOF) {
		int arr1[30] = { 0 };
		int max = 0;
		for (int i = 0; arr[i]!='\0'; i++) {
			arr1[arr[i] - 'A']++;
		}
		int p=arr1[0];
		for(int i = 1; i < 26; i++) {
			p = jh(arr1[i], p);
		}
		for (int i = 0; i < 26; i++) {
			arr1[i] /= p;
			if (arr1[i] > arr1[max]) {
				max = i;
			}
		}
		int max1 = arr1[max];
		while (max1) {
			int f = 1;
				for (int i = 0; i < 26; i++) {
					if (f) {
						if (arr1[i]) {
							if (arr1[i] - max1 >= 0) {
								printf("*");
								for (int j = i + 1; j < 26; j++) {
									if (arr1[j] - max1 < 0) {
										if (j == 25) {
											f = 0;
											break;
										}
										continue;
									}
									else {
										break;
									}
								}
							}
							else
								printf(" ");
						}
					}
				}
			printf("\n");
			max1--;
		}
		for (int i = 0; i < 26; i++) {
			if (arr1[i]) {
				printf("%c", i + 'A');
			}
		}
		printf("\n\n");
	}
	return 0;
}