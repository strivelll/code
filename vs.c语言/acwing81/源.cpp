//#include<stdio.h>
//int main()
//{
//	int n = 0;
//	scanf_s("%d", &n);
//	int a[1001]={0},b[1001]={0},c[1001]={0};
//	for (int i = 0; i < n; i++)
//	{
//		scanf_s("%d %d %d", &a[i],&b[i],&c[i]);
//	}
//	int count = 0;
//	for (int i = 0; i < n; i++) {
//		if (a[i] + b[i] + c[i] >= 2)
//			count++;
//	}
//	printf("%d\n", count);
//	return 0;
//}
//#include<stdio.h>
//int main()
//{
//	int n = 0, k = 0;
//	int count = 0;
//	int a[1001] = { 0 };
//	int b[1001] = { 0 };
//	scanf_s("%d %d", &n, &k);
//	for (int i = 0; i < n; i++) {
//		scanf_s("%d", &a[i]);
//	}
//	for (int i = 0; i < n-1; i++) {
//		if ((a[i + 1] - a[i])!= k) {
//			count++;
//			if (a[i + 1] > a[i]) {
//				b[i] = a[i + 1] - a[i] - k;
//					a[i + 1] = a[i] + k;
//			}
//			else if(a[i + 1]<=a[i]) {
//				b[i] = a[i + 1] - a[i] - k;
//				a[i + 1] = a[i] + k;
//			}
//		}
//	}
//	printf("%d\n", count);
//	for (int i = 0; i < n - 1; i++) {
//		if (b[i] < 0) {
//			printf("+ %d %d\n", i + 2,-b[i]);
//		}
//		else if (b[i] > 0) {
//			printf("- %d %d\n", i + 2, b[i]);
//		}
//	}
//	return 0;
//}
#include<stdio.h>
int main()
{
	int n, k,s, flat,min=1001;
	int a[1001];
	scanf_s("%d %d", &n, &k);
	for(int j=0;j<n;j++)
		scanf_s("%d", &a[j]);
	for (int i = 0; i < n; i++) {
		int count = 0; s = 0;
		for (int j = i - 1; j >= 0; j--) {
			if (a[j] == a[i] - (i - j) * k) {
				continue;
			}
			else {
				count++;
			}
			if (a[i] - (i - j) * k <= 0)
				s = 1;
		}
			for (int j = i + 1; j < n; j++) {
				if (a[j] == a[i] + (j - i) * k) {
					continue;
				}
				else {
					count++;
				}
				if (a[i] + (j-i) * k <= 0)
					s = 1;
			}
			if (s==1) {
				continue;
			}
			if(count<min){
				flat = i;
				min = count;
		}
	}
	printf("%d\n", min);
	for (int i = 0; i < n; i++) {
		if (i>flat) {
			if (a[i] <a[flat]+(i-flat)*k) {
				printf("+ %d %d\n", i + 1, -(a[i] - a[flat] -(i-flat)*k));
			}
			if (a[i] > a[flat] + (i - flat) * k) {
				printf("- %d %d\n", i + 1, (a[i] - a[flat] - (i - flat) * k));
			}
		}
		if (i <flat) {
			if (a[i] < a[flat] - (flat-i) * k) {
				printf("+ %d %d\n", i + 1, -(a[i] - a[flat] + (i - flat) * k));
			}
			if (a[i] > a[flat] - (flat-i) * k) {
				printf("- %d %d\n", i + 1, (a[i] - a[flat] + (i - flat) * k));
			}
		}
	}
	return 0;
}