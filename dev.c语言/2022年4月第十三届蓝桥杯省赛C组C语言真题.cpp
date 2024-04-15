#include<stdio.h>
//题目二特殊时间： 
//int main()
//{
//	int n=0,m=0;
//	for(int i=0;i>0;i++)
//	{
//		
//	}
//	return 0;
//} 
//题目C纸张尺寸： 
//int main()
//{
//	char a;
//	int n;
//	int c=1189;
//	int k=841;
//	scanf("%c%d",&a,&n);
//	if(n==0)
//	{
//		printf("%d\n",c);
//		printf("%d\n",k);
//	}
//	else
//	{
//		for(int i=1;i<=n;i++)
//		{
//			if(c<k)
//			{
//				int t=k;
//				k=c;
//				c=t;
//			}
//			c/=2;
//		}
//		printf("%d\n",k);
//		printf("%d\n",c);
//	}
//	return 0;
//}
//题目D求和： 
//int main()
//{
//	int n;
//	int sum=0;
//	int a[1005];
//	scanf("%d",&n);
//	for(int i=0;i<n;i++)
//	{
//		scanf("%d",&a[i]);
//	}
//	for(int i=0;i<n;i++)
//	{
//		for(int j=1;j+i<n;j++)
//		{
//			sum=sum+a[i]*a[j+i];
//		}
//	}
//	printf("%d\n",sum);
//	return 0;
//}
int main()
{
	int n,m;
	int x=1;
	int s[1005];
	int a[1005];
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++)
	{
		a[i]=i+1;
	}
	for(int i=0;i<n;i++)
	{
		s[i]=0;
	}
	for(int j=0;j<n;j++)
	{
		while(a[j])
		{
			s[j]+=a[j]%10;
			a[j]=a[j]/10;
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=1;j+i<n;j++)
		{
			if(s[i]>s[j+i])
			{
				int t=s[j+i];
				s[j+i]=s[i];
				s[i]=t;
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		printf("%d ",s[i]);
	} 
	return 0;
} 
