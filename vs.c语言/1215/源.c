#define _CRT_SECURE_NO_WARNINGS  1
#pragma warning(disable:6031)
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int myatoi(int arr[10],int len) {
	int sum = 0;
	for (int i = 10-len; i < 10; i++) {
		sum = sum * 10 + arr[i];
	}
	return sum;
}
int countlen(int n) {
	int count = 0;
	while (n)
	{
		count++;
		n /= 10;
	}
	return count;
}
int main()
{
	int k,a,b;
	scanf("%d", &k);
	while (k--) {
		scanf("%d %d", &a, &b);
		char arra[10] = { 0 };
		char arrb[10] = { 0 };
		int arrc[10] = { 0 };
		sprintf(arra, "%010d", a);
		sprintf(arrb, "%010d", b);
		int len = a > b ? countlen(a) : countlen(b);
		for (int i = 10-len; i < 10; i++) {
			arrc[i] = arra[i]-'0' + arrb[i]-'0';
			arrc[i] %= 10;
		}
		printf("%d\n", myatoi(arrc,len));
	}
	return 0;
}