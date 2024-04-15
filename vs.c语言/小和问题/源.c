#define _CRT_SECURE_NO_WARNINGS  1
#pragma warning(disable:6031)
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int mage(int arr[], int l, int mid, int r) {
	int sum=0;
	int help[10] = {0};
	int i = 0;
	int p1 = l;
	int p2 = mid + 1;
	while (p1 <= mid && p2 <= r) {
		sum += arr[p1] < arr[p2] ? (r-p2+1)*arr[p1] : 0;
		help[i++] = arr[p1] < arr[p2] ? arr[p1++] : arr[p2++];
	}
	while (p1 <= mid) {
		help[i++] = arr[p1++];
	}
	while (p2 <= r) {
		help[i++] = arr[p2++];
	}
	for (i = 0; i < r - l + 1; i++) {
		arr[l + i] = help[i];
	}
	return sum;
}
int process(int arr[], int l, int r) {
	if (l == r) {
		return 0;
	}
	int mid = l + ((r - l) >> 1);
	return process(arr, l, mid)+process(arr, mid + 1, r)+mage(arr, l, mid, r);
}
int main()
{
	int arr[10] = { 4,3,6,2,1,9,7,5,10,8 };
	int len = sizeof(arr) / arr[0];
	printf("%d ", process(arr, 0, len - 1));
	return 0;
}