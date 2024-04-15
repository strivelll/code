#include<stdio.h>
int main()
{
	int s;
	scanf("%d",&s);
	int a,b,c;
	a=s/100;
	b=s%100/10;
	c=s%10;
	if((a==b&&b!=c)||(a!=b&&b==c)||(a==c&&c!=b)){
		printf("Yes");
	}
	else printf("No");
	return 0;
} 
