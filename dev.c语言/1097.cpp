#include<stdio.h>
int main()
{
	int k,n;
	char m;
	scanf("%d",&k);
	int arr[1000];
	while(k--)
	{
		scanf("%d %c",&n,&m);
		for(int i=0;i<n;i++)
		{
			scanf("%d",&arr[i]);
		}
		if(m=='A')
		{
			for(int i=0;i<n;i++)
			{
				for(int j=i+1;j<n;j++)
				{	
					if(arr[i]>arr[j])
					{
						int t=arr[j];
						arr[j]=arr[i];
						arr[i]=t;
					}
				}
			}
			for(int t=0;t<n;t++)
			{
				if(t!=n-1)
				{
					printf("%d",arr[t]);
					printf(" ");
				}
				else
				{
					printf("%d",arr[t]);
				}
			}
		}
		if(m=='D')
		{
			for(int i=0;i<n;i++)
			{
				for(int j=i+1;j<n;j++)
				{	
					if(arr[i]<arr[j])
					{
						int t=arr[j];
						arr[j]=arr[i];
						arr[i]=t;
					}
				}
			}
			for(int t=0;t<n;t++)
			{
				if(t!=n-1)
				{
					printf("%d",arr[t]);
					printf(" ");
				}
				else
				{
					printf("%d",arr[t]);
				}
			}
		}
		printf("\n");
	}
	return 0;
}
