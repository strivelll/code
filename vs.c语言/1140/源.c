#define _CRT_SECURE_NO_WARNINGS  1
#pragma warning(disable:6031)
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
int main()
{
	int k;
	char str[32];
	scanf("%d", &k);
	while (k--) {
		scanf("%s", &str);
		int len = strlen(str);
		int sum=0;
		for (int i = 0; i < len; i++) {
			if (str[i] == '-') {
				str[i] = '0'-1;
			}
		}
		double j = 0;
		for (int i = len-1; i >= 0; i--) {
			sum += (str[i] - '0') * (int)pow(3.0, j++);
		}
		printf("%d\n", sum);
	}
	return 0;
}