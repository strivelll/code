#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
	int k;
	scanf("%d" ,& k);
	while (k--)
	{
		int a, b, sum, count;
		int ans = 1;
		scanf("%d %d", &a, &b);
		sum = a + b;
		for (int i = 2; i * i <= sum; i++) {
			if (sum % i == 0) {
				count = 0;
				while (sum % i == 0) {
					count++;
					sum /= i;
				}
				ans *= (count + 1);
			}
		}
		if (sum!= 1)printf("%d\n", 2 * ans);
		else printf("%d\n", ans);
	}
	return 0;
}
//³¬Ê±ÁË
//int main()
//{
//	int k;
//	scanf("%d", &k);
//	while (k--) {
//		int a, b,sum;
//		int count = 2;
//		scanf("%d %d", &a, &b);
//		sum = a + b;
//		for (int i = 2; i * i <= sum; i++) {
//			if (sum % i == 0) {
//				count+=2;
//			}
//		}
//		printf("%d\n", count);
//	}
//	return 0;
//}