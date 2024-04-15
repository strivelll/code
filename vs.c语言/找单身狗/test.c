#define _CRT_SECURE_NO_WARNINGS  1
#pragma warning(disable:6031)
#include<stdio.h>
//Ò»£º1 2 3 4 5 1 2 3 4
//int main()
//{
//	int a[9] = { 1,2,3,4,5,1,2,3,4 };
//	int aw = 0;
//	for (int i = 0; i < 9; i++) {
//		aw ^= a[i];
//	}
//	printf("%d\n", aw);
//	return 0;
//}
//¶þ£º1 2 3 4 5 1 2 3 4 6
//int main()
//{
//	int a[] = { 1,2,3,4,5,1,2,3,4,6 };
//	int b[10] = { 0 };
//	int c[10] = { 0 };
//	int aw = 0;
//	for (int i = 0; i < 10; i++) {
//		aw ^= a[i];
//	}
//	for (int i = 0; i < 32; i++) {
//		if (aw >> i & 1) {
//			for (int j = 0; j < 10; j++) {
//				if (a[j] >> i & 1) {
//					b[j] = a[j];
//				}
//				else
//					c[j] = a[j];
//			}
//			break;
//		}
//	}
//	aw = 0;
//	for (int i = 0; i < 10; i++) {
//		aw ^= b[i];
//	}
//	printf("%d ", aw);
//	aw = 0;
//	for (int i = 0; i < 10; i++) {
//		aw ^= c[i];
//	}
//	printf("%d ", aw);
//	return 0;
//}
//º¯Êý£º
void chectdsg(int a[], int* n, int* m) {
	int aw = 0;
	int pos=0;
	for (int i = 0; i < 10; i++) {
		aw ^= a[i];
	}
	for (int i = 0; i < 32; i++) {
		if (aw >> i & 1) {
			pos = i;
			break;
		}
	}
	*n = 0; *m = 0;
	for (int i = 0; i < 10; i++) {
		if (a[i] >> pos & 1) {
			*n ^= a[i];
		}
		else
			*m ^= a[i];
	}
}
int main()
{
	int a[] = { 1,2,3,4,5,1,2,3,4,6 };
	int n, m;
	chectdsg(a, &n, &m);
	printf("%d %d", n, m);
	return 0;
}