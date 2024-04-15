#define _CRT_SECURE_NO_WARNINGS  1
#pragma warning(disable:6031)
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
int counts(int n) {
	int count = 0;
	while (n) {
		n /= 10;
		count++;
	}
	return count;
}
int pd(int n,int count) {
	int sum = 0;
	while (n) {
		sum += (int)pow(n % 10, count);
		n /= 10;
	}
	return sum;
}
int main()
{
	int n;
	while (scanf("%d", &n), n){
		int count = counts(n);
		int sum = pd(n,count);
		if (sum == n) {
			printf("Yes\n");
		}
		else
			printf("No\n");
	}
	return 0;
}