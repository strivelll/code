#include<stdio.h>
int main()
{
	int a,n;
	int b=1;
	int sum=0;
	for(n=1;n<=5;n++)
{
	b=b*n;
	sum=sum+b;
}
    printf("%d",sum);
	return 0;
}
