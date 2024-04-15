#define _CRT_SECURE_NO_WARNINGS  1
#include <stdio.h>
int main() {
    int a, b;
    while (~scanf("%d %d", &a, &b)) {
        int flag = 1;//flag=1表示他还没有过水仙花数
        for (int i = a; i <= b; i++) {
            int x = i;
            int sum = 0;

            while (x) {
                int r = x % 10;
                sum += r * r * r;
                x = x / 10;//x/=10;
            }
            if (sum == i) {
                flag = 0;
`                printf("%d ", i);
            }
        }
        if (flag) {
            printf("no");
        }
        printf("\n");
    }
    return 0;
}