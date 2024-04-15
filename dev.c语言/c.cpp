////方法一： 
//#include<stdio.h>
//int main()
//{
//	char arr[]={1,2,3,4,5,6,7,8,9,10};
//	int n=7;
//	int i;
//	int sz=sizeof(arr)/sizeof(arr[0]);
//	for(i=1;i<sz;i++)
//	{
//		if(n==arr[i])
//{
//		printf("找到了,下标为%d\n",i);
//		break;
//}

//	}
//			if(i==sz)
//		printf("找不到\n");
//	return 0;
//}
//方法二： 
//#include<stdio.h>
//int main()
//{
//	int n=90;
//	char arr[]={1,2,3,4,5,6,7,8,9,10};
//	int sz=sizeof(arr)/sizeof(arr[0]);
//	int left=0;
//	int right=sz-1;
//	while(left<=right)
//{
//		int mid=(left+right)/2;
//	if(arr[mid]<n)
//	{
//		left=mid+1; 
//	}
//	else if(arr[mid]>n)
//	{
//		right=mid-1;
//	}
//	else
//	{
//		printf("找到了，下标为%d\n",mid);
//	    break;
//	}
//}
//if(left>right)
//{
//	printf("找不到\n");
//}
//	return 0;
//}
//方法三（函数方法）：
#include<stdio.h>
int is_l(int arr[],int n,int sz)
{
	int left=0;
	int right=sz-1;
while(left<=right)
{
	int mid=(left+right)/2;
	if(arr[mid]<n)
	{
		left=mid+1; 
	}
	else if(arr[mid]>n)
	{
		right=mid-1;
	}
	else
	return mid;
}
	return -1;
}
int main()
{
	int arr[]={1,2,3,4,5,6,7,8,9,10};
	int sz=sizeof(arr)/sizeof(arr[0]);
	int n=71;
	int a=is_l(arr,n,sz);
	if(a==-1)
	{
		printf("找不到"); 
	}
	else
	{
		printf("找到了，下标为%d",a);
	}
	return 0;
} 
