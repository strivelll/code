#include<stdio.h>
#include<memory.h>
struct stu {
	char name[20];
	int age[10];
};
//模拟实现memcpy：
//void* my_memcpy(void* det, const void* str, size_t count) {
//	char* s1 = (char*)det;
//	char* s2 = (char*)str;
//	while (count--) {
//		*s1 = *s2;
//		s1++;
//		s2++;
//	}
//	return det;
//}
//int main()
//{
//	int a1[] = { 1,2,3,4,5 };
//	int a2[5] = { 0 };
//	struct stu s1[3] = { {"zhangsan",20},{"lisi",30} };
//	struct stu s2[3] = { 0 };
//	//memcpy(s2, s1, sizeof(s1));
//	//my_memcpy(s2, s1, sizeof(s1));
//	return 0;
//}
//模拟实现memmove
//#include<stdio.h>
//void* my_memmove(void* det, const void* str, size_t count)
//{
//	char* s1 = (char*)det;
//	char* s2 = (char*)str;
//	if (s1 < s2) {
//		while (count--) {
//			*s1 = *s2;
//			s1++;
//			s2++;
//		}
//		return det;
//	}
//	else {
//		while (count--) {
//			*(s1 + count) = *(s2 + count);
//		}
//		return det;
//	}
//}
//int main()
//{
//	int a1[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int a2[10] = { 0 };
//	//memmove(a1 + 2, a1, 20);
//	my_memmove(a1 + 2, a1, 20);
//	for (int i = 0; i < 10; i++)
//		printf("%d ", a1[i]);
//	return 0;
//}
#include<stdio.h>
union un {
	char a;
	char b;
	int c;
};
int main()
{
	union un n1;
	printf("%p\n", &n1);
	printf("%p\n", &n1.a);
	printf("%p\n", &n1.b);
	printf("%p\n", &n1.c);

	return 0;
}