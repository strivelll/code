
#define _CRT_SECURE_NO_WARNINGS  1
#pragma warning(disable:6031)
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main() {
	int n;
	scanf("%d", &n);
	int arr[101];
	int count = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	for (int i = 0; i < n-1; i++) {
		if (arr[0] == 3) {
			int count1 = 0;
			for (int j = 0; j < n; j++) {
				if (arr[j] == 0)count1++;
				if (arr[j] != 3 && arr[j] != 0) {
					if ((j-count1 + 1) % 2 == 0) {
						arr[0] =3- arr[j];
						break;
					}
					else {
						arr[0] =arr[j];
						break;
					}
				}
			}
		}
		if (arr[i] == 3&&i>=1) {
			if (arr[i - 1] == 0) {
				int count1 = 0;
				for (int j = i; j < n; j++) {
					if (arr[j] == 0)count1++;
					if (arr[j] != 3&&arr[j]!=0) {
						if ((j - i-count1 + 1) % 2 == 0) {
							arr[i] = 3-arr[j];
							break;
						}
						else {
							arr[i] =arr[j];
							break;
						}
					}
				}
			}
			else
			arr[i] = 3 - arr[i - 1];
		}
		if (arr[i + 1] == arr[i]&&arr[i]!=0) {
			arr[i + 1] = 0;
		}
	}
	for (int i = 0; i < n; i++) {
		if (arr[i] == 0) {
			count++;
		}
	}
	printf("%d\n", count);
	return 0;
}
//int main() {
//	int n, m;
//	scanf("%d %d", &n, &m);
//	char a[20],b[20];
//	for (int i = 0; i < n; i++)
//	{
//		scanf(" %c", &a[i]);
//	}
//	for (int i = 0; i < m; i++)
//	{
//		scanf(" %c", &b[i]);
//	}
//	if (a[0]=='<'&&a[n-1]=='>'&&b[0]=='v'&&b[m-1]=='^'||
//		a[0] == '>' && a[n - 1] == '<' && b[0] == '^' && b[m - 1] == 'v') {
//		printf("YES\n");
//	}
//	else
//		printf("NO\n");
//	return 0;
//}
//int main()
//{
//	int x,y;
//	scanf("%d", &x);
//	for (int i = x+1;; i++) {
//		char buf[5] = { 0 };
//		sprintf(buf, "%d", i);
//		int len = strlen(buf);
//		int f = 0;
//		for (int j = 0; j < len; j++) {
//			for (int k = j + 1; k < len; k++) {
//				if (buf[j] == buf[k]) {
//					f = 1;
//					break;
//				}
//			}
//			if (f)
//				break;
//		}
//		if (f == 0) {
//			printf("%d\n", i);
//			break;
//		}
//	}
//	return 0;
//}