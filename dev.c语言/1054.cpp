#include<stdio.h>
int main()
{
	int n;
	int count;
	int arr[1000];
	__int64 a,b;
	while(scanf("%d",&n),n)
	{
		count=0;
		for(int i=0;i<n;i++)
		{
			scanf("%d",&arr[i]);
		}
		for(int i=0;i<n;i++)
		{
			a=arr[i];
			for(int j=0;j<n;j++)
			{
				b=arr[j];
				if(a==b*b)
				{
					count++;
				}
			}
		}
		printf("%d\n",count);
	}
	return 0;
}
