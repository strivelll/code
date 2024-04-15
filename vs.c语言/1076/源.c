#define _CRT_SECURE_NO_WARNINGS  1
#pragma warning(disable:6031)
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
int main()
{
	unsigned int n;//ÕýÕûÊý
	while (scanf("%d", &n)&&n!=0) {
		if (n == 1) {
			printf("No\n");
			continue;
		}
		int i;
		for (i = 2; i < sqrt(n); i++) {
			if (n % i == 0) {
				break;
			}
		}
		if (i >sqrt(n)) {
			printf("Yes\n");
		}
		else {
			printf("No\n");
		}
		
	}
	return 0;
}