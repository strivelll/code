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
//	printf("������:>\n");
//		scanf("%d",&i);
//		if(i<n)
//		{
//			printf("��С��\n"); 
//		}
//		else if(i>n)
//		{
//			printf("�´���\n");
//		}
//		else
//		{
//			printf("��ϲ�㣬�¶���\n");
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
//		printf("��ѡ��\n");
//		scanf("%d",&input) ;
//		switch(input)
//		{
//			case 1:
//				game();
//				break; 
//			case 0:
//				printf("�˳���Ϸ\n");
//				break;
//			default:
//				printf("ѡ�����\n");
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
		printf("������:>\n");
		scanf("%d",&n);
		if(n<i)
		{
			printf("��С��\n");
		}
		else if(n>i)
		{
			printf("�´���\n");
		}
		else
		{
			printf("��ϲ�㣬�¶���\n");
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
		printf("��ѡ��:>\n");
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
				printf("���˳���Ϸ\n");
				break;
			}
			default:
				{
					printf("ѡ�����\n"); 
					break;
				}
		} 
	}	while(input);
	return 0;
}
