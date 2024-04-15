#include<stdio.h>
#include<math.h>
#define PI 3.14159265
int main()
{
	float a,b,p;
	scanf("%f%f%f",&a,&b,&p);
	printf("%g\n",sqrt(a*a+b*b-2*a*b*cos(p*PI/180)));
	return 0;
}
