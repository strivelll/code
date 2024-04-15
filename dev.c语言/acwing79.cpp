#include<stdio.h>
//int main()
//{
//	int n,a=0,f=1;
//	scanf("%d",&n);
//	for(int i=1;i<n+1;i++)
//	{
//		a+=i;
//		if(a==n)
//		{
//			f=0;
//			printf("YES\n");
//			break;
//		}
//	}
//	if(f)
//	{
//		printf("NO\n"); 
//	}
//	return 0;
//}
//int main()
//{
//	char a[100000]={'a','b','c','d','e'};
//	int n,t;
//	char f;
//	scanf("%d",&n);
//	t=n;
//	for(int j=1;j<=n;j++){
//		f=a[0];
//		for(int i=0;i<5+j;i++)
//		{
//			a[i]=a[i+1];
//		}
//		a[3+j]=f;
//		a[4+j]=f;
//	}
//	printf("%c\n",f);
//	return 0;
//}
int main()
{
	int n;
	char a[10]={"abcde"};
	int i=1;
	scanf("%d",&n);
	while(n-i*5>0)
	{
		n-=i*5;
		i*=2;
	} 
	int j=0;
	while(n-i>0)
	{
		j++;
		n-=i;
	}
	printf("%c\n",a[j]);
	return 0;
}
