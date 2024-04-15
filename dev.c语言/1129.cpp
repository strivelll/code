#include<stdio.h>
int main()
{
	int n,d;
	int x1,y1,x2,y2;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		if(x1<x2)
		{
			int t=x2;
			x2=x1;
			x1=t;
		}
		if(y1<y2)
		{
			int t=y2;
			y2=y1;
			y1=t;
		}
		d=(x1-x2)+(y1-y2); 
		printf("%d\n",d);
	}
	return 0;
}
