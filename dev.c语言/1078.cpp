#include<stdio.h>
int main()
{
	char a;
  	int count=1;
	while(scanf(" %c",&a)&&a!='#')
	{
	char b='A';
	printf("case %d:\n",count);
 	count++;
	for(int i=0;i<=a-b;i++)
	{
		for(int j=0;j<i;j++)
  		{
   			printf(" ");
		}
		for(int j=0;j<=a-b-i;j++)
		{
			printf("%c",b+j);
		}
		for(int j=1;j<=a-b-i;j++)
		{
			printf("%c",a-j-i);
		}
		printf("\n");
	}
	continue;
	}
	return 0;
}

