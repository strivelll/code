#include<stdio.h>
int main()
{
	double a;
	scanf("%lf",&a);
	printf ("%.8f",a);//fioat（单精度浮点数）打印字符用%f,而double（）多精度浮点数即 
	return 0;
}
//fioat（单精度浮点数）打印小数用%f,而double（多精度浮点数）即long float所以打印
//小数用%lf 
