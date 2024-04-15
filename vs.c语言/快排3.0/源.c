#define _CRT_SECURE_NO_WARNINGS  1
#pragma warning(disable:6031)
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
void swap(int* a, int* b) {
	int t = *a;
	*a = *b;
	*b = t;
}
int partation(int arr[],int l,int r,int* p0,int* p1) {
	int less = l - 1;
	int more = r;
	while (l < more) {
		if (arr[l] < arr[r]) {
			int t = arr[l];
			arr[l++] = arr[++less];
			arr[less] = t;
		}
		else if (arr[l] >arr[r]) {
			int t = arr[l];
			arr[l] = arr[more];
			arr[more--] = t;
		}
		else
			l++;
	}
	swap(&arr[more], &arr[r]);
	*p0 = less;
	*p1 = more;
	return 0;
}
void swap(int* a, int* b) {
	int t = *a;
	*a = *b;
	*b = t;
}
void process(int arr[], int l, int r) {
	if (l == r) {
		return;
	}
	srand((unsigned int)time(NULL));
	int t = rand()% (r - l + 1);
	int p[2];
	swap(&arr[r], &arr[t]);
	partation(arr, l, r, &p[0], &p[1]);
	process(arr, l, p[0]);
	process(arr, p[1] + 1, r);
	

}
int main()
{
	int arr[10] = { 4,3,6,2,7,9,7,5,10,8 };
	int len = sizeof(arr) / sizeof(arr[0]);
	process(arr,0,len-1);
	for (int i = 0; i < len; i++) {
		printf("%d ", arr[i]);
	}
	return 0;
}