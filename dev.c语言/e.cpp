#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	int i;
	char password[20]={0};
	for(i=0;i<3;i++)
{
	printf("��������:>\n");
		scanf("%s",&password);	
		if(strcmp(password,"123456")==0)
		{
		printf("����ɹ�");
		break;
	}
	else
{
	 printf("���������������������\n");//�����������һ�λ��ظ� 
}
}
	if(i==3)
	printf("��������������˳�����");
	return 0;
}
