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
//��ӡǽ
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
	//���ع��
	CONSOLE_CURSOR_INFO cci;
	cci.dwSize = sizeof(cci);
	cci.bVisible = FALSE;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cci);
}
void inti_food(SNAKE* snake) {
	//ʳ�������������
	srand(time(NULL));
	snake->food.x = rand() % WIDE;
	snake->food.y = rand() % HIGH;
}
void inti_snake(SNAKE* snake) {
	//��ʼ��
	//�ʼ��������
	snake->list[0].x = WIDE / 2;
	snake->list[0].y= HIGH / 2;
	snake->list[1].x = WIDE / 2-1;
	snake->list[1].y = HIGH / 2;
	//һ��ʼ���ƶ�����
	snake->dx = 1;
	snake->dy = 0;
	//������ʼ��
	snake->scord = 0;
	//ʳ���ʼ��
	inti_food(snake);
	//���峤�ȳ�ʼ��
	snake->size = 2;

}
void show_ui(SNAKE* snake) {
	//���������ӡͷ
	snake->coord.X = snake->list[0].x;
	snake->coord.Y = snake->list[0].y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), snake->coord);
		printf("@");
		//���������ӡ����
	for (int i = 1; i < snake->size; i++) {
		snake->coord.X = snake->list[i].x;
		snake->coord.Y = snake->list[i].y;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), snake->coord);
			printf("*");
	}
	//���������ӡʳ��
	snake->coord.X = snake->food.x;
	snake->coord.Y = snake->food.y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), snake->coord);
	printf("#");
}
void control_snake(SNAKE* snake) {
	char key=0;
	//_kbhit()��ס��ѭ������,�ɿ���ѭ������;
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
	//�����סβ�͵�����,��֮���β��ȥ��
	snake->tail.x = snake->list[snake->size - 1].x;
	snake->tail.y = snake->list[snake->size - 1].y;
	for (int i = snake->size - 1; i > 0; i--) {
		snake->list[i] = snake->list[i - 1];
	}
	snake->list[0].x += snake->dx;
	snake->list[0].y += snake->dy;
	//�Ѵ�ӡ�Ŀ�ʼ�������ú�
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
		//���ݶ�,��ͬ�Ѷ��·�����һ��
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
	printf("��Ϸ����,���õĻ���Ϊ: %d\n", snake->scord);
	//ֱ���˳�����
	exit(0);
}
void eat_body(SNAKE* snake) {
	for (int i = 1; i < snake->size; i++) {
		if (snake->list[0].x == snake->list[i].x &&
			snake->list[0].y == snake->list[i].y) {
			//�ж�ͷ�������Ƿ����������������ظ�,�ظ�ֱ�ӽ�����Ϸ
			end_game(snake);
		}
	}
}
void start_game(SNAKE* snake) {
	while (snake->list[0].x>0&& snake->list[0].x <WIDE && 
		snake->list[0].y > 0 && snake->list[0].y<HIGH) {
		control_snake(snake);//��������ƶ�;
		move_snake(snake);//��������
		show_ui(snake);//�ø��ºõ������ٴ�ˢ����Ļ
		eat_food(snake);//�Ե�ʳ����Ӱ��
		eat_body(snake);//�Ե��Լ��������Ӱ��
		if (snake->size < 12)//������Ϸ�Ѷ�Խ����Խ�ٶ�Խ��
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
	hide_cur();//���ع��
	print_wall(snake);
	inti_snake(snake);//��ʼ���ߵĸ�������
	show_ui(snake);//��ʾ��Ļ
	start_game(snake);//��ʼ��Ϸ
	end_game(snake);//��Ϸ����
	return 0;
}