#define _CRT_SECURE_NO_WARNINGS  1
#pragma warning(disable:6031)
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//4.5
//int main()
//{
//	int n,count=0;
//	scanf("%d", &n);
//	while (n) {
//		n /= 2;
//		count++;
//	}
//	printf("%d\n", count);
//	return 0;
//}
//5.12
//int main() {
//	float a, b;
//	scanf("%f %f", &a, &b);
//	float n = (a + b) / 2;
//	if (a == b) {
//		printf("None\n");
//	}
//	if (a > n) {
//		printf("Bob %g", a - n);
//		return 0;
//	}
//	if (b > n) {
//		printf("Alice %g", b - n);
//		return 0;
//	}
//	return 0;
//}
//6.3
//int main() {
//	int a = 4;
//	int b = 1;
//	for (int i = 0; i < 4; i++) {
//		for (int j = 0; j < a; j++) {
//			printf(" ");
//		}
//		a--;
//		for (int j = 0; j < b; j++) {
//			printf("*");
//		}
//		b += 2;
//		printf("\n");
//	}
//	for (int i = 0; i < 5; i++) {
//		for (int j = 0; j < a; j++) {
//			printf(" ");
//		}
//		a++;
//		for (int j = 0; j < b; j++) {
//			printf("*");
//		}
//		b -= 2;
//		printf("\n");
//	}
//	return 0;
//}
//6.3(2)
//int main() {
//	int a = 4;
//	int b = 1;
//	char c = 'A';
//	for (int i = 0; i < 4; i++) {
//		for (int j = 0; j < a; j++) {
//			printf(" ");
//		}
//		a--;
//		for (int j = 0; j < b; j++) {
//			printf("%c",c);
//		}
//		c++;
//		b += 2;
//		printf("\n");
//	}
//	for (int i = 0; i < 5; i++) {
//		for (int j = 0; j < a; j++) {
//			printf(" ");
//		}
//		a++;
//		for (int j = 0; j < b; j++) {
//			printf("%c", c);
//		}
//		c++;
//		b -= 2;
//		printf("\n");
//	}
//	return 0;
//}
//7.5
//int main() {
//	int a[8][8] = {0};
//	int n = 8;
//	for (int i = 0; i < n; i++) {
//		a[i][0] = 1;
//		a[i][i] = 1;
//	}
//	for (int i = 2; i < n; i++) {
//		for (int j = 1; j < i; j++) {
//			a[i][j] = a[i - 1][j] + a[i - 1][j - 1];
//		}
//	}
//	int b = 7;
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < b; j++) {
//			printf(" ");
//		}
//		b--;
//		for (int j = 0; j <= i; j++) {
//			printf("%d ", a[i][j]);
//		}
//		printf("\n");
//	}
//	return 0;
//}
//8.4
//int main() {
//	int n = 3,b=1;
//	int a[3][3] = { 0 };
//	int i = 2, j = 1;
//	while (b <= n*n) {
//		if (i > 2 && j > 2) {
//			j --;
//			i -= 2;
//		}
//		else if (i > 2) {
//			i = 0;
//		}
//		else if (j > 2) {
//			j = 0;
//		}
//		if (a[i][j] != 0) {
//			i-=2;
//			j--;
//		}
//		a[i++][j++] = b++;
//	}
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < n; j++) {
//			printf("%d ", a[i][j]);
//		}
//		printf("\n");
//	}
//	return 0;
//}
//9.12
//char a[100][100];
//char b[100][100];
//int main() {
//	int n;
//	printf("��������Ҫ��������ַ���:>\n");
//	scanf("%d", &n);
//	for (int i = 0; i < n; i++) {
//		scanf("%s", a[i]);
//	}
//	int x = n;
//	for (int j = 0; j < n; j++) {
//		for (int i = 0; i < x; i++) {
//			char minstr[100];
//			if (strcmp(a[i], a[i + 1]) == 1) {
//				strcpy(minstr, a[i]);
//				strcpy(a[i], a[i + 1]);
//				strcpy(a[i + 1], minstr);
//			}
//		}
//		x--;
//	}
//	printf("�����:>\n");
//	for (int i = 0; i < n; i++) {
//		printf("%s\n", a[i]);
//	}
//	return 0;
//}
//10.2
//int main()
//{
//	char out = EOF;
//	int countnum = 0, countenglish = 0, countEnglish = 0, countempty = 0;
//	FILE* fp = fopen("file.txt", "r");
//	while (1) {
//		if (feof(fp)) {
//			break;
//		}
//		fscanf(fp, "%c", &out);
//		if (out == '\0') {
//			break;
//		}
//		else if (out == ' ') {
//			countempty++;
//		}
//		else if (out <= '9' && out >= '0') {
//			countnum++;
//		}
//		else if (out <= 'Z' && out >= 'A') {
//			countEnglish++;
//		}
//		else if (out <= 'z' && out >= 'a') {
//			countenglish++;
//		}
//	}
//	printf("�ո�����%d\t��������%d\t ��д��ĸ����%d\t Сд��ĸ����%d\n", countempty, countnum, countEnglish, countenglish);
//	return 0;
//}
//11.4
struct class {
	long long num;
	char name[64];
	char sex[10];
	int bir;
	int classnum;
	int ywsore;
	int mathsore;
	int englishsore;
	int size;
};
int input(struct class c1[]) {
	int n;
	printf("��������Ҫ��¼����ѧ����Ϣ:>\n");
	scanf("%d", &n);
	printf("������ѧ����Ϣ:\n");
	for (int i = 0; i < n; i++) {
		printf("������ѧ��ѧ��:>\n");
		scanf("%lld", &c1[i].num);
		printf("������ѧ������:>\n");
		scanf("%s", &c1[i].name);
		printf("������ѧ���Ա�:>\n");
		scanf("%s", &c1[i].sex);
		printf("������ѧ������:>\n");
		scanf("%d", &c1[i].bir);
		printf("������ѧ���༶:>\n");
		scanf("%d", &c1[i].classnum);
		printf("������ѧ�����ĳɼ�:>\n");
		scanf("%d", &c1[i].ywsore);
		printf("������ѧ����ѧ�ɼ�:>\n");
		scanf("%d", &c1[i].mathsore);
		printf("������ѧ��Ӣ��ɼ�:>\n");
		scanf("%d", &c1[i].englishsore);
		printf("��¼�ɹ�\n");
		if (i != n - 1) {
			printf("��������һ��ѧ����Ϣ;>\n");
		}
	}
	return n;
}
void look(struct class c1[],int n) {
	if (n == 0) {
		printf("��¼Ϊ��\n");
		return;
	}
	printf("һ����%d��ѧ��\n", n);
	for (int i = 0; i < n; i++) {
		printf("��%d��ѧ��\n",i+1);
		printf("ѧ��ѧ��:>");
		printf("%lld\n", c1[i].num);
		printf("ѧ������:>");
		printf("%s\n", c1[i].name);
		printf("ѧ���Ա�:>");
		printf("%s\n", c1[i].sex);
		printf("ѧ������:>");
		printf("%d\n", c1[i].bir);
		printf("ѧ���༶:>");
		printf("%d\n", c1[i].classnum);
		printf("ѧ�����ĳɼ�:>");
		printf("%d\n", c1[i].ywsore);
		printf("ѧ����ѧ�ɼ�:>");
		printf("%d\n", c1[i].mathsore);
		printf("ѧ��Ӣ��ɼ�:>");
		printf("%d\n", c1[i].englishsore);
	}
}
void menu() {
	printf("**************************************************\n");
	printf("**************************************************\n");
	printf("******0.�˳�����                  1.��¼��Ϣ******\n");
	printf("******2.�鿴��¼����Ϣ            3.ͨ�����ֲ�ѯ**\n");
	printf("******            4.����ѧ�ɼ�����          ******\n");
	printf("**************************************************\n");
}
void find(struct class c1[], int n) {
	if (n == 0) {
		printf("��¼Ϊ��\n");
		return;
	}
	char nm[64] = "";
	printf("������Ҫ��ѯ������\n");
	scanf("%s", &nm);
	for (int i = 0; i < n; i++) {
		if (strcmp(c1[i].name, nm) == 0) {
			printf("��ѧ��ѧ��:>");
			printf("%lld\n", c1[i].num);
			printf("��ѧ������:>");
			printf("%s\n", c1[i].name);
			printf("��ѧ���Ա�:>");
			printf("%s\n", c1[i].sex);
			printf("��ѧ������:>");
			printf("%d\n", c1[i].bir);
			printf("��ѧ���༶:>");
			printf("%d\n", c1[i].classnum);
			printf("��ѧ�����ĳɼ�:>");
			printf("%d\n", c1[i].ywsore);
			printf("��ѧ����ѧ�ɼ�:>");
			printf("%d\n", c1[i].mathsore);
			printf("��ѧ��Ӣ��ɼ�:>");
			printf("%d\n", c1[i].englishsore);
			return;
		}
	}
	printf("��ѧ��������\n");
	return;
}
void mysort(struct class c1[], int n) {
	for (int i = 0; i < n; i++) {
		int Max = i;
		for (int j = i+1; j < n; j++) {
			if (c1[Max].mathsore < c1[j].mathsore) {
				Max = j;
			}
		}
		if (i != Max) {
			struct class t = c1[Max];
			c1[Max] = c1[i];
			c1[i] = t;
		}
	}
	printf("�����\n");
	look(c1, n);
	return;
}
int main() {
	struct class c1[100];
	int n = 0;
	while (1) {
		menu();
		printf("��ѡ����:>\n");
		int x;
		scanf("%d", &x);
		
		switch (x) {
		case 0: {
			return 0;
		}
		case 1: {
			n += input(c1);
			break;
		}
		case 2: {
			look(c1, n);
			break;
		}
		case 3: {
			find(c1,n);
			break;
		}
		case 4: {
			mysort(c1, n);
			break;
		}
		default: {
			break;
		}
		}
	}
	return 0;
}
