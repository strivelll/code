#include<stdio.h>
#include<graphics.h>	//easyxͼ�ο� ��Ҫ��װ
#include<time.h>
#include<mmsystem.h>				//ͷ�ļ�����ý���豸�ӿ�
#pragma comment(lib,"winmm.lib")	//���ļ�
 
#define INTERVAL 100 //��ǰ��ļ��
int score;
//��α�ʾ�ڿ죿
int flag[4];
void initFlag()
{
	for (int i = 0; i < 4; i++)
	{
		flag[i] = rand() % 4;	//[0-4)
		//printf("%d ", flag[i]);
	}
}
void drawMap()
{
	settextstyle(25, 0, "����");
	settextcolor(RED);
	//���������Ϸ����
	outtextxy(150, 30, "��Ȱ׿��");
 
	char str[30] = { 0 };
	sprintf_s(str, "score:%d", score);
	outtextxy(280, 20, str);
 
	//����������ʽ
	setlinestyle(PS_SOLID, 2);
	setlinecolor(RGB(59, 59, 59));
	for (int i = 0; i < 5; i++)
	{
		line(0, i * 150 + INTERVAL, 400, i * 150 + INTERVAL);
		line(i * 100, INTERVAL, i * 100, 700);
	}
	//���ƺڿ�
	setfillcolor(BLACK);
	for (int i = 0; i < 4; i++)
	{
		int x = flag[i] * 100;
		int y = i * 150 + INTERVAL;
		fillrectangle(x, y, x + 100, y + 150);
	}
}
bool mouseEvent()
{
	//��ȡ�����Ϣ
	MOUSEMSG msg = GetMouseMsg();
	if (msg.uMsg == WM_LBUTTONDOWN)	//�������
	{
		//��ȡ�������һ���ڿ������(���Ͻ�)
		int x = flag[3] * 100;
		int y = 3 * 150 + INTERVAL;
		//�ж�����Ƿ�����������ĺڿ�
		if (msg.x > x && msg.x<x + 100 && msg.y>y && msg.y < y + 150)
		{
			cleardevice();
			//�����ƶ�������Ԫ�غ���
			for (int i = 3; i >0; i--)
			{
				flag[i] = flag[i - 1];
			}
			//�ѵ�һ���ڿ���������
			flag[0] = rand() % 4;
			score += 10;
		}
		else
		{
			return false;
		}
	}
	return true;
}
//���̰�������Ϸ
bool keyMouse()
{
	return false;
}
void gameOver()
{
	settextstyle(25, 0, "����");
	settextcolor(RED);
	//���������Ϸ����
	outtextxy(150, 30, "Game Over��");
	MessageBox(GetHWnd(), "Game Over��", "low B", MB_OK);
}
int main()
{
	//����BGM 
	mciSendString("open Ұ�����.mp3 alias BGM", NULL, 0, NULL);
	mciSendString("play BGM", NULL, 0, NULL);
 
	//����ͼ�δ��� initgraph(int width, int height, int flag = NULL);	// ��ʼ��ͼ�λ���
	initgraph(400, 700/*,EW_SHOWCONSOLE*/);	//flag ��־���Ƿ���ʾ����̨���ڣ����߹رհ�ť
	//���ñ�����ɫ
	setbkcolor(WHITE);
	cleardevice();
	//�������������
	srand((unsigned)time(NULL));
 
	initFlag();
	while (1)
	{
		drawMap();
		if (!mouseEvent())
			break;
	}
	gameOver();
 
	getchar();
	closegraph();
	return 0;
}
