#include<stdio.h>
#include<stdlib.h>
int main()
{
	int arr[] = { 1,3,5,7,9,2,4,6,8,10 };
	qsort(arr,10,sizeof(int),);
	for (int i = 0; i < 10; i++)
	{
		printf("&d ", &arr[i]);
	}
	return 0;
}
//方法一：传统只能整形排序
//void mh(int arr[], int sz)
//{
//	int f=1;
//	for (int i = 0; i < sz; i++)
//	{
//		
//		if(f)
//		for (int j = i; j < sz; j++)
//		{
//			f=0;
//			if (arr[i] > arr[j])
//			{
//				int t=arr[i];
//				arr[i] = arr[j];
//				arr[j] = t;
//				f = 1;
//			}
//		}
//	}
//	for (int i = 0; i < sz; i++) {
//		printf("%d ", arr[i]);
//	}
//}
//int main()
//{
//	int arr[] = { 1,3,5,7,9,2,4,6,8,10 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	mh(arr, sz);
//	return 0;
//}