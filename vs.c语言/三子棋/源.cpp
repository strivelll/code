#include<stdio.h>
#include"game.h"
void game()
{
	char borad[ROW][COL] = {0};
	chush(borad, ROW, COL);
	display(borad, ROW, COL);
}
void menu()
{
	printf("#########################\n");
	printf("####1.play     0.exit####\n");
	printf("#########################\n");
}
void texs()
{
	int imput = 0;
	do
	{
		
		menu();
		printf("������:>\n");
		scanf("%d", &imput);
		switch (imput)
		{
		case 1:
			printf("��Ϸ��ʼ\n");
			
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("�����������������:>\n");
			break;
		}
	} while (imput);
}
int main()
{
	texs();
	return 0;
}
