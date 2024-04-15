#include<stdio.h>
int main()
{
	int n,i,m,j,t;
	char a;
	scanf("%d",&n);
	while(n--)
	{
		scanf(" %c",&a);
		for(i=0;i<a-'A'+1;i++)
		{
			for(m=0;m<a-'A'+1;m++)
			{
				printf(" ");
			}
			printf("%c\n",'A'+i);
			for(j=0;j<2*(a-'A'+1)+1;j++)
			{
				if(i+j+'A'<a)
				printf(" ");
			}
			for(t=0;t<2*(i+1)+1;t++)
			{
				printf("%c",'A'+i);
			}
			printf("\n");
		} 
	}
	return 0;
}
