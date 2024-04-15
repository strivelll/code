#include<stdio.h>
int main()
{
	int a,n;
	int b=1;
	scanf("%d",&n);
	for(a=1;a<=n;a++)
	{
		b=b*a;
	}
	printf("b=%d\n",b);
	return 0;
}
