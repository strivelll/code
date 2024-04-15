#include<stdio.h>
int to_number(int x[4])
{
	int num=0;
	for(int i=0;i<4;i++)
	{
		num=num*10+x[i];
	}
	return num;
}
int main()
{
	int n,n1,n2,n3,n4;
	int a[4];
	int b[4];
	int anum,bnum;
	int count;
	while(scanf("%d",&n),n)
	{
		count=0;
		while(n!=6174)
		{
			a[0]=n/1000;a[1]=n%1000/100;a[2]=n%100/10;a[3]=n%10;
			b[0]=n/1000;b[1]=n%1000/100;b[2]=n%100/10;b[3]=n%10;
			for(int i=0;i<4;i++)
			{
				for(int j=i;j<4;j++)
				{
					if(a[i]>a[j])
					{
						int t=a[j];
						a[j]=a[i];
						a[i]=t;
					}
				}
			}
			for(int i=0;i<4;i++)
			{
				for(int j=i;j<4;j++)
				{
					if(b[i]<b[j])
					{
						int t=b[j];
						b[j]=b[i];
						b[i]=t;
					}
				}
			}
			anum=to_number(a);
			bnum=to_number(b);
			n=bnum-anum;
			count++;	
		}
		printf("%d\n",count);
	}
	return 0;
}
