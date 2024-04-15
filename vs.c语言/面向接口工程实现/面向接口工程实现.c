#define _CRT_SECURE_NO_WARNINGS  1
#pragma warning(disable:6031)
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef void (*init_game)(void** player, char* name);
typedef int(*fight_game)(void* player, int diff);
typedef void(*look_contents)(void* player);
typedef void(*exit_game)(void* player);
void start_game(init_game init, fight_game fight, look_contents look, exit_game exit)
{
	void* player = NULL;
	char buf[1024] = { 0 };
	printf("请输入玩家姓名:>\n");
	scanf("%s", &buf);
	init(&player, buf);
	int diff = 0;
	printf("请选择难度:>\n");
	printf("1.简单  2.中等  3.困难\n");
	scanf("%d", &diff);
	if (fight(player, diff)) {
		printf("玩家胜利\n");
		printf("玩家当前状态为:>\n");
		look(player);
	}
	else {
		printf("玩家失败\n");
	}
	exit(player);
}
int main()
{
	return 0;
}