#define _CRT_SECURE_NO_WARNINGS  1
#pragma warning(disable:6031)
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void insert_px(int arr[],int len) {
	for (int i = 1; i < len; i++) {
		if (arr[i] < arr[i - 1]) {
			int temp = arr[i];
			int j;
			for (j = i - 1; j >= 0 && arr[j] > temp;j--) {
				arr[j + 1] = arr[j];
			}
			arr[j + 1] = temp;
		}
	}
}
int main()
{
	int arr[10] = { 4,7,2,3,9,10,5,1,6,8 };
	int len = sizeof(arr) / sizeof(arr[0]);
	insert_px(arr,len);
	for (int i = 0; i < len; i++) {
		printf("%d ", arr[i]);
	}
	return 0;
}