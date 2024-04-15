#include<stdio.h>
int main()
{
	char ch;
	scanf("%c",&ch);
	int a=ch;
    if(ch>=90)
    {
    	printf("%c",ch-32);
    }else printf("%C",ch+32);
    return 0;
}
