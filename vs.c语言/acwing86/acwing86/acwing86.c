#define _CRT_SECURE_NO_WARNINGS  1
#pragma warning(disable:6031)
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main() {
	return 0;
}
//安全区
//int count1[100001] = { 0 }, count2[100001] = { 0 };
//
//long long t[100001] = { 0 };
//int main() {
//	int n, m,a,b;
//	scanf("%d %d", &n, &m);
//    long long t1 = n, t2 = n;
//	for (int i = 1; i <= m; i++) {
//		scanf("%d %d", &a, &b);
//        if (count1[a] == 0)
//        {
//            count1[a]++;
//            t1--;
//        }
//        if (count2[b] == 0)
//        {
//            count2[b]++;
//            t2--;
//        }
//        printf("%lld ", t1*t2);
//	}
//
//	return 0;
//}
//健身:
//int main()
//{
//	int n;
//	int a[3] = {0};
//	int arr[20] = { 0 };
//	scanf("%d", &n);
//	for (int i = 0; i < n; i++) {
//		scanf("%d", &arr[i]);
//	}
//	for (int i = 0; i < n; i++) {
//		a[i % 3]+=arr[i];
//	}
//	int t = 0;
//	for (int i = 0; i < 3; i++) {
//		if (a[i] > a[t]) {
//			t = i;
//		}
//	}
//	if (t == 0)
//		printf("chest\n");
//	else if (t == 1)
//		printf("biceps\n");
//	else
//		printf("back\n");
//	return 0;
//}