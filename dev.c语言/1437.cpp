#include<stdio.h>
int zuixiao(int x,int y)
{
	int p;
	if(x<y)
	{
		int s=y;
		y=x;
		x=s;
	}
	while(x%y!=0)
	{
		p=x%y;
		x=y;
		y=p;
		
	}
	return p;
}
int main()
{
	int a,b,c,d,e,f,n;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f);
		int x=c*a*(e+f);
		int y=d*f*(a+b);
		if(x/y==0&&y/x==0)
		{
			printf("%d %d\n",x,y);
		}
		else
		{
			int p=zuixiao(x,y);
			printf("%d %d\n",x/p,y/p);
		}
	}
	return 0;
} 
