#include<stdio.h>
#include<string.h>
int main()
{
	int n,k,p;
	char arr[2000];
	int brr[26];
	scanf("%d",&k);
	int count;
	while(k--)
	{
		count=0;
		for(int i=0;i<26;i++)
		{
			brr[i]=0;
		}
		scanf("%s",&arr);
		n=strlen(arr);
		for(int i=0;i<n;i++)
		{
			brr[arr[i]-65]++;
		}
		p=0;
		for(int i=0;i<26;i++)
		{
			if(brr[i]>brr[p])
			{
				p=i;
			}
		}
		printf("%c %d\n",p+65,brr[p]);
	}
	return 0;
}
