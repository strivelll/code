//方法一：硬做 
//#include<stdio.h>
//int main()
//{
//	int k,n,a,b,t[100000],ts;
//	int count=0; 
//	scanf("%d",&k);
//	while(k--)
//	{
//		scanf("%d %d %d",&a,&b,&n);
//		count=0;
//		for(int i=a;i<=b;i++)
//		{
//			
//			if(i>=0&&i<10)
//			{
//				if(((i%10)*(i%10))%10==n)
//				{
//					count++;
//				}
//			}
//			if(i>=10&&i<100)
//			{
//				if(((i%10)*(i%10)+(i/10)*(i/10))%10==n)
//				{
//					count++;
//				}
//			}
//			if(i>=100&&i<1000)
//			{
//				if(((i%10)*(i%10)+(i%100/10)*(i%100/10)+(i/100)*(i/100))%10==n)
//				{
//					count++;
//				}
//			}
//			if(i>=1000&&i<10000)
//			{
//				if(((i%10)*(i%10)+(i%100/10)*(i%100/10)+(i%1000/100)*(i%1000/100)
//				+(i/1000)*(i/1000))%10==n)
//				{
//					count++;
//				}
//			}
//			if(i>=10000&&i<100000)
//			{
//				if(((i%10)*(i%10)+(i%100/10)*(i%100/10)+(i%1000/100)*(i%1000/100)
//				+(i%10000/1000)*(i%10000/1000)+(i/10000)*(i/10000))%10==n)
//				{
//					count++;
//				}
//			}
//		}
//		printf("%d\n",count);
//	}
//	return 0;
//
//方法二：
#include<stdio.h>
int main()
{
	int k,a,b,n,m,t;
	int sum;
	int count;
	scanf("%d",&k);
	while(k--)
	{
		count=0;
		scanf("%d %d %d",&a,&b,&n);
		for(int i=a;i<=b;i++)
		{
			t=i;
			sum=0;
			while(t>0)
			{
				sum+=(t%10)*(t%10);
				t=t/10;
			}
			if(sum%10==n)
			{
				count++;
			}
		}
		printf("%d\n",count);
	}
	return 0;
}
