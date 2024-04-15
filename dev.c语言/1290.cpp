#include<stdio.h>
#include<string.h>
int main()
{
	int k;
	char alice[10],bob[10];
	scanf("%d",&k);
	while(k--)
	{
		scanf("%s %s",&alice,&bob);
		int a=strlen(alice);
		int b=strlen(bob);
		if(a==b)
			printf("Draw\n");
		if (a== 4 && b == 5)
			printf("Bob\n");
		if (a == 4 && b == 8)
			printf("Alice\n");
		if (a == 8 && b == 4)
			printf("Bob\n");
		if (a == 8 && b == 5)
			printf("Alice\n");
		if ( a == 5 && b == 8)
			printf("Bob\n");
		if (a == 5 && b == 4)
			printf("Alice\n");
	}
	return 0;
}
