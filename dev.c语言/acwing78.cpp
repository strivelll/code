#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	int n;
	int count=0;
	char a[10][10];
	char b[10][10];
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%s%s",&a[i][10],&b[i][10]);
	}
	for(int i=0;i<n;i++)
	{
		if((strcmp(a[i][10],a[i+1][10])==0)&&strcmp(b[i][10],b[i+1][10])==0)
		count++;
	}
	printf("%d\n",n-count);
	return 0;
} 
