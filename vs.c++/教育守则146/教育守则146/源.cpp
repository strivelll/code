#define _CRT_SECURE_NO_WARNINGS  1
#pragma warning(disable:6031)
#include<iostream>
#include<math.h>
#include<algorithm>
using namespace std;
int a[4000010] = { 0 };
void ma() {
    for (int i = 2; i <= 4000000; i++) {
        if (a[i] == 0) {
            for (int j = 2; j * i <= 4000000; j++) {
                a[i * j] = 1;
            }
        }
    }
    a[1] = 1;
    a[0] = 1;
}
int main() {
    ma();
    cout << a[985];
    return 0;
}
//int a, b;
//int dfs(int x, int y, int m,int count) {
//	if (x == a && b == y) {
//		return count;
//	}
//	if (x > a || y > b||x+m>a&&y+m>b) {
//		return INT_MAX;
//	}
//	return min(min(dfs(x + m, y, m, count + 1),
//		dfs(x, y + m, m, count + 1)),
//		dfs(x, y, m + 1, count + 1));
//}
//int main() {
//	int t,m=1;
//	int ans = 0;
//	scanf("%d", &t);
//	while (t--) {
//		scanf("%d %d", &a, &b);
//		ans=dfs(0, 0, m,1);
//		printf("%d\n", ans);
//	}
//	return 0;
//}
//Ó²±Ò
//int main()
//{
//	int t;
//	long long k, n;
//	scanf("%d", &t);
//	while (t--) {
//		scanf("%lld %lld", &n, &k);
//		if (n % k == 0 || n % 2 == 0||n%k%2==0) {
//			printf("YES\n");
//			continue;
//		}
//		long long x, y,t;
//		if (k > 2) {
//			y = n / k;
//			t = n % k;
//			int f = 0;
//			while (y >= 0&&t<2*k/__gcd(2,k)) {
//				if (t % 2 == 0) {
//					printf("YES\n");
//					f = 1;
//					break;
//				}
//				else {
//					y--;
//					t += k;
//				}
//			}
//			if (!f) {
//				printf("NO\n");
//			}
//		}
//	}
//	return 0;
//}