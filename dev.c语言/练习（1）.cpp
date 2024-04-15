#define _CRT_SECURE_NO_WARNINGS  1
#pragma warning(disable:6031)
#include<stdio.h>
#include<string.h>
#include<malloc.h>
int main() {
	char a[1000] = { "0" };
	gets(a);
	for (int i = strlen(a)-2; i >=0 ; i--) {
		printf("%c",a[i]);
	}
	return 0;
}
//题目四：方法一(试除法)：打印100~200的所以素数
//#include<stdio.h>
//int main()
//{
//	int a;
//	int b;
//	int count=0;
//	for(a=100;a<=200;a++)
//{
//	for(b=2;b<a;b++)
//{
//	if(a%b==0)
//{
//	break;
//}
//}
//	if(a==b)
//{
//	count++;
//	printf("%d\n",a);
//}
//}
//	printf("count=%d",count);
//	return 0;
//} 
//方法二：
// #include<stdio.h>
// #include<math.h>
// int main()
// {
// 	int a;
// 	int i;
// 	int count=0;
// 	for(a=100;a<=200;a++)
//偶数必定不是素数；所以可以优化为(for(a=101;a<=100;a+=2)) !!!!!!
// 	{
// 		for(i=2;i<=sqrt(a);i++)
// 		{
// 			if(a%i==0)
// 			{
// 			break;
//			}
//		}
// 		if(i>sqrt(a))
// 		{
//		 count++;
// 		printf("%d ",a);
// 		}
// 	}
// 	printf("\ncount=%d",count);
// 	return 0;
// } 
//方法三(函数方法)：
//#include<stdio.h>
//int is_prime(int n)
//{
//	int j;
//	for(j=2;j<n;j++)
//	{
//		if(n%j==0)
//		{
//			return 0;
//		}
//	}
//	return 1;
//}

//int main()
//{
//	int i;
//	int count=0;
//	for(i=100;i<=200;i++)
//	{
//		int a=is_prime(i);
//		if(a==1)
//		{
//			printf("%d ",i);
//			count++;
//		}
//	}
//	printf("\n%d\n",count);
//	return 0;
//} 
 
 
 //题目五；求两个数的最大公约数；
 //#include<stdio.h>
// int main()
// {
// 	int n,m,r;
// 	scanf("%d%d",&n,&m);
// 	while(r=m%n)
//{
//	m=n;
//	n=r;
//}
//	printf("%d",n);
// 	return 0;
// } 
// 
 
//题目六：从大到小排列数
//#include<stdio.h>
//int main()
//{
//	int a,b,c,d;
//	scanf("%d%d%d",&a,&b,&c);
//	if(c>b)
//	{
//		d=c;
//		c=b;
//		b=d;
//	} 
//	if(a<b)
//	{
//		d=b;
//		b=a;
//		a=d;
//	}
//	if(a<c)
//	{
//		d=c;
//		c=a;
//		a=d;
//	}
//	printf("%d %d %d",a,b,c);
//	return 0;
//} 
// 题目七；数100中9的个数；
//#include<stdio.h>
//int main()
//{
//	int n;
//	int count=0;
//	for(n=1;n<=100;n++)
//	{
//		if(n%10==9)
//		{
//			count++;
//		}
//		if(n/10==9)
//		{
//			count++;
//		}
//	}
//	printf("count=%d",count);
//	return 0;
//} 
//题目八：分数求和
//#include<stdio.h>
//int main()
//{
//	int n;
//	double sum=0.0;
//	for(n=1;n<=100;n++)
//	{
//		if(n%2!=0)
//		{
//			sum+=1.0/n;
//		}
//		if(n%2==0)
//		{
//			sum-=1.0/n;
//		}
//	}
//	printf("%lf",sum);
//	return 0;
//} 
//题目九：输出乘法表
/*#include<stdio.h>
int main()
{
	int i;
	int j=1;
	for(i=1;i<=9;i++)
	{
		for(j=1;j<=i;j++)
		{
			printf(" %d*%d=%-2d",i,j,i*j);
		}
		printf("\n");
	}
	return 0;
} */
//复习
//题目十：冒泡排序函数
//#include<stdio.h>
//void paixu(int arr[],int sz)
//{
//	for(int a=0;a<sz-1;a++)
//	{
//		int flag=1;
//		for(int b=0;b<sz-1-a;b++)
//		{
//			if(arr[b]>arr[b+1])
//			{
//				int s=arr[b];
//				arr[b]=arr[b+1];
//				arr[b+1]=s;
//				flag=0;
//			}
//		}
//		if(flag==1)
//		{
//			break;
//		}
//	}
//}
//int main()
//{
//	int arr[]={9,8,7,6,5,4,2,3,1,0};
//	int sz=sizeof(arr)/sizeof(arr[0]);
//	paixu(arr,sz);
//	for(int i=0;i<sz;i++)
//	{
//		printf("%d ",arr[i]);
//	}
//	return 0;
//} 
 
 
 
 
 
 
 
 
 
