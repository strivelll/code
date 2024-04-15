#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
int isprime(int s) {
    int i;
    for (i = 2; i < sqrt(s); i++) {
        if (s % i == 0) {
            return 0;
        }
    }
    return 1;
}
int main()
{
    while (1) {
        int k;
        int b[100]={0};
        scanf("%d", &k);
        if (isprime(k)) {
            printf("%d", k);
        }
        else
        {
            int n = k;
            for (int i = 2; i <= k / 2; i++) {
                while (n % i == 0) {
                    b[i]++;
                    n /= i;
                }
            }
        }
        int count = 0;
        for (int i = 2; i <= k / 2; i++) {
            if (b[i] != 0) {
                if (b[i] == 1) {
                    if (count == 0) {
                        printf("%d", i);
                    }
                    else {
                        printf("*%d", i);
                    }
                }
                else {
                    if (count == 0) {
                        printf("%d^%d", i,b[i]);
                    }
                    else {
                        printf("*%d^%d", i, b[i]);
                    }
                }
                count++;
            }
        }
        printf("\n");
    }
    return 0;
}
