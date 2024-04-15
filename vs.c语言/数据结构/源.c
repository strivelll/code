#define _CRT_SECURE_NO_WARNINGS  1
#pragma warning(disable:6031)
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//动态数组
//typedef struct per {
//	void** arr;
//	int m_size;
//	int container;
//}PER;
//typedef struct ss {
//	char name[20];
//	int age;
//}S;
//PER* inti_array(int inti) {
//	PER* p = malloc(sizeof(PER));
//	if (!p) {
//		perror("");
//		return NULL;
//	}
//	PER* cur = p;
//	cur->arr = malloc(inti *sizeof(void*));
//	cur->container = inti;
//	cur->m_size = 0;
//	return cur;
//}
//void array_insert(PER* sum, int n,void* data) {
//	if (sum->m_size >= sum->container) {
//		void* p = realloc(sum->arr, sizeof(void*) * sum->container * 2);
//		if (!p) {
//			perror("");
//			return;
//		}
//		sum->arr = p;
//		printf("增容成功\n");
//	}
//	if (n<0 || n>sum->m_size) {
//		sum->arr[sum->m_size] = data;
//	}
//	else {
//		for (int i = sum->m_size - 1; i >= n; i--) {
//			sum->arr[i + 1] = sum->arr[i];
//		}
//		sum->arr[n] = data;
//	}
//	sum->m_size++;
//	printf("%d\n", sum->m_size);
//	/*printf("插入成功\n");*/
//}
//void my_print(void* a) {
//	S* b = a;
//	printf("性名:%s 年龄:%d\n", b->name, b->age);
//}
//void look_array(PER* sum, void(*myprint)()) {
//	for (int i = 0; i < sum->m_size; i++) {
//		myprint(sum->arr[i]);
//	}
//}
//void delete_bypost_array(PER*sum,int n) {
//	if (sum == NULL) {
//		perror("");
//		return;
//	}
//	for (int i = n; i < sum->m_size; i++) {
//		sum->arr[i] = sum->arr[i + 1];
//	}
//	sum->m_size--;
//}
//void delete_byvalue_array(PER* sum, void* n,void* mycompare(void*,void*) ){
//	if (sum == NULL) {
//		perror("");
//		return;
//	}
//	if (n == NULL) {
//		perror("");
//		return;
//	}
//	for (int i = 0; i < sum->m_size; i++) {
//		if (mycompare(n, sum->arr[i])) {
//			delete_bypost_array(sum, i);
//			break;
//		}
//	}
//
//}
//int mycompare(void* data1, void* data2) {
//	S* a = data1;
//	S* b = data2;
//	return (strcmp(a->name, b->name) == 0 && a->age == b->age);
//}
//int main()
//{
//	PER* sum = inti_array(5);
//	S s1 = { "赵云",18 };
//	S s2 = { "张飞",19 };
//	S s3 = { "关羽",20 };
//	S s4 = { "刘备",19 };
//	S s5 = { "诸葛亮",22 };
//	S s6 = { "黄忠",17 };
//	array_insert(sum, 0, &s1);
//	array_insert(sum, 0, &s2);
//	array_insert(sum, 1, &s3);
//	array_insert(sum, -1, &s4);
//	array_insert(sum, 1, &s5);
//	array_insert(sum, 0, &s6);
//	look_array(sum, my_print);
//	printf("------------------------\n");
//	delete_bypost_array(sum,2);
//	look_array(sum, my_print);
//	printf("------------------------\n");
//	delete_byvalue_array(sum,&s6,mycompare);
//	look_array(sum, my_print);
//	return 0;
//}
//链表:
//typedef struct ss {
//	char name[20];
//	int age;
//}S;
//struct linklist {
//	void* data;
//	struct linklist* next;
//};
//typedef struct llist {
//	struct linklist phead;
//	int size;
//}ll;
//typedef void* list;
//list init_linklist() {
//	ll* cur = NULL;
//	cur = malloc(sizeof(ll));
//	if (!cur) {
//		perror("");
//		return NULL;
//	}
//	//cur->phead.data = NULL;
//	cur->phead.next = NULL;
//	cur->size = 0;
//	return cur;
//}
//void insert_list(list p, int n,void*data) {
//	if (!p) {
//		perror("");
//		return;
//	}
//	if (!data) {
//		perror("");
//		return;
//	}
//	ll* pp = p;
//	if (n<0 || n>pp->size) {
//		n = pp->size;
//	}
//	struct linklist* pcur = &(pp->phead);
//	for (int i = 0; i < n; i++) {
//		pcur = pcur->next;
//	}
//	struct linklist* newp=malloc(sizeof(struct linklist));
//	if (!newp) {
//		perror("");
//		return;
//	}
//	newp->data = data;
//	newp->next = NULL;
//	newp->next = pcur->next;
//	pcur->next = newp;
//	pp->size++;
//}
//void myprintf(void* p) {
//	if (!p) {
//		perror("");
//		return;
//	}
//	S* asd = p;
//	printf("姓名:%s  年龄:%d\n", asd->name, asd->age);
//}
//void looklinklist(list p, void(*myprint)()) {
//	
//	if (!p) {
//		perror("");
//		return;
//	}
//	
//	if (!myprint) {
//		perror("");
//		return;
//	}
//	ll* pp = p;
//	struct linklist* pcur = pp->phead.next;
//	for (int i = 0; i < pp->size; i++) {
//		myprint(pcur->data);
//		pcur = pcur->next;
//	}
//	
//}
//void delete_bypos_linklist(list p,int n) {
//	if (!p) {
//		return;
//	}
//	ll* cur = p;
//	struct linklist* pp = &cur->phead;
//	for (int i = 0; i < n; i++) {
//		pp = pp->next;
//	}
//	struct linklist* p1 = pp->next;
//	pp->next = p1->next;
//	cur->size--;
//	free(p1);
//	p1 = NULL;
//}
//int mycmp(void*data1,void*data2) {
//	S* s1 = data1;
//	S* s2 = data2;
//	return strcmp(s1->name, s2->name)==0 && s1->age == s2->age;
//}
//void delete_byvalue_linklist(list p, void* data,int(*mycomp)() ){
//	if (!p) {
//		return;
//	}
//	ll* cur = p;
//	struct linklist* pp = &cur->phead;
//	struct linklist* p1 = pp->next;
//	for (int i = 0; i < cur->size; i++) {
//		if (mycomp(p1->data, data)) {
//			pp->next = p1->next;
//			cur->size--;
//			free(p1);
//			p1 = NULL;
//			break;
//		}
//		pp = p1;
//		p1 = pp->next;
//	}
//}
//void clear_linklist(list p) {
//	if (!p) {
//		return;
//	}
//	ll* cur = p;
//	struct linklist* pp = &cur->phead;
//	struct linklist* p1 = pp->next;
//	for (int i = 0; i < cur->size-1; i++) {
//		pp->next = p1->next;
//		free(p1);
//		p1 = pp->next;
//	}
//	p1 = NULL;
//	pp->next = NULL;
//	cur->size = 0;
//}
//void deory_linklist(list* p) {
//	if (!p) {
//		return;
//	}
//	clear_linklist(*p);
//	free(*p);
//	*p = NULL;
//}
//int main() {
//	list sum = init_linklist();
//	S s1 = { "赵云",18 };
//	S s2 = { "张飞",19 };
//	S s3 = { "关羽",20 };
//	S s4 = { "刘备",19 };
//	S s5 = { "诸葛亮",22 };
//	S s6 = { "黄忠",17 };
//	insert_list(sum, 0, &s1);
//	insert_list(sum, 0, &s2);
//	insert_list(sum, 1, &s3);
//	insert_list(sum, -1, &s4);
//	insert_list(sum, 1, &s5);
//	insert_list(sum, 100, &s6);
//	looklinklist(sum, myprintf);
//	printf("--------------------\n");
//	delete_bypos_linklist(sum, 1);
//	looklinklist(sum, myprintf);
//	printf("--------------------\n");
//	delete_byvalue_linklist(sum, &s6,mycmp);
//	looklinklist(sum, myprintf);
//	printf("--------------------\n");
//	/*clear_linklist(sum);
//	printf("清空后\n");
//	looklinklist(sum, myprintf);*/
//	deory_linklist(&sum);
//	
//	looklinklist(sum, myprintf);
//	return 0;
//}
//企业版
//typedef struct ss {
//	int* a;
//	char name[20];
//	int age;
//}S;
//struct linklist {
//	struct linklist* next;
//};
//typedef struct llist {
//	struct linklist phead;
//	int size;
//}ll;
//typedef void* list;
//list init_linklist() {
//	ll* cur = NULL;
//	cur = malloc(sizeof(ll));
//	if (!cur) {
//		perror("");
//		return NULL;
//	}
//	cur->phead.next = NULL;
//	cur->size = 0;
//	return cur;
//}
//void insert_list(list p, int n, void* data) {
//	if (!p) {
//		perror("");
//		return;
//	}
//	if (!data) {
//		perror("");
//		return;
//	}
//	ll* pp = p;
//	if (n<0 || n>pp->size-1) {
//		n = pp->size;
//	}
//	struct linklist* pcur = &(pp->phead);
//	for (int i = 0; i < n; i++) {
//		pcur = pcur->next;
//	}
//	struct linklist* newp = data;
//	newp->next = pcur->next;
//	pcur->next = newp;
//	pp->size++;
//}
//void myprintf(void* p) {
//	if (!p) {
//		perror("");
//		return;
//	}
//	S* asd = p;
//	printf("姓名:%s  年龄:%d\n", asd->name, asd->age);
//}
//void looklinklist(list p, void(*myprint)()) {
//
//	if (!p) {
//		perror("");
//		return;
//	}
//
//	if (!myprint) {
//		perror("");
//		return;
//	}
//	ll* pp = p;
//	struct linklist* pcur = pp->phead.next;
//	for (int i = 0; i < pp->size; i++) {
//		myprint(pcur);
//		pcur = pcur->next;
//	}
//}
//void delete_bypos_linklist(list p, int n) {
//	if (!p) {
//		return;
//	}
//	ll* cur = p;
//	struct linklist* pp = &cur->phead;
//	for (int i = 0; i < n; i++) {
//		pp = pp->next;
//	}
//	struct linklist* p1 = pp->next;
//	pp->next = p1->next;
//	cur->size--;
//}
//int mycmp(void* data1, void* data2) {
//	S* s1 = data1;
//	S* s2 = data2;
//	return strcmp(s1->name, s2->name) == 0 && s1->age == s2->age;
//	
//}
//void delete_byvalue_linklist(list p, void* data, int(*mycomp)()) {
//	if (!p) {
//		return;
//	}
//	ll* cur = p;
//	struct linklist* pp = &cur->phead;
//	struct linklist* p1 = pp->next;
//	for (int i = 0; i < cur->size; i++) {
//		if (mycomp(p1, data)) {
//			pp->next = p1->next;
//			cur->size--;
//			break;
//		}
//		pp = p1;
//		p1 = pp->next;
//	}
//}
//void deory_linklist(list p) {
//	if (!p) {
//		return;
//	}
//	ll* cur = p;
//	free(cur);
//	cur = NULL;
//}
//int main() {
//	list sum = init_linklist();
//	S s1 = { NULL,"赵云",18 };
//	S s2 = { NULL,"张飞",19 };
//	S s3 = { NULL,"关羽",20 };
//	S s4 = { NULL,"刘备",19 };
//	S s5 = { NULL,"诸葛亮",22 };
//	S s6 = { NULL,"黄忠",17 };
//	int a = 1;
//	int b = 2;
//	int c = 3;
//	int d = 4;
//	int e = 5;
//	int f = 6;
//	insert_list(sum, 0, &s1);
//	insert_list(sum, 0, &s2);
//	insert_list(sum, 1, &s3);
//	insert_list(sum, -1, &s4);
//	insert_list(sum, 1, &s5);
//	insert_list(sum, 100, &s6);
//	looklinklist(sum, myprintf);
//	printf("--------------------\n");
//	delete_bypos_linklist(sum, 1);
//	looklinklist(sum, myprintf);
//	printf("--------------------\n");
//	delete_byvalue_linklist(sum, &s6, mycmp);
//	looklinklist(sum, myprintf);
//	printf("--------------------\n");
//	deory_linklist(sum);
//	looklinklist(sum, myprintf);
//	return 0;
//}
//队列:
typedef struct ss {
	int* a;
	char name[20];
	int age;
}S;
struct linklist {
	struct linklist* next;
};
typedef struct llist {
	struct linklist phead;
	int size;
	struct linklist* ptail;
}ll;
typedef void* list;
list init_linklist() {
	ll* cur = NULL;
	cur = malloc(sizeof(ll));
	if (!cur) {
		perror("");
		return NULL;
	}
	cur->phead.next = NULL;
	cur->ptail = &cur->phead;
	cur->size = 0;
	return cur;
}
void insert_list(list p, void* data) {
	if (!p) {
		perror("");
		return;
	}
	if (!data) {
		perror("");
		return;
	}
	ll* pp = p;
	struct linklist* newp = data;
	newp->next = NULL;
	pp->ptail->next = newp;
	pp->ptail = newp;
	pp->size++;
}
void delete_bypos_linklist(list p) {
	if (!p) {
		return;
	}
	ll* cur = p;
	if (cur->size == 0) {
		return;
	}
	if (cur->size == 1) {
		cur->phead.next = NULL;
		cur->ptail = &cur->phead;
		cur->size--;
		return;
	}
	struct linklist* pp = &cur->phead;
	struct linklist* p1 = pp->next;
	pp->next = p1->next;
	cur->size--;
}
void* look_headerqueue(list p) {
	if (!p) {
		return NULL;
	}
	ll* cur = p;
	struct linklist* pp = &cur->phead;
	return pp->next;
}
void* look_tailqueue(list p) {
	if (!p) {
		return NULL;
	}
	ll* cur = p;
	return cur->ptail;
}
int sizeofqueue(list p) {
	if (!p) {
		return -1;
	}
	ll* cur = p;
	return cur->size;
}
int isempty(list p) {
	if (!p) {
		return -1;
	}
	ll* cur = p;
	return cur->size==0;
}
void deory_linklist(list p) {
	if (!p) {
		return;
	}
	free(p);
	p = NULL;
}
int main() {
	list sum = init_linklist();
	S s1 = { NULL,"赵云",18 };
	S s2 = { NULL,"张飞",19 };
	S s3 = { NULL,"关羽",20 };
	S s4 = { NULL,"刘备",19 };
	S s5 = { NULL,"诸葛亮",22 };
	S s6 = { NULL,"黄忠",17 };
	insert_list(sum, &s1);
	insert_list(sum, &s2);
	insert_list(sum, &s3);
	insert_list(sum, &s4);
	insert_list(sum, &s5);
	insert_list(sum, &s6);
	printf("%d\n", sizeofqueue(sum));
	while (sizeofqueue(sum) != 0) {
		S* s9=look_headerqueue(sum);
		printf("姓名:%s 年龄:%d\n", s9->name, s9->age);
		delete_bypos_linklist(sum);
	}
	printf("%d\n", sizeofqueue(sum));
	deory_linklist(sum);
	return 0;
}