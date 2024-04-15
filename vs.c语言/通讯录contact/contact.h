#pragma once
//这个头文件包括一些库函数的头文件，结构体的创建，还有一些值的定义，还有自定义函数的声明
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