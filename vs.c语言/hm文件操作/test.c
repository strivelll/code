#define _CRT_SECURE_NO_WARNINGS  1
#pragma warning(disable:6031)
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct students {
	char name[64];
	int age;
}stu;
typedef struct teacher{
	char* name;
	stu ** students;
}TEA;

TEA** inti_space() {
	TEA** p = malloc(sizeof(TEA*) * 4);
	if (!p) {
		perror("");
		exit(0);
	}
	for (int i = 0; i < 4; i++) {
		p[i] = malloc(sizeof(TEA));
		if (p[i] == NULL) {
			perror("");
			exit(0);
		}
		p[i]->name = malloc(64);
		if (p[i]->name == NULL) {
			perror("");
			exit(0);
		}
		sprintf(p[i]->name, "teacher_%d", i + 1);
		p[i]->students = malloc(sizeof(stu *) * 4);
		if (p[i]->students == NULL) {
			perror("");
			exit(0);
		}
		for (int j = 0; j < 4; j++) {
			(p[i]->students)[j] = malloc(sizeof(stu));
			if ((p[i]->students)[j] == NULL) {
				perror("");
				exit(0);
			}
			(p[i]->students)[j]->age = 20 + j;

			sprintf((p[i]->students)[j]->name, "student_%d",j+1);
		}
	}
	return p;
}
void print_parray(TEA** p) {
	for (int i = 0; i < 4; i++) {
		printf("%s\n", p[i]->name);
		for (int j = 0; j < 4; j++) {
			printf("name: %s   age: %d\n", (p[i]->students)[j]->name, (p[i]->students)[j]->age);
		}
	}
}
void free_space(TEA** p) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if ((p[i]->students)[j]) {
				free((p[i]->students)[j]);
				(p[i]->students)[j] = NULL;
			}
		}
		free(p[i]->students);
		p[i]->students = NULL;
		free(p[i]->name);
		p[i]->name = NULL;
		free(p[i]);
		p[i] = NULL;
	}
}
int main()
{
	TEA** p =inti_space();
	print_parray(p);
	free_space(p);
	p = NULL;
	return 0;
}