#include<stdio.h>
#include<graphics.h>	//easyx图形库 需要安装
#include<time.h>
#include<mmsystem.h>				//头文件：多媒体设备接口
#pragma comment(lib,"winmm.lib")	//库文件
 
#define INTERVAL 100 //最前面的间隔
int score;
//如何表示黑快？
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
	settextstyle(25, 0, "黑体");
	settextcolor(RED);
	//输出文字游戏结束
	outtextxy(150, 30, "别踩白块儿");
 
	char str[30] = { 0 };
	sprintf_s(str, "score:%d", score);
	outtextxy(280, 20, str);
 
	//设置线条样式
	setlinestyle(PS_SOLID, 2);
	setlinecolor(RGB(59, 59, 59));
	for (int i = 0; i < 5; i++)
	{
		line(0, i * 150 + INTERVAL, 400, i * 150 + INTERVAL);
		line(i * 100, INTERVAL, i * 100, 700);
	}
	//绘制黑快
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
	//获取鼠标消息
	MOUSEMSG msg = GetMouseMsg();
	if (msg.uMsg == WM_LBUTTONDOWN)	//左键按下
	{
		//获取最下面的一个黑快的坐标(左上角)
		int x = flag[3] * 100;
		int y = 3 * 150 + INTERVAL;
		//判断鼠标是否点击的最下面的黑快
		if (msg.x > x && msg.x<x + 100 && msg.y>y && msg.y < y + 150)
		{
			cleardevice();
			//整体移动，数组元素后移
			for (int i = 3; i >0; i--)
			{
				flag[i] = flag[i - 1];
			}
			//把第一个黑快重新生成
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
//键盘按下玩游戏
bool keyMouse()
{
	return false;
}
void gameOver()
{
	settextstyle(25, 0, "黑体");
	settextcolor(RED);
	//输出文字游戏结束
	outtextxy(150, 30, "Game Over！");
	MessageBox(GetHWnd(), "Game Over！", "low B", MB_OK);
}
int main()
{
	//播放BGM 
	mciSendString("open 野蜂飞舞.mp3 alias BGM", NULL, 0, NULL);
	mciSendString("play BGM", NULL, 0, NULL);
 
	//创建图形窗口 initgraph(int width, int height, int flag = NULL);	// 初始化图形环境
	initgraph(400, 700/*,EW_SHOWCONSOLE*/);	//flag 标志，是否显示控制台窗口，或者关闭按钮
	//设置背景颜色
	setbkcolor(WHITE);
	cleardevice();
	//设置随机数种子
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
