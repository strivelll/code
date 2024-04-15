#define _CRT_SECURE_NO_WARNINGS  1
#pragma warning(disable:6031)
#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;
int gcd(int x, int y) {
	int t = x % y;
	while (t) {
		x = y;
		y = t;
		t = x % y;
	}
	return y;
}
int main() {
	int l1, r1, l2, r2,count=0;
	scanf("%d %d %d %d", &l1, &r1, &l2, &r2);
	for (int i = l1; i <= r1; i++) {
		for (int j = l2; j <= r2; j++) {
			if ((i ^ j )<gcd(i,j)) {
				count++;
			}
		}
	}
	printf("%d\n",count);
	return 0;
}

//1.³ýÆæÖÂÊ¤
//int main()
//{
//	int n, m;
//	vector<int> a, b;
//	scanf("%d", &n);
//	for (int i = 0; i < n; i++) {
//		int c;
//		scanf("%d", &c);
//		if (c % 2 == 0) {
//			a.push_back(c);
//		}
//	}
//	scanf("%d", &m);
//	for (int i = 0; i < m; i++) {
//		int c;
//		scanf("%d", &c);
//		if (c % 2 != 0) {
//			b.push_back(c);
//		}
//	}
//	if (a.size() <= b.size()) {
//		printf("0\n");
//	}
//	else {
//		sort(a.begin(), a.end());
//		long long ans = 0;
//		for (int i = 0; i < a.size() - b.size(); i++) {
//			ans += a[i];
//		}
//		printf("%lld\n", ans);
//	}
//	return 0;
//}