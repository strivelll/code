/*#include<stdio.h>
#include<string.h>
#include<windows.h>
int main()
{
	char arr[20]={0};
	system("shutdown -s -t 60"); 
	printf("������������������Խ���һ���Ӻ�ػ�");
	scanf("%s",arr);
	if(strcmp(arr,"������")==0)
	{
		system("shutdoown -a "); 
	}
	
	return 0;
}*/
//#include<stdio.h>
//#include<string.h>
//#include<windows.h>
//int main()
//{
//	char arr[20] = { 0 };
//	system("shutdown -s -t 60");
//	printf("������������������Խ���һ���Ӻ�ػ�");
//	scanf("%s", arr);
//	if (strcmp(arr, "������") == 0)
//	{
//		system("shutdown -a");
//	}

//	return 0;
//}
#include<stdio.h>
#include<string.h>
#include<windows.h>
#include<stdlib.h> 
int main()
{
	char input[20] = {0};
	system('shutdown -s -t 60');
	printf("������������������Խ���һ���Ӻ�ػ�\n");
	scanf("%s",input);
	if (strcmp(input, "������") == 0)
	{
		system("shutdown -a");
		printf("ȡ���ɹ�");
	}

	return 0;
}
