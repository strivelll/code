#include<stdio.h>
int main()
{
	int a, b, c,k;
	scanf("%d", &k);
	while (k--) {
		scanf("%d %d %d", &a, &b, &c);
		if (b + c == a) {
			printf("YES\n");
		}
		if (a + c == b) {
			printf("YES\n");
		}
		if (a + b == c) {
			printf("YES\n");
		}
		else {
			printf("NO\n");
		}
	}
	return 0;
}