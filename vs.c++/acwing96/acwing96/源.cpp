#define _CRT_SECURE_NO_WARNINGS  1
#pragma warning(disable:6031)
//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
////int main() {
////    long long n, m = 2520;
////    cin >> n;
////    cout << n/m << endl;;
////    return 0;
////}
//int main() {
//	int n, m,a,b;
//	vector<int> v, w;
//	cin >> n >> m >> a >> b;
//	v.push_back(a);
//	w.push_back(b);
//	for (int i = 0; i < m; i++) {
//
//	}
//
//	return 0;
//}
#include <iostream>
using namespace std;
int main()
{
    int count = 0;
    for (int i = 1900; i <= 9999; i++) {
        for (int j = 1; j <= 12; j++) {
            if (i / 1000 == 2 || i / 100 % 10 == 2 || i / 10 % 100 == 2 || i % 10 == 2 && (i % 400 == 0 || (i % 4 == 0 && i % 100 != 0))) {

            }
            if (j == 2 && (i % 400 == 0 || (i % 4 == 0 && i % 100 != 0))) {
                count += 29;
            }
            else if (j == 2) {
                count += 28;
            }
            else if (j == 12) {
                count += 31;
            }
            else {
                    if (i / 1000 == 2 || i / 100 % 10 == 2 || i / 10 % 100 == 2 || i % 10 == 2 ) {
                        if (j == 1 || j == 3 || j == 5 || j == 7 || j == 8 || j == 10) {
                            count += 31;
                        }
                        else
                            count += 30;
                    }
                    else {
                        count += 12;
                    }
            }
        }
    }
    cout << count;
    return 0;
}