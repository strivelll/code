#define _CRT_SECURE_NO_WARNINGS  1
#pragma warning(disable:6031)
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int diedai(int n) {
	char arr[502] = { 0 };
	sprintf(arr, "%d", n);
	int ans = 0;
	int len = strlen(arr);
	for (int i = 0; i < len; i++) {
		ans += arr[i]-'0';
	}
	if (ans / 10==0) {
		return ans;
	}
	else
		return diedai(ans);
}
int main()
{
    int n;
    while (scanf("%d", &n), n != 0) {
        if (n / 10 == 0) {
            printf("%d\n", n);
            continue;
        }
        printf("%d\n", diedai(n));

    }
    return 0;
}