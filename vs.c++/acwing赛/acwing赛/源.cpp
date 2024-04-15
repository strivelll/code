#define _CRT_SECURE_NO_WARNINGS  1
#pragma warning(disable:6031)
//#include<iostream>
//using namespace std;
//int main()
//{
//	int x, n=0,count=0;
//	/*cin >> x;
//	while (x) {
//		int t = x % 2+0.5;
//		x /= 2;
//		if (t == 1) {
//			count++;
//		}
//	}*/
//	cout << count;
//	return 0;
//}
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long LL;

int n, m;

bool check()
{
    while (m)
    {
        int t = m % n;
        if (t == 0 || t == 1)
            m /= n;
        else if (t == n - 1)
            m /= n, m++;
        else
            return false;
    }
    return true;
}

int main()
{
    cin >> n >> m;
    cout << (check() ? "YES" : "NO") << endl;
    return 0;
}
