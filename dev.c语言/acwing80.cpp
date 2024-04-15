//#include<stdio.h>
//#include<string.h>
//int main()
//{
//	char a[101];
//	gets(a);
//	int b=strlen(a);
//	for(int i=b-1;;i--)
//	{
//		if((a[i]>=65&&a[i]<=127))
//		{
//			if(a[i]=='A'||a[i]=='E'||a[i]=='I'||a[i]=='O'||a[i]=='U'||a[i]=='a'
//			||a[i]=='e'||a[i]=='i'||a[i]=='o'||a[i]=='u'||a[i]=='y'||a[i]=='Y')
//		{
//			printf("YES\n");
//			break;
//		}
//		else
//		{
//			printf("NO\n");
//			break;
//		}
//		}
//	}
//	return 0;
//} 
#include<stdio.h>
int main()
{
	int n,x,b=-1,c;
	int a[10];
	scanf("%d",&n);
	c=n;
	while(c)
	{
		c/=10;
		b++;
	}
	while(n)
	{
		for(int i=b+1;i>0;i--)
		{
			a[i]=n%10;
			n/=10;
			printf("%d ",a[i]);
		}
	}
	for(int i=1;i<b;i++)
	{
		if(a[i]>4)
		{
			a[i]=7;
		}
		if(a[i]>7)
		{
			a[i]=4;
			a[0]=4;
		}
	}
	for(int i=0;i<b;i++)
	printf("%d",a[i]); 
	return 0;
}
