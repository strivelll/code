#include<stdio.h>
//方法一：
//void yanghui(int n)
//{
//	int data[30][30] = {1};
//	for (int i = 0; i <=n; i++) {
//		data[i][0] = 1;
//		for (int j = 1; j < i; j++) {
//			data[i][j] = data[i - 1][j] + data[i - 1][j - 1];
//		}
//	}
//	for (int i = 0; i <= n; i++)
//	{
//		for (int j = 0; j < i; j++) {
//			printf("%.2d ", data[i][j]);
//		}
//		printf("\n");
//	}
//}
//方法二：
void yanghui2(int n) {
	int data[30] = { 1 };
	printf("1\n");
	for (int i = 1; i <= n; i++) {
		for (int j = i; j > 0; j--) {
			data[j] += data[j - 1];
		}
		for(int j=0;j<=i;j++)
		printf("%d ", data[j]);
		printf("\n");
	}
}
int main()
{
	int n;
	scanf_s("%d", &n);
	//yanghui1(n);
	yanghui2(n);
	return 0;
}