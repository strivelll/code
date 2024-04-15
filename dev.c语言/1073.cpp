#include<stdio.h>
int main()
{
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	if(a>b&&b>c){
		printf("%d %d",a,c);
	}
	if(a>c&&c>b){
		printf("%d %d",a,b);
	}
	if(b>a&&a>c){
		printf("%d %d",b,c);
	}
	if(b>c&&c>a){
		printf("%d %d",b,a);
	}
	if(c>a&&a>b){printf("%d %d",c,b);
	}
	if(c>b&&b>a){
		printf("%d %d",c,a);
	}
	return 0;
}
