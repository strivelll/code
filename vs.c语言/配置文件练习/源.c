#define _CRT_SECURE_NO_WARNINGS  1
#pragma warning(disable:6031)
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct configinfo {
	char key[64];
	char value[64];
}con;
int cal() {
	int lines = 0;
	FILE* fp = fopen("test..txt", "r");
	if (!fp) {
		perror("文件打开失败");
		exit(0);
	}
	char buf[1024] = { 0 };
	while (fgets(buf, 1024, fp)) {
		if(strchr(buf,':'))
		lines++;
		memset(buf, 0, 1024);
	}
	fclose(fp);
	fp = NULL;
	return lines;
}
void copy_file(con* p,int lines) {
	FILE* fp = fopen("test..txt", "r");
	char buf[1024] = { 0 };
	char* pos=NULL;
	for (int i = 0; i < lines; i++) {
		while (fgets(buf, 1024, fp)) {
			if (pos=strchr(buf, ':')) {
				strncpy(p[i].key, buf, pos - buf);
				strncpy(p[i].value,pos+1,strlen(pos+1)-1);
				/*sscanf(buf, "%s:%s", &p[i].key, &p[i].value);*/
				break;
			}
			memset(buf, 0, 1024);
		}
	}
	fclose(fp);
	fp = NULL;
}
void my_print(con* p,int n) {
	for (int i = 0; i < n; i++) {
		printf("%s:", p[i].key);
		printf("%s\n", p[i].value);
	}
}
int main()
{
	int lines = cal();
	//printf("%d\n", lines);
	con* p = malloc(sizeof(con) * lines);
	copy_file(p,lines);
	my_print(p,lines);
	free(p);
	p = NULL;
	return 0;
}