#include<stdio.h>
#include<math.h>
int main()
{
	int i;
	int a,b;
	int c;
	int n;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d%d",&a,&b);
		for(c=1;c>a-b&&c<a+b||c>b-a&&c<a+b;c++)
		{
				if(a*a+b*b==c*c||a*a+c*c==b*b||b*b+c*c==a*a)
				{
					printf("%d",c);
					break;
				}
		}
		if(c>sqrt(a*a+b*b))
		{
			printf("None");
		}
	}
	return 0; 
} 
