#define _CRT_SECURE_NO_WARNINGS  1
#pragma warning(disable:6031)
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//一:死或生
//int main()
//{
//	int n;
//	int x[2] = { 0 };
//	int y[2] ={0};
//	int a[3] = { 0 };
//	scanf("%d", &n);
//	for (int j = 0; j < n; j++) {
//		for (int i = 0; i < 3; i++) {
//			scanf("%d", &a[i]);
//				x[a[0]-1] += a[i];
//				y[a[0]-1] += a[i];
//		}
//	}
//	if (x[0] >= y[0]) {
//		printf("LIVE\n");
//	}
//	else
//		printf("DEAD\n");
//	if (x[1] >= y[1]) {
//		printf("LIVE\n");
//	}
//	else
//		printf("DEAD\n");
//	return 0;
//}
//二:最大价值:
//int main()
//{
//	int k;
//	int sum = 0;
//	int w[26] = { 0 };
//	char s[1005] = { 0 };
//	scanf("%s", s);
//	scanf("%d", &k);
//	int p = 0;
//	for (int i = 0; i < 26; i++) {
//		scanf("%d",&w[i]);
//		if (w[i] > w[p]) {
//			p = i;
//		}
//	}
//	int len=strlen(s);
//	for (int i = 0; i < len; i++) {
//		sum += w[s[i] - 'a']*(i+1);
//	}
//	int t = 0;
//	for (int i = 0; i < k; i++) {
//		t += len + i+1;
//	}
//	printf("%d\n", sum += t * w[p]);
//	return 0;
//}
//三:危险程度:????