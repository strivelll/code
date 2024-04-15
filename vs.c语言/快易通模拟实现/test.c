#define _CRT_SECURE_NO_WARNINGS  1
#pragma warning(disable:6031)
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct dict{
	char* key;
	char* content;
}A;
int count(FILE* p) {
	int i = 0;
	char buf[256]="";
	while (1) {
		char*pr= fgets(buf, sizeof(buf), p);
		if (!pr) {
			return i;
		}
		pr= fgets(buf, sizeof(buf), p);
		if (!pr) {
			return i;
		}
		i++;
	}
	return i;
}
void houz(char* p) {
	int i = strlen(p) - 1;
	while (1) {
		if (p[i] == '\n' || p[i] == ' ' || p[i] == '\r' || p[i] == '\t') {
			i--;
		}
		else
		{
			p[i + 1] = '\0';
			break;
		}
	}
}
void dqwj(A* a,FILE*P,int n) {
	char buf[256]="";
	for(int i=0;i<n;i++)
	{
		fgets(buf, sizeof(buf), P);
		houz(buf);
		//printf("%s\n", buf);
		a[i].key = (char*)malloc(strlen(buf) + 1);
		if (!a[i].key) {
			perror("");
			exit(0);
		}
		strcpy(a[i].key, buf+1);
		fgets(buf, sizeof(buf), P);
		//houz(buf,n);
		//printf("%s\n", buf);
		a[i].content = (char*)malloc(strlen(buf) + 1);
		if (!a[i].content) {
			perror("");
			exit(0);
		}
		strcpy(a[i].content, buf+6);
	}
	fclose(P);
}
int seachercontent(A* a,char* shur, char* count,int n) {
	for (int i = 0; i < n; i++) {
		if (strcmp(shur, a[i].key) == 0) {
			strcpy(count, a[i].content);
			return 1;
		}
		
	}
return 0;
}
int main()
{
	FILE* P = fopen("dict.txt", "r");
	if (!P) {
		perror("");
		exit(0);
	}
	int n = count(P);
	printf("%d\n", n);
	A* a = (A*)malloc(n * sizeof(A));
	if (!a) {
		perror("");
		exit(0);
	}
	rewind(P);
	char content[256] ="";
	char shur[256] ="";
	dqwj(a, P,n);
	while (1){
		printf("ÇëÊäÈëÄãÏë·­ÒëµÄÄÚÈÝ:>");
	fgets(shur,sizeof(shur), stdin);
	shur[strlen(shur) - 1] = 0;
	int ret = seachercontent(a,shur,content,n);
	if (ret) {
		printf("·­ÒëÎª:%s", content);
	}
	else
		printf("no found\n");
}
	return 0;
}
//#include<stdio.h>
//#include<string.h>
//int main()
//{
//	FILE* fp = fopen("dict.txt", "w");
//	int i = 2;
//	while (i--) {
//		char buf[256]="";
//		scanf("%s", &buf);
//		buf[strlen(buf)] = '\n';
//		fputs(buf, fp);
//		scanf("%s", &buf);
//		buf[strlen(buf)] = '\n';
//		fputs(buf, fp);
//	}
//	fclose(fp);
//	fp = NULL;
//	return 0;
//}