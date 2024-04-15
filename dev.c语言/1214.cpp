#include<stdio.h>
int main()
{
	int k;
	int a,b,c,n,m,s;
	scanf("%d",&k);
	while(k--)
	{
		s=0;
		m=1;
		scanf("%d+%d=%d",&a,&b,&c);
		if(a+b==c)
		{
			printf("0\n");
		}
		else
		{
			for(n=10;n<1000000000;n*=10)
			{
				s++;
				if((a*n+b)==c)
				{
					printf("%d\n",s);
					m=0;
					break;
				}
			}
			if(m)
			{
			s=0;
			for(n=10;n<1000000000;n*=10)
			{
				s--;
				if((a+b*n)==c)
				{
					printf("%d\n",s);
					break;
				}
			}
			}
		}
	}
	return 0;
}
