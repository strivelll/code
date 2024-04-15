//练习一：qsort模拟实现：
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//struct stu {
//	char name[20];
//	int age[10];
//}; 
//int cmp_int(const void* e1, const void* e2)
//{
//	return *(int*)e1-*(int*)e2;
//}
//int cmp_float(const void* e1, const void* e2)
//{
//	return (int)(*(float*)e1 - *(float*)e2);
//}
//int cmp_strust_by_name(const void* e1, const void* e2)
//{
//	return strcmp(((struct stu*)e1)->name, ((struct stu*)e2)->name);
//}
//int cmp_strust_by_age(const void* e1, const void* e2)
//{
//	return *((struct stu*)e1)->age - *((struct stu*)e2)->age;
//	
//}
//void swap(char* e1, char* e2, int width) {
//	for (int i = 0; i < width; i++) {
//		char t = *e1;
//		*e1 = *e2;
//		*e2 = t;
//		e1++;
//		e2++;
//	}
//}
//void my_qsort(void* base, int sz, int width, int (*cmp)(const void* e1, const void* e2))
//{
//	for (int i = 0; i < sz - 1; i++) {
//		for (int j = 0; j < sz - 1 - i; j++) {
//			if (cmp((char*)base + j * width, (char*)base + (j + 1) * width) > 0) {
//				swap((char*)base + j * width, (char*)base + (j + 1) * width, width);
//			}
//		}
//	}
//}
//void texs1()
//{
//	int a[10] = { 9,8,7,6,5,4,3,2,1,0 };
//	int sz = sizeof(a) / sizeof(a[0]);
//	//qsort(a, sz, sizeof(a[0]), cmp_int);
//	my_qsort(a, sz, sizeof(a[0]), cmp_int);
//	for (int i = 0; i < sz; i++)
//		printf("%d ", a[i]);
//}
//void texs2()
//{
//	float b[10] = { 9.8,9.9,7.0,6.0,5.0,4.0,3.0,2.0,1.0,0.0 };
//	int sz = sizeof(b) / sizeof(b[0]);
//	//qsort(b, sz, sizeof(b[0]), cmp_float);
//	my_qsort(b, sz, sizeof(b[0]), cmp_float);
//	for (int i = 0; i < sz; i++)
//		printf("%.1f ", b[i]);
//}
//void texs3()
//{
//	struct stu s[3] = { {"zhangsan",20},{"lisi",30},{"wangwu",26}};
//	int sz = sizeof(s) / sizeof(s[0]);
//	qsort(s, sz, sizeof(s[0]), cmp_strust_by_age);
//}
//void texs4()
//{
//	struct stu s[3] = { {"zhangsan",20},{"lisi",30},{"wangwu",26} };
//	int sz = sizeof(s) / sizeof(s[0]);
//	/*qsort(s, sz, sizeof(s[0]), cmp_strust_by_name);*/
//	my_qsort(s, sz, sizeof(s[0]), cmp_strust_by_name);
//}
//
//void texs5()
//{
//	struct stu s[3] = { {"zhangsan",20},{"lisi",30},{"wangwu",26} };
//	int sz = sizeof(s) / sizeof(s[0]);
//	//qsort(s, sz, sizeof(s[0]), cmp_strust_by_name);
//	my_qsort(s, sz, sizeof(s[0]), cmp_strust_by_age);
//}
//int main()
//{
//	//texs1();
//	//texs2();
//	//texs3();
//	//texs4();
//	texs5();
//	return 0;
//}
//指针进阶练习一：
//1.写一个函数，判断一个字符串是否为另外一个字符串旋转之后的字符串。
//#include<stdio.h>
//#include<string.h>
//int pd(char a[100], char b[100]) {
//	char temp[100];
//	strcpy_s(temp, a);
//	strcat_s(temp, a);
//	return strstr(temp, b)!=NULL;
//}
//int main()
//{
//	char a[100]="abcde";
//	char b[100]="BCDAA";
//	int c=pd(a, b);
//	printf("%d\n", c);
//	return 0;
//}
//2.实现一个函数，可以左旋字符串中的k个字符
//#include<stdio.h>
//void leftround(char a[10], int k,int len)
//{
//	k %= len;
//	while(k--) {
//		char temp = a[0];
//		for (int j = 0; j < len-1; j++) {
//			a[j] = a[j + 1];
//		}
//		a[len - 1] = temp;
//	}
//}
//int main()
//{
//	char a[] = "ABCDE";
//	int k;
//	int len = sizeof(a) / sizeof(a[0]);
//	scanf("%d", &k);
//	leftround(a,k,len-1);
//	/*for (int i = 0; i < len; i++) {
//		printf("%c",a[i]);
//	}*/
//	printf("%s", a);
//	return 0;
//}
//改进一：拼接法
//#include<stdio.h>
//#include<string.h>
//void leftround(char* a,int k) {
//	char temp[256];
//	strcpy(temp, a + k);
//	strncat(temp, a, k);
//	strcpy(a, temp);
//}
//int main()
//{
//	char a[] = "ABCDE";
//	int k;
//	scanf("%d", &k);
//	k %= 5;
//	leftround(a, k);
//	printf("%s\n", a);
//	return 0;
//}
//改进二：先将要左旋的前三个家伙逆序（CBADEFG），然后将后半段也逆序（CBAGFED），最后整体逆序（DEFGABC）即可。
//这样只需要做数值交换即可，可以写一个函数帮我们完成局部逆序
#include<stdio.h>
#include<string.h>
void nx(char* a,int start,int end) {
	char temp;
	int i, j;
	for (j = end, i =start; i < j; i++, j--) {
		temp = a[i];
		a[i] = a[j];
		a[j] = temp;
	}
}
int main()
{
	char a[] = "ABCDE";
	int k;
	int len = sizeof(a) / sizeof(a[0])-1;
	scanf("%d", &k);
	k %= len;
	nx(a, 0, k-1);
	nx(a, k, len-1);
	nx(a, 0, len-1);
	printf("%s\n", a);
	return 0;
}