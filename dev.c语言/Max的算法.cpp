//����һ 
//#include<stdio.h>
//int Max(int x,int y)
//{
//if(x>y)
//	return x;
//else 
//    return y;
//}
//int main()
//{
//	int a,b;
//	scanf("%d%d",&a,&b);
//	int max=Max(a,b);
//	printf("max=%d",max);
//	return 0;
//}
//������ 
#include<stdio.h>
#define Max(x,y) x>y?x:y
int main()
{
int a,b;
scanf("%d%d",&a,&b);
int max=Max(a,b);
printf("max=%d",max);
return 0;
}
