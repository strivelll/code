#include<stdio.h>
//int main()
//{
//	int n;
//	int a=0;
//	int f=1;
//	int sum=0;
//	for(int i=2;i<140;i++)
//	{
//		f=1;
//		for(int j=2;j<i;j++)
//		{
//			if(i%j==0)
//			{
//				f=0;
//				break;
//			}
//		}
//		if(f)
//		{
//			sum+=i;
//			a++;
//			printf("%d ",i);
//		}
//		
//	}printf("%d\n%d",sum,a);
//} 
//#include<stdio.h>
//#include<stdlib.h>
//struct dc 
//{
//	char a[100];
//}b[100];
//int main()
//{
//	int n;
//	scanf("%d", &n);
//	for (int i = 0; i < n; i++)
//	{
//		scanf("%s", &b[i]);
//	}
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = i; j < n; j++)
//		{
//			if(strcmp(b[i],b[j])==0)
//			{
//				printf("%s\n",b[i]);
//			}
//		}
//	}
//	return 0;
//}
//#include <stdio.h>
//#include <stdlib.h>
//#include<string.h>
//int main(int argc, char *argv[])
//{
//  char a[1001];
//  int b[26]={0};
//  int p=0;
//  scanf("%s",&a);
//  int n=strlen(a);
//  for(int i=0;i<n;i++){
//    for(int j=0;j<26;j++){
//      if(a[i]==j+97){
//      	 b[j]++;
//      }
//    }
//  }
//  for(int i=0;i<26;i++){
//  	if(b[p]<b[i])
//  	p=i;
//  }
//printf("%c\n%d\n",97+p,b[p]);
//  return 0;
//}
#include<stdio.h>
int main()
{
	float t,jg=0,yx=0;
	float a[10001];
	scanf("%f",&t);
	for(int i=0;i<t;i++){
		scanf("%f",&a[i]);
	}
	for(int i=0;i<t;i++){
		if(a[i]>=60){
			jg++;
		}
		if(a[i]>=85){
			yx++;
		}
	}
	printf("%.0f",jg/t*100);
	printf("%\n");
	printf("%.0f",yx/t*100);
	printf("%\n");
	return 0;
}
























