#include<iostream>
#include<stdio.h>
#include<windows.h>
int main(){
    float x,y,a; 
    for(y=1.5;y>-1.5;y-=0.1)
	{
		for(x=-1.5;x<1.5;x+=0.05)
		{
			a=x*x+y*y-1;
			putchar(a*a*a-x*x*y*y*y<=0.0?'*':' ');
		}
        system("color 0c");
        putchar('\n');
    }
	printf("�����ֱ���ר��\n");
	printf("����Ŷ���ҵ�С����������\n");
	return 0;
} 
