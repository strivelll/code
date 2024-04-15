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
	printf("�������������:>\n");
	scanf("%s", &buf);
	init(&player, buf);
	int diff = 0;
	printf("��ѡ���Ѷ�:>\n");
	printf("1.��  2.�е�  3.����\n");
	scanf("%d", &diff);
	if (fight(player, diff)) {
		printf("���ʤ��\n");
		printf("��ҵ�ǰ״̬Ϊ:>\n");
		look(player);
	}
	else {
		printf("���ʧ��\n");
	}
	exit(player);
}
int main()
{
	return 0;
}