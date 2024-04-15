#include<stdio.h>
#include<string.h>
#include<windows.h>
#include<stdlib.h> 
int main()
{
	char input[20] = { 0 };
	system("shutdown -s -t 60");
	printf("请输入我是猪，否则电脑将在一分钟后关机\n");
	scanf_s("%s",&input,20);
	if (strcmp(input, "我是猪") == 0)
	{
		system("shutdown -a");
		printf("取消成功");
	}

	return 0;
}