#include<stdio.h>
int zuida(int x,int y)
{
	while(y%x!=0)
	{
		int t=y%x;
		y=x;
		x=t;
	}
	return x;
}
int main()
{
	int x,y;
	while(x!=0&&y!=0)
	{
		scanf("%d%d",&x,&y);
		if(x==0&&y==0)
		{
			break;
		}
		if(x>y)
		{
			int t=x;
			x=y;
			y=t;
		}
		if(y%x==0)
		{
			printf("%d\n",y);
		}
		else
		{
			int a=zuida(x,y); 
			printf("%d\n",x*y/a);
		}
	}
	return 0;
} 
