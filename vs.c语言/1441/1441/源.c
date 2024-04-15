#define _CRT_SECURE_NO_WARNINGS  1
#pragma warning(disable:6031)
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//int a[1000] = { 1 };
//int main()
//{
//	for (int i = 2; i < 1000; i++) {
//		if (a[i] == 1) {
//			for (int j = 1; j * i < 1000; j++) {
//				a[j * i] = 0;
//			}
//		}
//	}
//	int T,n;
//	scanf("%d", &T);
//	while (T--) {
//		scanf("%d", &n);
//		int count = 0;
//		for (int i = 2;count<=n; i++) {
//			if (a[i] == 1) {
//				if (count % 2 == 0) {
//					for (int j = 0; j < i; j++) {
//						printf("_");
//					}
//				}
//				else {
//					for (int j = 0; j < i; j++) {
//						printf("|\n");
//					}
//				}
//				count++;
//			}
//		}
//
//	}
//	return 0;
//}
int main()
{
	char str[10];
	scanf("%s", str);
	str[9] = '0';
	int len = strlen(str);
	char a[10];
	strcpy(a, str);
	printf("%s\n", a);
	printf("%d\n", len);
	char* t=strstr(str, "abc");
	
	return 0;
}
