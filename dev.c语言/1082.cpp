#include<stdio.h>
#include<math.h>
#define PI 3.14159265
int main()
{
	float y;
	y=sin(PI/4)*sin(PI/4)+sin(PI/4)*cos(PI/4)-cos(PI/4)*cos(PI/4);
	printf("%g\n",y);
	return 0;
} 
