#include<stdio.h>
int main()
{
	int n;
	scanf("%d",&n);
	while(n--)
	{
		int a,b,c,d;
		int i;
		scanf("%d%d",&a,&b);
		scanf("%d%d",&c,&d);
		if(a>b)
		{
			int t=a;
			a=b;
			b=t;
		}
		if(c>d)
		{
			int t=c;
			c=d;
			d=t;
		}
		if(b<=d&&b>=c||a<=c&&b>=d||a>=c&&a<=d)
		{
			printf("Yes\n");
		}
		else
		{
			printf("No");
		}
	}
	return 0;
}
