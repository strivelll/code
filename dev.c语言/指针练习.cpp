#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct stu {
	char name[20];
	int age[10];
}; 
int cmp_int(const void* e1, const void* e2)
{
	return *(int*)e1-*(int*)e2;
}
int cmp_float(const void* e1, const void* e2)
{
	return (int)(*(float*)e1 - *(float*)e2);
}
int cmp_strust_by_name(const void* e1, const void* e2)
{
	return strcmp(((struct stu*)e1)->name, ((struct stu*)e2)->name);
}
int cmp_strust_by_age(const void* e1, const void* e2)
{printf("%d\n", *((struct stu*)e1)->age - *((struct stu*)e2)->age);
	return *((struct stu*)e1)->age - *((struct stu*)e2)->age;
	
}
void swap(char* e1, char* e2, int width) {
	for (int i = 0; i < width; i++) {
		char t = *e1;
		*e1 = *e2;
		*e2 = t;
		e1++;
		e2++;
	}
}
void my_qsort(void* base, int sz, int width, int (*cmp)(const void* e1, const void* e2))
{
	for (int i = 0; i < sz - 1; i++) {
		for (int j = 0; j < sz - 1 - i; j++) {
			if (cmp((char*)base + j * width, (char*)base + (j + 1) * width) > 0) {
				swap((char*)base + j * width, (char*)base + (j + 1) * width, width);
			}
		}
	}
}
void texs1()
{
	int a[10] = { 9,8,7,6,5,4,3,2,1,0 };
	int sz = sizeof(a) / sizeof(a[0]);
	//qsort(a, sz, sizeof(a[0]), cmp_int);
	my_qsort(a, sz, sizeof(a[0]), cmp_int);
	for (int i = 0; i < sz; i++)
		printf("%d ", a[i]);
}
void texs2()
{
	float b[10] = { 9.8,9.9,7.0,6.0,5.0,4.0,3.0,2.0,1.0,0.0 };
	int sz = sizeof(b) / sizeof(b[0]);
	//qsort(b, sz, sizeof(b[0]), cmp_float);
	my_qsort(b, sz, sizeof(b[0]), cmp_float);
	for (int i = 0; i < sz; i++)
		printf("%.1f ", b[i]);
}
void texs3()
{
	struct stu s[3] = { {"zhangsan",20},{"lisi",30},{"wangwu",26}};
	int sz = sizeof(s) / sizeof(s[0]);
	qsort(s, sz, sizeof(s[0]), cmp_strust_by_age);
}
void texs4()
{
	struct stu s[3] = { {"zhangsan",20},{"lisi",30},{"wangwu",26} };
	int sz = sizeof(s) / sizeof(s[0]);
	/*qsort(s, sz, sizeof(s[0]), cmp_strust_by_name);*/
	my_qsort(s, sz, sizeof(s[0]), cmp_strust_by_name);
}

void texs5()
{
	struct stu s[3] = { {"zhangsan",20},{"lisi",30},{"wangwu",26} };
	int sz = sizeof(s) / sizeof(s[0]);
	//qsort(s, sz, sizeof(s[0]), cmp_strust_by_name);
	my_qsort(s, sz, sizeof(s[0]), cmp_strust_by_age);
}
int main()
{
	//texs1();
	//texs2();
	//texs3();
	//texs4();
	texs5();
	return 0;
}
