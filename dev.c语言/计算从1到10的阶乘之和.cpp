#include<stdio.h>
int main()
{
	int a;
	int b=1;
	int n;
	int sum=0;
	for(n=1;n<=5;n++) 
{
//����һ�� 
//			b=1;
//		for(a=1;a<=n;a++)
//		b=b*a;
//����������㣩�� 
        b=b*n;
		sum=sum+b;
}
	printf("sum=%d\n",sum);
	return 0;
}
