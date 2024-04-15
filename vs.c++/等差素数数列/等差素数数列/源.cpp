//#define _CRT_SECURE_NO_WARNINGS  1
//#pragma warning(disable:6031)
//#include <iostream>
//using namespace std;
//int a[100000] = { 0 };
//
//int main()
//{
//    a[0] = 1;
//    a[1] = 1;
//    for (int i = 2; i < 100000; i++) {
//        if(a[i]==0)
//        for (int j = 2; j * i < 100000; j++) {
//                a[j * i] = 1;
//        }
//    }
//    int Min = 9999;
//    for (int i = 2; i < 100000; i++) {
//        if(a[i]==0)
//        for (int k = 1; k < 1000; k++) {
//            int j;
//            for (j = 1; j <= 10; j++) {
//                if (a[i + j * k] != 0) {
//                    break;
//                }
//            }
//            if (j >= 10) {
//                Min = k;
//                cout << Min;
//                return 0;
//            }
//        }
//    }
//    
//    return 0;
//}
#include <iostream>
using namespace std;
int a[10000][10000] = { 0 };
int b[100000000] = { 0 };
int main()
{
    long long n;
    cin >> n;
    for (int i = 0; i < 10000; i++) {
        a[i][0] = 1;
        a[i][i] = 1;
    }
    for (int i = 2; i < 10000; i++) {
        for (int j = 1; j < i; j++) {
            a[i][j] = a[i - 1][j] + a[i - 1][j - 1];
        }
    }
    long long k = 0;
    for (int i = 0; i < 10000; i++) {
        for (int j = 0; j <= i; j++) {
            b[k++] = a[i][j];
        }
    }
    for (int i = 0; i < 100000000; i++) {
        if (n == b[i]) {
            cout << i + 1;
            return 0;
        }
    }
    return 0;
}