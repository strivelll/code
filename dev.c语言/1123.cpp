#include<stdio.h>
int main()
{
	int m,n,k,f;
	int count;
	int arr[1005];
	scanf("%d",&m);
	while(m--)
	{
		scanf("%d %d",&n,&k);
		
		for(int i=0;i<n;i++)
		{
			scanf("%d",&arr[i]);
		}
		f=1;
		for(int i=k;i<n;i++)
		{
			
			if(arr[k-1]!=arr[i])
			{
				f=0;
				break;
			}
		}
		if(f==0)
		{
			printf("-1\n");
		}
		else
		{	
			count=0;
			for(int i=1;i<=k-1;i++)
			{
				if(arr[k-1]==arr[k-1-i])
				{
					count++;
				}
				else
				{
					break;
				}
			}
			printf("%d\n",k-1-count);
		}
		
	}
	return 0;
}
