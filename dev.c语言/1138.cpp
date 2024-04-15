#include<stdio.h>
int zuida(int n,int m)
{
	int t;
	while(m%n!=0)
	{
		t=m%n;
		m=n;
		n=t;
	}
	return t;
}
int main()
{
	int k,x,y;
	scanf("%d",&k);
	for(int i=0;i<k;i++)
	{
		scanf("%d%d",&x,&y);
		int n=(x-y)*(x+y-1);
		int m=x*(x-1);
		if(y<=1)
		{
			printf("1\n");
			
		}
		else if(x==y)
		{
			printf("0\n");
		}	
		else if(m%n==0)
		{
			
			printf("%d/%d\n",n/n,m/n);
		}
		else if(m%n!=0)
		{
			int t=zuida(n,m);
			printf("%d/%d\n",n/t,m/t);
		}
	}
	return 0;
} 
