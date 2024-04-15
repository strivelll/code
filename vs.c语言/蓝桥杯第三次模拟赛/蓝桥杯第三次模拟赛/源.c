#define _CRT_SECURE_NO_WARNINGS  1
#pragma warning(disable:6031)
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//第一题进制转换2730
//int main()
//{
//	int n=2022;
//	int t = n;
//	int arr[10] = { 0 };
//	int i = 0;
//	while (t) {
//		arr[i] = t % 16;
//		t /= 16;
//		i++;
//	}
//	for (int i = 0; i < 10; i++) {
//		printf("%d ", arr[i]);
//	}
//	int ss = 0;
//	ss = 10 + 10 * 16 + 10 * 256;
//	printf("%d", ss);
//	return 0;
//}
//第二题ZT
//int main() {
//	int count = 0;
//	for (int i = 0; i < 26; i++) {
//		for (int j = 0; j < 26; j++) {
//			count++;
//			if (count == 26) {
//				printf("%C %C\n", i+'A', j+'A');
//				printf("%d %d", i, j);
//				break;
//			}
//		}
//	}
//	printf("\n%C", 'A' + 19);
//	return 0;
//}
// 第三题3302
//int main() {
//	int count = 0;
//	for (int i = 0; i < 9999; i++) {
//		for (int j = 0; j < 12; j++) {
//			if (i % 4 == 0 && i % 100 != 0||i%400==0) {
//				if (j == 1 || j == 3 || j == 5 || j == 7 || j == 8 || j == 10 || j == 12) {
//					for (int k = 0; k < 31; k++) {
//						if (i / 1000 + i / 100 + i / 10 + 1 % 10 == j / 10 + j % 10 + k / 10 + k % 10) {
//							count++;
//						}
//					}
//				}
//				else if (j == 2) {
//					for (int k = 0; k < 29; k++) {
//						if (i / 1000 + i / 100 + i / 10 + 1 % 10 == j / 10 + j % 10 + k / 10 + k % 10) {
//							count++;
//						}
//					}
//				}
//				else {
//					for (int k = 0; k < 30; k++) {
//						if (i / 1000 + i / 100 + i / 10 + 1 % 10 == j / 10 + j % 10 + k / 10 + k % 10) {
//							count++;
//						}
//					}
//				}
//			}
//			else
//			{
//				if (j == 1 || j == 3 || j == 5 || j == 7 || j == 8 || j == 10 || j == 12) {
//					for (int k = 0; k < 31; k++) {
//						if (i / 1000 + i / 100 + i / 10 + 1 % 10 == j / 10 + j % 10 + k / 10 + k % 10) {
//							count++;
//						}
//					}
//				}
//				else if (j == 2) {
//					for (int k = 0; k < 28; k++) {
//						if (i / 1000 + i / 100 + i / 10 + 1 % 10 == j / 10 + j % 10 + k / 10 + k % 10) {
//							count++;
//						}
//					}
//				}
//				else {
//					for (int k = 0; k < 30; k++) {
//						if (i / 1000 + i / 100 + i / 10 + 1 % 10 == j / 10 + j % 10 + k / 10 + k % 10) {
//							count++;
//						}
//					}
//				}
//			}
//		}
//	}
//	printf("%d", count);
//	return 0;
//}
// 第四题193
//int main() {
//	int arr[30];
//	for (int i = 0; i < 30; i++) {
//		scanf("%d", &arr[i]);
//	}
//	for (int i = 0; i < 30; i++) {
//		int max = 0;
//		for (int j = i; j < 30; j++) {
//			if (arr[max] < arr[j]) {
//				max = j;
//			}
//		}
//		if (max != i) {
//			int t = arr[max];
//			arr[max] = arr[i];
//			arr[i] = t;
//		}
//	}
//	for (int i = 0; i < 30; i++) {
//		printf("%d ", arr[i]);
//	}
//	int count = 0;
//	int n = 2022;
//	for (int i = 0; i < 30; i++) {
//		for (int j = 0; j < 30; j++) {
//			if (n / arr[i] <= arr[j]) {
//				count++;
//			}
//		}
//	}
//	printf("\n%d ", count);
//	return 0;
//}
//int main() {
//	int arr[30][60] = { 0 };
//	for (int i = 0; i < 30; i++) {
//		for (int j = 0; j < 60; j++) {
//			scanf("%d", &arr[i][j]);
//		}
//	}
//	
//	return 0;
//}
//第6题
//int main() {
//    int w, n;
//    scanf("%d", &w);
//    scanf("%d", &n);
//    int t = n + w;
//    while (t > 7) {
//        t -= 7;
//    }
//    printf("%d", t);
//    return 0;
//}
//第七题
//int arr[100][100] = { 0 };
//int main() {
//	int w, h, n, r;
//	scanf("%d %d %d %d", &w, &h, &n, &r);
//	int x, y,count=0;
//	for (int i = 0; i < n; i++) {
//		scanf("%d %d", &x, &y);
//		arr[x][y] = 1;
//		for (int i = 0; i <= w; i++) {
//			for (int j = 0; j <= h; j++) {
//				if (arr[i][j] == 0||arr[i][j]==2) {
//					if (((x - i) * (x - i) + (y - j) * (y - j)) <= r * r) {
//						arr[i][j] = 2;
//						
//					}
//				}
//			}
//		}
//	}
//	for (int i = 0; i <= w; i++) {
//		for (int j = 0; j <= h; j++) {
//			if (arr[i][j] != 0) {
//				count++;
//			}
//		}
//	}
//	printf("%d", count);
//	return 0;
//}
//第十题
int arr[1000000];
int b[1000000];
int main() {
	int n,k;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d ", &arr[i]);
	}
	scanf("%d", &k);
	for (int i = 0; i <n; i++) {
		int min = 0;
		for (int j = i - k; j <= k + i; j++) {
			if (j >= 0&&j<n) {
				if (arr[min] > arr[j]) {
					min = j;
				}
			}
		}
		b[i] = arr[min];
	}
	for (int i = 0; i < n; i++) {
		printf("%d ", b[i]);
	}
	return 0;
}