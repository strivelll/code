#include<stdio.h>
#include<string.h>
//题目一逆序： 
//void nxu(char*a)
//{
//	int left=0;
//	int len=strlen(a);
//	int right=len-1;
//	int t=a[left];
//	a[left]=a[right];
//	a[right]='\0';
//	if(strlen(a+1)>=2)
//	nxu(a+1);
//	a[right]=t;
//}
//int main()
//{
//	char a[100];
//	scanf("%s",&a);
//	nxu(a);
//	printf("%s\n",a);
//	return 0;
//} 
//题目二:一个数每位之和
//int js(int n)
//{
//	if(n>9)
//	{
//		return js(n/10)+n%10; 
//	}
//	else
//	{
//		return n;
//	}
//} 
//int main()
//{
//	int n;
//	scanf("%d",&n);
//	int sum=js(n);
//	printf("%d\n",sum);
//	return 0;
//}
//题目三:n的k次方
//double cf(int n,int k)
//{
//	if(k==0)
//	{
//		return 1;
//	}
//	if(k<0)
//	{
//		return 1.0/cf(n,-k);
//	}
//	if(k>0)
//	{
//		return n*cf(n,k-1);
//	}
//}
//int main()
//{
//	int n,k;
//	scanf("%d%d",&n,&k);
//	double c=cf(n,k);
//	printf("%lf\n",c);
//	return 0;
//} 
#include<stdio.h>
#include<string.h>
//题目一逆序：
//void nxu(char* n)
//{
//	int left=0;
//	int len=strlen(n);
//	int right=len-1;
//	int t=n[left];
//	n[left]=n[right];
//	n[right]='\0';
//	if(strlen(n+1)>=2)
//	nxu(n+1);
//	n[right]=t;
//}
//int main()
//{
//	char n[100];
//	scanf("%s",&n);
//	nxu(n);
//	printf("%s\n",n);
//	
//	return 0;
//}

//题目二:一个数每位之和
//double he(int n)
//{
//	if(n>9)
//	{
//		return he(n/10)+n%10;
//	}
//	else
//	{
//		return n;
//	}
//}
//int main()
//{
//	int n;
//	scanf("%d",&n);
//	double r=he(n); 
//	printf("%lf\n",r);
//	return 0;
//}

//题目三:n的k次方
//double cf(int n,int k)
//{
//	if(k==0)
//	{
//		return 1;
//	}
//	if(k<0)
//	{
//		return 1.0/cf(n,-k);
//	}
//	if(k>0)
//	{
//		return n*cf(n,k-1);
//	}
//}
//int main()
//{
//	int n,k;
//	scanf("%d%d",&n,&k);
//	double r=cf(n,k);
//	printf("%lf\n",r);
//	return 0;
//}
