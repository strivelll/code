#include<stdio.h> 
int main()
{
	int n,m,i,j;
	int arr[100]; 
	while(scanf("%d",&n),n)
	{
		for(i=0;i<n;i++)
		{
			scanf("%d",&arr[i]);
		}
		while(n--)
		{
			printf("%d\n",n);
			for(j=0;j<n;j++)
			{
				arr[j]=(arr[i]+arr[j+1])%2013;
			}
		}
		printf("%d\n",arr[0]);
	} 
	return 0;
} 
