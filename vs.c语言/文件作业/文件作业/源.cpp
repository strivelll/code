#define _CRT_SECURE_NO_WARNINGS  1
#pragma warning(disable:6031)
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
	char out=EOF;
	int countnum = 0,countenglish=0,countEnglish=0,countempty=0;
	FILE* fp = fopen("test.txt", "r");
	while (1) {
		if (feof(fp)) {
			break;
		}
		fscanf(fp, "%c", &out);
		if (out == '\0') {
			break;
		}
		else if (out == ' ') {
			countempty++;
		}
		else if (out <= '9' && out >= '0') {
			countnum++;
		}
		else if (out <= 'Z' && out >= 'A') {
			countEnglish++;
		}
		else if (out <= 'z' && out >= 'a') {
			countenglish++;
		}
	}
	printf("�ո�����%d\t��������%d\t ��д��ĸ����%d\t Сд��ĸ����%d\n", countempty, countnum, countEnglish, countenglish);
	return 0;
}