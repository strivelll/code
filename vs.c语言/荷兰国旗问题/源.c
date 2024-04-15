#define _CRT_SECURE_NO_WARNINGS  1
#pragma warning(disable:6031)
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
	int arr[10] = { 4,3,6,2,7,9,7,5,10,8 };
	int len = sizeof(arr) / sizeof(arr[0]);
	int num = 8;
	int s = 0,i=0;
	int end = len - 1;
	while(i<end) {
		if (arr[i] < num) {
			int t = arr[i];
			arr[i++] = arr[s];
			arr[s++] = t;
		}
		else if (arr[i] > num) {
			int t = arr[i];
			arr[i] = arr[end];
			arr[end--] = t;
		}
		else
			i++;
	}
	for (int i = 0; i < len; i++) {
		printf("%d ", arr[i]);
	}
	return 0;
}