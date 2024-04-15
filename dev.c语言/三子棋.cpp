#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
# define ROW 3
# define COL 3
int isfull(char borad[ROW][COL],int row,int col)
{
	for(int i=0;i<row;i++)
	{
		for(int j=0;j<col;j++)
		{
			if(borad[i][j]==' ')
			{
				return 0;
			}
		}
	}
	return 1;
}
char iswin(char borad[ROW][COL],int row,int col)
{
	for(int i=0;i<row;i++)
	{
		if(borad[i][0]==borad[i][1]&&borad[i][1]==borad[i][2]&&borad[i][0]!=' ')
		{
			return borad[i][0];
		}
	}
	for(int i=0;i<col;i++)
	{
		if(borad[0][i]==borad[1][i]&&borad[1][i]==borad[2][i]&&borad[0][i]!=' ')
		{
			return borad[1][i];
		}
	}
	if(borad[0][0]==borad[1][1]&&borad[1][1]==borad[2][2]&&borad[0][0]!=' ')
	{
		return borad[0][0];
	}
	if(borad[0][2]==borad[1][1]&&borad[1][1]==borad[2][0]&&borad[0][2]!=' ')
	{
		return borad[0][2];
	}
	if(isfull(borad, ROW, COL)==1)
	{
		return 'q';
	}
	else
	{
		return 'c';
	}
}
void dnplay(char borad[ROW][COL],int row,int col)
{
	printf("������:>\n");
	
	while(1)
	{
		int x=rand()%row;
		int y=rand()%col;
		if(borad[x][y]==' ')
		{
			borad[x][y]='#';
			break; 
		}
	}
}
void wjplay(char borad[ROW][COL],int row,int col)
{
	int x,y;
	printf("�����:>\n");
	while(1)
	{
		scanf("%d%d",&x,&y);
		if(x>=1&&x<=row&&y>=1&&y<=col)
		{
			if(borad[x-1][y-1]==' ')
			{
				borad[x-1][y-1]='*';
				break; 
			}
			else
			{
				printf("��λ���Ա�ռ��:>\n");
			}
		}
		else
		{
			printf("����Ƿ�,����������:>\n");
		}
	}
}
void chush(char borad[ROW][COL], int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			borad[i][j] = ' ';
		}
	}
}
void display(char borad[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		int j = 0;
		for (j = 0; j < col; j++)
		{
			printf(" %c ", borad[i][j]);
			if (j < col - 1)
				printf("|");
		}
		printf("\n");
		if (i < row - 1)
		{
			for (j = 0; j < col; j++)
			{
				printf("---");
				if (j < col - 1)
				{
					printf("|");
				}
			}
		}
		printf("\n");
	}
}
void game()
{
	char ret;
	char borad[ROW][COL] = {0};
	chush(borad, ROW, COL);
	display(borad, ROW, COL);
	while(1)
	{
	wjplay(borad, ROW, COL);
	display(borad, ROW, COL);
	ret=iswin(borad, ROW, COL);
	if(ret!='c')
	{
		break;
	}
	dnplay(borad, ROW, COL);
	display(borad, ROW, COL);
	ret=iswin(borad, ROW, COL);
	if(ret!='c')
	{
		break;
	}
	}
	if(ret=='*')
	{
		printf("��ϲ��Ӯ�ˣ�����\n");
	}
	if (ret=='#')
	{
		printf("���ź�������\n");
	}
	if(ret=='q')
	{
		printf("ƽ��\n");
	}
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
	srand((unsigned int)time(NULL));
	do
	{
		
		menu();
		printf("������:>\n");
		scanf("%d", &imput);
		switch (imput)
		{
		case 1:
			printf("��Ϸ��ʼ\n");
			game(); 
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
