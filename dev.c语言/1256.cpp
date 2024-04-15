#include<stdio.h>
#include<string.h>
int main()
{
	int k,len,count;
	char arr[1005];
	scanf("%d ",&k);
	while(k--)
	{
		gets(arr);
		len=strlen(arr);
		int a=0,b=0,c=0;
		for(int i=0;i<len;i++)
		{
			if(arr[i]=='X')
			{
				a++;
			}
			if(arr[i]=='T')
			{
				b++;
			}
			if(arr[i]=='U')
			{
				c++;
			}
		}
		if(a>=b&&c>=b)
		{
			count=b;
		}
		if(a<=b&&a<=c)
		{
			count=a;
		}
		if(c<=a&&c<=b)
		{
			count=c;
		}
		printf("%d\n",count);
	}
	return 0;
}
