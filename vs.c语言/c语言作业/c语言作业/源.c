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
//	printf("请输入需要输入多少字符串:>\n");
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
//	printf("排序后:>\n");
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
//	printf("空格数：%d\t数字数：%d\t 大写字母数：%d\t 小写字母数：%d\n", countempty, countnum, countEnglish, countenglish);
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
	printf("请输入需要记录多少学生信息:>\n");
	scanf("%d", &n);
	printf("请输入学生信息:\n");
	for (int i = 0; i < n; i++) {
		printf("请输入学生学号:>\n");
		scanf("%lld", &c1[i].num);
		printf("请输入学生姓名:>\n");
		scanf("%s", &c1[i].name);
		printf("请输入学生性别:>\n");
		scanf("%s", &c1[i].sex);
		printf("请输入学生生日:>\n");
		scanf("%d", &c1[i].bir);
		printf("请输入学生班级:>\n");
		scanf("%d", &c1[i].classnum);
		printf("请输入学生语文成绩:>\n");
		scanf("%d", &c1[i].ywsore);
		printf("请输入学生数学成绩:>\n");
		scanf("%d", &c1[i].mathsore);
		printf("请输入学生英语成绩:>\n");
		scanf("%d", &c1[i].englishsore);
		printf("记录成功\n");
		if (i != n - 1) {
			printf("请输入下一个学生信息;>\n");
		}
	}
	return n;
}
void look(struct class c1[],int n) {
	if (n == 0) {
		printf("记录为空\n");
		return;
	}
	printf("一共有%d名学生\n", n);
	for (int i = 0; i < n; i++) {
		printf("第%d个学生\n",i+1);
		printf("学生学号:>");
		printf("%lld\n", c1[i].num);
		printf("学生姓名:>");
		printf("%s\n", c1[i].name);
		printf("学生性别:>");
		printf("%s\n", c1[i].sex);
		printf("学生生日:>");
		printf("%d\n", c1[i].bir);
		printf("学生班级:>");
		printf("%d\n", c1[i].classnum);
		printf("学生语文成绩:>");
		printf("%d\n", c1[i].ywsore);
		printf("学生数学成绩:>");
		printf("%d\n", c1[i].mathsore);
		printf("学生英语成绩:>");
		printf("%d\n", c1[i].englishsore);
	}
}
void menu() {
	printf("**************************************************\n");
	printf("**************************************************\n");
	printf("******0.退出程序                  1.记录信息******\n");
	printf("******2.查看记录的信息            3.通过名字查询**\n");
	printf("******            4.按数学成绩排序          ******\n");
	printf("**************************************************\n");
}
void find(struct class c1[], int n) {
	if (n == 0) {
		printf("记录为空\n");
		return;
	}
	char nm[64] = "";
	printf("请输入要查询的名字\n");
	scanf("%s", &nm);
	for (int i = 0; i < n; i++) {
		if (strcmp(c1[i].name, nm) == 0) {
			printf("该学生学号:>");
			printf("%lld\n", c1[i].num);
			printf("该学生姓名:>");
			printf("%s\n", c1[i].name);
			printf("该学生性别:>");
			printf("%s\n", c1[i].sex);
			printf("该学生生日:>");
			printf("%d\n", c1[i].bir);
			printf("该学生班级:>");
			printf("%d\n", c1[i].classnum);
			printf("该学生语文成绩:>");
			printf("%d\n", c1[i].ywsore);
			printf("该学生数学成绩:>");
			printf("%d\n", c1[i].mathsore);
			printf("该学生英语成绩:>");
			printf("%d\n", c1[i].englishsore);
			return;
		}
	}
	printf("该学生不存在\n");
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
	printf("排序后：\n");
	look(c1, n);
	return;
}
int main() {
	struct class c1[100];
	int n = 0;
	while (1) {
		menu();
		printf("请选择功能:>\n");
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
