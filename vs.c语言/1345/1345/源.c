#define _CRT_SECURE_NO_WARNINGS  1
#pragma warning(disable:6031)
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int n[5000001];
char a[1000001][10] = {0};
int main()
{
	for (int i = 2; i < 1000001; i++) {
		n[i] = 1;
	}
	for (int i = 2; i < 1000001; i++) {
		if (n[i]) {
			for (int j = 2; j * i < 1000001; j++) {
				n[i * j] = 0;
			}
		}
	}
	int count = 1;
	for (int i = 2;i<1000001; i++) {
		if (n[i]&&count<1000001) {
			char str[1000] = {0};
			sprintf(str, "%d", i);
			int len = strlen(str);
			for (int j = 0; j < len; j++) {
				for (int k = 0; k < 10; k++) {
					if (str[j] - '0' == k)
					{
						a[count][k] = a[count - 1][k] + 1;
						break;
					}
					else
						a[count][k] = a[count - 1][k];
				}
					if (count < 1000000)
						count++;
					else
						break;
			}
		}
	}
	int T;
	scanf("%d", &T);
	while (T--) {
		int l, r,d;
		scanf("%d %d %d", &l, &r, &d);
		printf("%d\n",a[r][d]-a[l-1][d]);
	}
	return 0;
}
//Ëã·¨²»ÐÐ;
//int n[1000001];
//char a[1000001] = {0};
//char b[1000001] =" ";
//int main()
//{
//	int p = 0;
//	for (int i = 2; i < 1000001; i++) {
//		n[i] = 1;
//	}
//	for (int i = 2; i < 500001; i++) {
//		if (n[i]) {
//			for (int j = 2; j * i < 1000001; j++) {
//				n[i * j] = 0;
//			}
//			a[p] = i;
//			p++;
//		}
//	}
//	char str[10];
//	for (int i = 0; i < p; i++) {
//		sprintf(str, "%d", a[i]);
//		strcat(b, str);
//	}
//	int T;
//	scanf("%d", &T);
//	while (T--) {
//		int l, r,d,lcount=0,rcount=0;
//		scanf("%d %d %d", &l, &r, &d);
//		for (int i = 1; i <= l; i++) {
//			if (b[i] == d+'0') {
//				lcount++;
//			}
//		}
//		for (int i = 1; i <= r; i++) {
//			if (b[i] == d + '0') {
//				rcount++;
//			}
//		}
//		printf("%d\n", rcount-lcount);
//	}
//	return 0;
//}