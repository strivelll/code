#define _CRT_SECURE_NO_WARNINGS  1
#pragma warning(disable:6031)
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int main() {

	return 0;
}
//int main() {
//	int t,n,w;
//	scanf("%d", &t);
//	while (t--) {
//		vector<int> a;
//		scanf("%d %d", &n, &w);
//		for (int i = 0; i < n; i++) {
//			int b;
//			scanf("%d", &b);
//			a.push_back(b);
//		}
//		sort(a.begin(), a.end());
//		int sum = 0;
//		for (int i = a.size() - 1; i >= 0; i--) {
//			sum += a[i];
//			if (sum >= w) {
//				printf("%d\n", a.size() - i);
//				break;
//			}
//			
//		}
//	}
//	return 0;
//}
//int main() {
//	long long t,a,b,n;
//	scanf("%lld", &t);
//	while (t--) {
//		long long time=0;
//		scanf("%lld %lld %lld", &a, &b, &n);
//		if (a <= b) {
//			printf("%lld\n", b * n);
//		}
//		else {
//			if (n % 2 == 0) {
//				time += (n - 2) / 2 * (a + b) + 2 * b;
//			}
//			else {
//				time += (n - 1) / 2 * (a + b) + b;
//			}
//			printf("%lld\n", time);
//		}
//	}
//
//	return 0;
//}
//int main()
//{
//	int n, d,t;
//	cin >> t;
//	while (t--) {
//		cin >> n >> d;
//		string a;
//		cin >> a;
//		int f = 1;
//		if (a == "0"&&d==0) {
//			cout << '0' << endl;
//			continue;
//		}
//		for (int i = 0; i < n; i++) {
//			if (f&&a[i]-'0' <= d &&((i+1<n&&a[i+1]-'0'<=d)||i+1>=n)&&d!=0 ) {
//				f = 0;
//				cout << d;
//			}
//			cout << a[i];
//		}
//		if (f == 1) {
//			cout << d;
//		}
//		cout << endl;
//	}
//	return 0;
//}