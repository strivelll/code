#define _CRT_SECURE_NO_WARNINGS  1
#pragma warning(disable:6031)
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>
void getdata() {
	srand((unsigned int)time(NULL));
	int n = 10;
	char c[4] = { '+','-','*','/' };
	FILE* P = fopen("size.txt", "w");
	if (!P) {
		perror("");
		exit(0);
	}
	while (n--)
	{
		int a = rand() % 100+1;
		int b = rand() % 100+1;
		int i = rand() % 4;
		fprintf(P, "%d%c%d=\n", a, c[i], b);
	}
	fclose(P);
	P = NULL;
}
void jsdata() {
	FILE* P = fopen("size.txt", "r+");
	if (!P) {
		perror("");
		exit(0);
	}
	int a, b;
	char c;
	char* buf[10]={0};
	for (int i = 0; i < 10; i++) {
		buf[i] = (char*)malloc(20);
		fgets(buf[i],20,P);
	}
	rewind(P);
	for (int i = 0; i < 10; i++) {
		sscanf(buf[i],"%d%c%d=\n",&a,&c,&b);
	int sum = 0;
		switch (c){
		case '+':
			sum = a + b;
			break;
		case '-':
			sum = a - b;
			break;
		case '*':
			sum = a * b;
			break;
		case '/':
			sum = a / b;
			break;
		}
		fprintf(P, "%02d%c%02d=%d\n", a, c, b, sum);
	}
	fclose(P);
}
int main()
{
	getdata();
	jsdata();
	return 0;
}