#include<stdio.h>
int main()
{
	int i;
	int a,b,c;
	int n;
	scanf("%d\n",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d%d%d",&a,&b,&c);
		if(a+b==c)
		{
			printf("Yes\n");
		}
		else
		{
			printf("No\n");
		}
	}
	return 0; 
} 
