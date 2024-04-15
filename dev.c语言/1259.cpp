#include<stdio.h>
#include<math.h>
int main()
{
	int k;
	int n,m;
	scanf("%d",&k);
	__int64 count,a,b;
	count=0;
	while(k--)
	{
		scanf("%d %d",&n,&m);
		a=1;
		b=1;
		if(n==1)
		{
			count=9/m+1;
			printf("%I64d\n",count);
		}
		else
		{
			a=pow(10,n)-1;
			b=pow(10,n-1)-1;
			count=a/m-b/m;
			printf("%I64d\n",count);
		}
	}
	return 0;
} 






















