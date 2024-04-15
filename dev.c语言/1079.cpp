//方法一： 
//#include<stdio.h>
//int main()
//{
//	float s=5;
//    float a=1+1/s;
//	float b=1+1/a;
//	float c=1+1/b;
//	printf("%g\n",c);
//    return 0;
//} 
//方法二：循环 
#include<stdio.h>
int main()
{
	float a=5;
	int n;
	for(n=0;n<3;n++)
{
	a=1+1/a;
}
printf("%g\n",a);
	
	return 0;
} 
