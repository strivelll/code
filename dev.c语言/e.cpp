#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	int i;
	char password[20]={0};
	for(i=0;i<3;i++)
{
	printf("输入密码:>\n");
		scanf("%s",&password);	
		if(strcmp(password,"123456")==0)
		{
		printf("登入成功");
		break;
	}
	else
{
	 printf("密码错误，请重新输入密码\n");//并不完美最后一次会重复 
}
}
	if(i==3)
	printf("三次密码均错误，退出程序");
	return 0;
}
