#define _CRT_SECURE_NO_WARNINGS  1
#pragma warning(disable:6031)
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
int main()
{
    int k;
    while (scanf("%d", &k)!=EOF) {
        int n = k;
        int num;
        int count = 0;
        for (int i = 2; i*i <= k; i++) {
            if (n % i == 0) {
                num = 0;
                while (n % i == 0) {
                    num++;
                    n /= i;
                }
                if (count != 0) {
                    printf("*");
                }
                if (num == 1) {
                    printf("%d", i);
                }
                else if (num > 1)
                    printf("%d^%d", i, num);
                count++;
            }
        }
        if (count == 0) {
            printf("%d\n", k);
        }
        else {
            if (n == 1)printf("\n");
            else printf("*%d\n", n);
        }
    }
    return 0;
}
//int isprime(int s) {
//    int i;
//    for (i = 2; i < sqrt(s); i++) {
//        if (s % i == 0) {
//            return 0;
//        }
//    }
//    return 1;
//}
//int main()
//{
//    while (1) {
//        int k;
//        int b[1000]={0};
//        scanf("%d", &k);
//        if (isprime(k)) {
//            printf("%d", k);
//        }
//        else
//        {
//            int n = k;
//            for (int i = 2; i <= k / 2; i++) {
//                while (n % i == 0) {
//                    b[i]++;
//                    n /= i;
//                }
//            }
//        }
//        int count = 0;
//        for (int i = 2; i <= k / 2; i++) {
//            if (b[i] != 0) {
//                if (b[i] == 1) {
//                    if (count == 0) {
//                        printf("%d", i);
//                    }
//                    else {
//                        printf("*%d", i);
//                    }
//                }
//                else {
//                    if (count == 0) {
//                        printf("%d^%d", i,b[i]);
//                    }
//                    else {
//                        printf("*%d^%d", i, b[i]);
//                    }
//                }
//                count++;
//            }
//        }
//        printf("\n");
//    }
//    return 0;
//}
//¿Õ¼äÌ«´ó
    /*unsigned int* m=(unsigned int*)malloc(sizeof(unsigned int)*100000000);
    if (!m) {
        return 0;
    }
    for (int i = 2; i <= 100000000; i++) {
        m[i] = 1;
    }
    for (int i = 2; i <=100000000; i++) {
        if (m[i]) {
            for (int j = 2; i * j < 100000000; j++) {
                m[i * j] = 0;
            }
        }
    }*/