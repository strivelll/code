#include<stdio.h>
#include<string.h>
#include<windows.h>
#include<stdlib.h> 
int main()
{
	char input[20] = { 0 };
	system("shutdown -s -t 60");
	printf("������������������Խ���һ���Ӻ�ػ�\n");
	scanf_s("%s",&input,20);
	if (strcmp(input, "������") == 0)
	{
		system("shutdown -a");
		printf("ȡ���ɹ�");
	}

	return 0;
}