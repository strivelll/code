#define _CRT_SECURE_NO_WARNINGS  1
#pragma warning(disable:6031)
#define WIDE 60
#define HIGH 20
#include<stdio.h>
#include<windows.h>
#include<time.h>
#include<conio.h>
typedef struct BODY {
	int x;
	int y;
}body;
typedef struct SNAKE {
	int size;
	body list[WIDE * HIGH];
	body food;
	int scord;
	COORD coord;
	int dx;
	int dy;
	body tail;
}SNAKE;
//打印墙
void print_wall(SNAKE* snake) {
	for (int i = 0; i <= HIGH; i++) {
		for (int j = 0; j <= WIDE; j++) {
			if (j == WIDE || HIGH == i) {
				printf("+");
			}
			else
				printf(" ");
		}
		printf("\n");
	}
}
void hide_cur() {
	//隐藏光标
	CONSOLE_CURSOR_INFO cci;
	cci.dwSize = sizeof(cci);
	cci.bVisible = FALSE;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cci);
}
void inti_food(SNAKE* snake) {
	//食物坐标随机产生
	srand(time(NULL));
	snake->food.x = rand() % WIDE;
	snake->food.y = rand() % HIGH;
}
void inti_snake(SNAKE* snake) {
	//初始化
	//最开始的蛇坐标
	snake->list[0].x = WIDE / 2;
	snake->list[0].y= HIGH / 2;
	snake->list[1].x = WIDE / 2-1;
	snake->list[1].y = HIGH / 2;
	//一开始的移动方向
	snake->dx = 1;
	snake->dy = 0;
	//分数初始化
	snake->scord = 0;
	//食物初始化
	inti_food(snake);
	//身体长度初始化
	snake->size = 2;

}
void show_ui(SNAKE* snake) {
	//根据坐标打印头
	snake->coord.X = snake->list[0].x;
	snake->coord.Y = snake->list[0].y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), snake->coord);
		printf("@");
		//根据坐标打印身体
	for (int i = 1; i < snake->size; i++) {
		snake->coord.X = snake->list[i].x;
		snake->coord.Y = snake->list[i].y;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), snake->coord);
			printf("*");
	}
	//根据坐标打印食物
	snake->coord.X = snake->food.x;
	snake->coord.Y = snake->food.y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), snake->coord);
	printf("#");
}
void control_snake(SNAKE* snake) {
	char key=0;
	//_kbhit()按住则循环继续,松开则循环结束;
	while (_kbhit()) {
		key = _getch();
	}
	switch (key) {
	case 'd':
		snake->dx = 1;
		snake->dy = 0;
		break;
	case 'a':
		snake->dx =-1;
		snake->dy = 0;
		break;
	case 's':
		snake->dx = 0;
		snake->dy = 1;
		break;
	case 'w':
		snake->dx = 0;
		snake->dy = -1;
		break;
	default:
		break;
	}
}
void move_snake(SNAKE* snake) {
	//这里记住尾巴的坐标,在之后把尾巴去掉
	snake->tail.x = snake->list[snake->size - 1].x;
	snake->tail.y = snake->list[snake->size - 1].y;
	for (int i = snake->size - 1; i > 0; i--) {
		snake->list[i] = snake->list[i - 1];
	}
	snake->list[0].x += snake->dx;
	snake->list[0].y += snake->dy;
	//把打印的开始坐标设置好
	snake->coord.X = snake->tail.x;
	snake->coord.Y = snake->tail.y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), snake->coord);
	printf(" ");
}
void eat_food(SNAKE* snake) {
	if (snake->list[0].x == snake->food.x && 
		snake->list[0].y == snake->food.y) {
		inti_food(snake);
		snake->size++;
		//分梯度,不同难度下分数不一样
		if(snake->size<12)
		snake->scord += 10;
		else if (snake->size < 112 && snake->size > 12) {
			snake->scord += 20;
		}
		else
			snake->scord += 40;
	}
}
void end_game(SNAKE* snake) {
	snake->coord.X = 20;
	snake->coord.Y = 30;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), snake->coord);
	printf("游戏结束,你获得的积分为: %d\n", snake->scord);
	//直接退出程序
	exit(0);
}
void eat_body(SNAKE* snake) {
	for (int i = 1; i < snake->size; i++) {
		if (snake->list[0].x == snake->list[i].x &&
			snake->list[0].y == snake->list[i].y) {
			//判断头的坐标是否和所有身体的坐标重复,重复直接结束游戏
			end_game(snake);
		}
	}
}
void start_game(SNAKE* snake) {
	while (snake->list[0].x>0&& snake->list[0].x <WIDE && 
		snake->list[0].y > 0 && snake->list[0].y<HIGH) {
		control_snake(snake);//控制射的移动;
		move_snake(snake);//更新坐标
		show_ui(snake);//用更新好的坐标再次刷新屏幕
		eat_food(snake);//吃到食物后的影响
		eat_body(snake);//吃到自己的身体的影响
		if (snake->size < 12)//增加游戏难度越后面越速度越快
			Sleep(200);
		else if (snake->size < 112 && snake->size > 12)
			Sleep(100);
		else
			Sleep(50);
	}
}
int main()
{
	SNAKE *snake=(SNAKE *)malloc(sizeof(SNAKE));
	hide_cur();//隐藏光标
	print_wall(snake);
	inti_snake(snake);//初始化蛇的各种数据
	show_ui(snake);//显示屏幕
	start_game(snake);//开始游戏
	end_game(snake);//游戏结束
	return 0;
}