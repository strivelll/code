#define _CRT_SECURE_NO_WARNINGS  1
#pragma warning(disable:6031)
//#include<iostream>
//#include<math.h>
//using namespace std;
//int main() {
//    long long n, a, b, m;
//    cin >> n >> b;
//    long long sumb = 0;
//    long long t;
//    for (int i = 0; i < n; i++) {
//        cin >> t;
//        sumb += t * pow(b, n - i - 1);
//    }
//    cin >> m >> a;
//    long long suma = 0;
//    for (int i = 0; i < m; i++) {
//        cin >> t;
//        sumb += t * pow(a, m - i - 1);
//    }
//    if (sumb == suma) {
//        cout << '=';
//    }
//    else if (sumb > suma) {
//        cout << '>';
//    }
//    else
//        cout << '<';
//    return 0;
//}
#include<iostream>
#include<math.h>
class node {
public:
	node* next;
	node* pre;
	int color;
};
using namespace std;
int main() {
	int n, m;
	cin >> n >> m;
	int x, y;
	for (int i = 0; i < n ; i++) {
		cin >> x >> y;
	}
	return 0;
}