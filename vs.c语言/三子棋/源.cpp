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
		printf("请输入:>\n");
		scanf("%d", &imput);
		switch (imput)
		{
		case 1:
			printf("游戏开始\n");
			
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("输入错误，请重新输入:>\n");
			break;
		}
	} while (imput);
}
int main()
{
	texs();
	return 0;
}
