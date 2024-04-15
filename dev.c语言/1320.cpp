#include<stdio.h>
#include<stdlib.h>
int main()
{
	int k;
    scanf("%d",&k);
    while(k--)
    {
    	int a,b;
    	int s;
    	scanf("%d %d",&a,&b);
    	s=abs(a-b);
    	printf("%d\n",s);
	}
	return 0;
}
