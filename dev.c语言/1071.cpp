#include<stdio.h>
#include<math.h>
int main()
{
	float a,b,c;
	scanf("%f%f%f",&a,&b,&c);
		float q=(a+b+c)/2;
	if(a+b>c&&a+c>b&&b+c>a){
		
		printf("%.2f",sqrt(q*(q-a)*(q-b)*(q-c)));
	}
	else printf("Not a triangle.");
	return 0;
}
