#include<stdio.h>
int main()
{
	int n;
	int a;
	scanf("%d",&n);
	while(n!=-1)
	{
		scanf("%d",&n);
		a=1;
		for(int i=1;i<=n;i++)
		{
			a=(a*i)%10007;
		}
		printf("%d",a);
	}
	return 0;
} 
