#include<stdio.h>
#include<math.h>
int main()
{
	float xa,ya,xb,yb;
	scanf("%f%f%f%f",&xa,&ya,&xb,&yb);
	printf("%g\n",sqrt((xa-xb)*(xa-xb)+(ya-yb)*(ya-yb)));
	return 0;
}
