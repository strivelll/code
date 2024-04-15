#define _CRT_SECURE_NO_WARNINGS  1
#pragma warning(disable:6031)
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void swap(int arr[],int a, int b) {
	int t = arr[a];
	arr[a] = arr[b];
	arr[b] = t;
}
void heapinset(int arr[], int index) {
	while (arr[index] > arr[(index - 1) / 2]) {
		swap(arr,index, (index - 1) / 2);
		index = (index - 1) / 2;
	}
}
void heapify(int arr[], int index, int heapsize) {
		int left = index*2+1;
		while(left < heapsize) {
			int anw = left + 1 < heapsize && arr[left + 1] > arr[left] ? left + 1 : left;
			if (arr[anw] > arr[index]) {
				swap(arr, anw, index);
			}
			index = anw;
			left= index * 2 + 1;
		}
	}
void heapsort(int arr[], int len) {
	//用户一个一个数据输入的时候用heapinset使其变成大跟堆.时间复杂度O(N)
	for (int i = 0; i < 10; i++) {
		heapinset(arr, i);
	}
	/*假如用户直接给了一组数据,则直接使用heapify使其变成大根堆,时间复杂度O(N).
	for(int i=len-1;i<=0;i--){
		heapify(arr,i,len);
	}
	*/
	swap(arr, 0, --len);
	while (len > 0) {
		heapify(arr, 0, len);
		swap(arr, 0, --len);
	}
}
int main()
{
	int arr[10] = { 2,4,9,1,7,6,3,8,5,10 };
	int len = sizeof(arr) / sizeof(arr[0]);
	heapsort(arr,len);
	for (int i = 0; i < 10; i++) {
		printf("%d ", arr[i]);
	}
	return 0;
}