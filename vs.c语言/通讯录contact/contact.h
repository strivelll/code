#pragma once
//���ͷ�ļ�����һЩ�⺯����ͷ�ļ����ṹ��Ĵ���������һЩֵ�Ķ��壬�����Զ��庯��������
#define _CRT_SECURE_NO_WARNINGS  1
#pragma warning(disable:6031)
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 3
#define NAME 20
#define SEX 10
#define ADDR 20
struct sb {
	char name[NAME];
	int age;
	char sex[SEX];
	long long int tele;
	char addr[ADDR];
	
};
struct contact {
	struct sb*data;
	int contain;
	int size;
}con;
int csh(struct contact* ps);
void addcontact(struct contact* ps);
void menu();
void delcontact(struct contact* ps);
void modifycontact(struct contact* ps);
void searchcontact(const struct contact* ps);
void showcontact(const struct contact* ps);
void sortcontact(struct contact* ps);
int savecontact(struct contact* ps);
void sfnc(struct contact* ps);