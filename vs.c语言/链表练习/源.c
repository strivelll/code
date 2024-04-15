#define _CRT_SECURE_NO_WARNINGS  1
#pragma warning(disable:6031)
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//链表的初始化
struct linklist {
	int num;
	struct linklist* nest;
};
struct linklist* init_linklist() {
	struct linklist* pheader = malloc(sizeof(struct linklist));
	if (!pheader)
	{
		return NULL;
	}
	pheader->num = -1;
	pheader->nest = NULL;
	struct linklist* ptail = pheader;
	int n=0;
	while (1) {
		printf("请输入数据,输入0即结束:>\n");
		scanf("%d", &n);
		if (n == 0) {
			break;
		}
		struct linklist* newnote = malloc(sizeof(struct linklist));
		if (!newnote) {
			return NULL;
		}
		newnote->num = n;
		newnote-> nest= NULL;
		ptail->nest = newnote;
		ptail = newnote;
	}
	return pheader;
}
//链表操作-插入功能实现
void insert_data(struct linklist* pheader, int cur, int dest) {
	struct linklist* fp = pheader->nest;
	struct linklist* ptail = fp;
	while (fp) {
		if (fp->num == cur) {
			struct linklist* ef = malloc(sizeof(struct linklist));
			if (!ef) {
				return;
			}
			ptail->nest = ef;
			ef->num = dest;
			ef->nest = fp;
			return;
		}
		ptail = fp;
		fp = fp->nest;
	}
}
//链表遍历
void print(struct linklist* p) {
	if (p == NULL) {
		return;
	}
	struct linklist* fp = p->nest;
	while (fp) {
		printf("%d\n", fp->num);
		fp = fp->nest;
	}
}

int main()
{
	struct linklist* pheader = init_linklist();
   insert_data(pheader,20,100);
	print(pheader);
	return 0;
}