#include<stdio.h>
int main()
{
	int k;
	scanf("%d",&k);
	while(k--)
	{
		int count=0;
		int m;
		int n=1;
		int i;
		scanf("%d",&m);
		for(i=0;i<m;i++)
		{
			count++;
			n=n%m;
			if(n==0)
			{
				printf("%d\n",count);
				break;
			}
			else
			{
				n=n*10+1;
			}
		}
		if(i>=m)
		{
			printf("0\n");
		}
		
	}
	return 0;
}
