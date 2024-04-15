#include<stdio.h>
int main()
{
	int k,n,m,sum=0;
	scanf("%d",&k);
	while(k--)
	{
		scanf("%d %d",&n,&m);
		int arr[n+1];
		int i,j,b;
		for(i=0;i<n;i++)
		{
			scanf("%d",&arr[i]);
		}
		for(i=0;i<n;i++)
		{
			for(j=i;j<n;j++)
			{
				if(arr[i]>arr[j])
				{
					b=arr[j];
					arr[j]=arr[i];
					arr[i]=b;
				}
			}
		}
		int t,flag,min=arr[n-1]-arr[n-m];
		if(m==1)
		{
			printf("0 %d\n",arr[0]);
		}
		else
		{
			for(i=n-1;i>=m-1;i--)
			{
				t=arr[i]-arr[i-m+1];
				if(t<=min)
				{
					min=t;
					flag=i-m+1;
				}
			}
			for(j=flag;j<=flag+m-1;j++)
			{
				sum+=arr[j];
			}
			printf("%d %d\n",min,sum);
		}
	}
	return 0;
} 
