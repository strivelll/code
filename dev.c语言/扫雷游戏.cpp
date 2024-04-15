#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define ROW 9
#define COL 9
#define ROWS ROW+2
#define COLS COL+2
#define EASY 10

void display(char borad[ROWS][COLS],int row,int col)
{
	for(int i=0;i<=col;i++)
	{
		printf("%d ",i);
	}
	printf("\n");
	for(int i=1;i<=row;i++)
	{
		printf("%d ",i);
		for(int j=1;j<=col;j++)
		{
			printf("%c ",borad[i][j]);
		}
		printf("\n"); 
	}
}
int count(char mine[ROWS][COLS],int x,int y)
{
	return mine[x][y-1]+
	mine[x][y+1]+
	mine[x-1][y]+
	mine[x-1][y-1]+
	mine[x-1][y+1]+
	mine[x+1][y]+
	mine[x+1][y+1]+
	mine[x+1][y-1]-8*'0';
}
void find(char mine[ROWS][COLS],char show[ROWS][COLS],int row,int col)
{
	int x,y;
	int c=0;
	while(c<row*col-EASY)
	{
		printf("请输入坐标:>\n");
		scanf("%d%d",&x,&y);
		if(x>=1&&x<=row&&y>=1&&y<=col)
		{
			if(mine[x][y]=='1')
			{
				printf("很遗憾，你被炸死了\n"); 
				display(mine,ROW,COL);
				break;
			}
			else
			{
				int sl=count(mine,x,y);
				show[x][y]=sl+'0';
				display(show,ROW,COL);
				c++;
			}
		}
		else
		{
			printf("坐标错误，请重新输入\n");
		}
	}
	if(c==row*col-EASY)
	{
		printf("恭喜你，扫雷成功:>\n");
	}
}
void insert(char mine[ROWS][COLS],int row,int col)
{
	
	int count=EASY;
	while(count)
	{
		int x=rand()%row+1;
		int y=rand()%col+1;
		if(mine[x][y]=='0')
		{
			mine[x][y]='1';
			count--;
		}
	}
}
void csh(char show[ROWS][COLS],int rows,int cols,char set)
{
	for(int i=0;i<rows;i++)
	{
		for(int j=0;j<cols;j++)
		{
			show[i][j]=set;
		}
	}
}
void game()
{
	char show[ROWS][COLS];
	char mine[ROWS][COLS];
	csh(show,ROWS,COLS,'#');
	csh(mine,ROWS,COLS,'0');
	display(show,ROW,COL);
	insert(mine,ROW,COL);
//	display(mine,ROW,COL);
	find(mine,show,ROW,COL);
}
void menu()
{
	printf("########################\n");
	printf("#####1.play  0.exit#####\n");
	printf("########################\n");
}
void test()
{
	srand((unsigned int)time(NULL));
	int input;
	do
	{
		menu();
		printf("请输入:>\n");
		scanf("%d",&input);
		switch(input)
		{
			case 1:
				{
					printf("游戏开始:>\n");
					game();
					break;
				}
			case 0:
				{
					printf("退出游戏\n");
					break;
				}
			default :
				{
					printf("输入错误，请重新输入\n");
					break; 
				}
		}
		
	}while(input);
}
int main()
{
	test();
	return 0;
} 
