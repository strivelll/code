//#include<stdio.h>
//#include<stdlib.h>
//#include<time.h>
//void game()
//{
//	int n;
//	int i;
//	n=rand()%100+1;
//	while(1)
//	{
//	printf("猜数字:>\n");
//		scanf("%d",&i);
//		if(i<n)
//		{
//			printf("猜小了\n"); 
//		}
//		else if(i>n)
//		{
//			printf("猜大了\n");
//		}
//		else
//		{
//			printf("恭喜你，猜对了\n");
//			break; 
//		}
//	}
//}
//void menu()
//{
//	printf("###########################\n");
//	printf("###########################\n");
//	printf("###########################\n");
//	printf("###  1.play    0.exit   ###\n");
//	printf("###########################\n");
//	printf("###########################\n");
//	printf("###########################\n");
//} 
//int main()
//{
//	int input;
//	do
//	{
//	srand((unsigned int)time(NULL));
//		menu();
//		printf("请选择\n");
//		scanf("%d",&input) ;
//		switch(input)
//		{
//			case 1:
//				game();
//				break; 
//			case 0:
//				printf("退出游戏\n");
//				break;
//			default:
//				printf("选择错误\n");
//				break;
//		}
//	}while(input);
//	return 0;
//} 

















































#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void menu()
{
	printf("#####################\n");
	printf("### 1.play 0.exit ###\n");
	printf("#####################\n");
}
void game()
{
	int n,i;
	i=rand()%100+1;
	while(1)
	{
		printf("猜数字:>\n");
		scanf("%d",&n);
		if(n<i)
		{
			printf("猜小了\n");
		}
		else if(n>i)
		{
			printf("猜大了\n");
		}
		else
		{
			printf("恭喜你，猜对了\n");
			break;
		} 
	}
}
int main()
{
	int input;
	do
	{
		menu();
		srand((unsigned int)time(NULL));
		printf("请选择:>\n");
		scanf("%d",&input);
		switch(input)
		{
			case 1:
			{
				game();
				break;
			} 
			case 0:
			{
				printf("请退出游戏\n");
				break;
			}
			default:
				{
					printf("选择错误\n"); 
					break;
				}
		} 
	}	while(input);
	return 0;
}
