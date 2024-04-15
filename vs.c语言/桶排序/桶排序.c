#define _CRT_SECURE_NO_WARNINGS  1
#pragma warning(disable:6031)
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int getmax(int arr[],int len) {
	int max = 0;
	for (int i = 0; i < len; i++) {
		int count = 0;
		int n = arr[i];
		while (n) {
			n /= 10;
			count++;
		}
		if (count > max) {
			max = count;
		}
	}
	return max;
}
int getnum(int n,int digit) {
	digit--;
	while (digit--) {
		n /= 10;
	}
	return n % 10;
}
void toquque(int arr[],int l,int r,int digit) {
	int help[10] = { 0 };
	for (int i = 1; i <= digit; i++) {
		int count[10] = { 0 };
		for (int j = l; j <r; j++) {
			int k=getnum(arr[j], i);
			count[k]++;
		}
		for (int j = 1; j < 10; j++) {
			count[j] += count[j - 1];
		}
		for (int j = r-1; j >= l; j--) {
			int k = getnum(arr[j], i);
			help[--count[k]] = arr[j];
		}
		for (int i = l, j = 0; i < r; i++,j++) {
		arr[i] = help[j];
		}
	}
	
}
int main()
{
	int arr[10] = { 13,17,21,1211,52,63,28,39,43,18 };
	int len = sizeof(arr) / sizeof(arr[0]);
	int maxdigit = getmax(arr,len);
	toquque(arr,0,len,maxdigit);
	for (int i = 0; i < len; i++) {
		printf("%d ", arr[i]);
	}
	return 0;
}