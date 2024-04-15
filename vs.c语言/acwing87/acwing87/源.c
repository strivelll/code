#define _CRT_SECURE_NO_WARNINGS  1
#pragma warning(disable:6031)
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int Max(int x,int y){
	return x > y ? x : y;
}
int main() 
{
	int n, m;
	int arr[1005];
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	for (int i = 0; i < n; i++) {
		if (m > arr[i]) {
			if (arr[i + 2] > m - Max(arr[i], arr[i + 1])) {

			}
		}
	}
	return 0;
}
//int main()
//{
//	int arr[5][5] = {0};
//	int ti, tj;
//	for (int i = 0; i < 5; i++) {
//		for (int j = 0; j < 5; j++) {
//			scanf("%d", &arr[i][j]);
//			if (arr[i][j] == 1) {
//				ti = i;
//				tj = j;
//			}
//		}
//	}
//	printf("%d\n", abs(2 - ti) + abs(2 - tj));
//	return 0;
//}